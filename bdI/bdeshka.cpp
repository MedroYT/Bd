#include "bdeshka.h"
#include "ui_bdeshka.h"
#include <QInputDialog>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDateTime>
#include "mainwindow.h"

bdeshka::bdeshka(int user_id, const QString &username, const QString &password, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bdeshka)
    , currentUserId(user_id)
    , username(username)
    , password(password)
{
    ui->setupUi(this);
    //checkAndFixUserIdSequence(); // Проверка и исправление последовательности при запуске
}

bdeshka::~bdeshka()
{
    delete ui;
}

void bdeshka::on_view_clicked()
{
    QSqlQuery query(QSqlDatabase::database("postgres"));

    if (!query.exec("SELECT * FROM tickets"))
    {
        QMessageBox::warning(this, "Ошибка", query.lastError().databaseText());
        return;
    }

    // Проверяем, является ли текущий пользователь администратором
    bool isAdminUser = isAdmin(); // Предполагается, что функция isAdmin() определена в bdeshka.cpp

    // Устанавливаем заголовки таблицы
    int columnCount = isAdminUser ? 8 : 4; // Определяем количество столбцов в зависимости от роли пользователя
    ui->tableWidget->setColumnCount(columnCount);
    QStringList headers;
    headers << "ID" << "Пользователь ID" << "Заголовок" << "Описание";
    if (isAdminUser) {
        headers << "Статус" << "Приоритет" << "Дата создания" << "Дата обновления";
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Заполняем таблицу данными
    ui->tableWidget->setRowCount(0);  // Очистить таблицу перед заполнением
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("id").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("user_id").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("title").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("description").toString()));
        if (isAdminUser) {
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("status").toString()));
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("priority").toString()));
            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("created_at").toDateTime().toString("yyyy-MM-dd HH:mm:ss")));
            ui->tableWidget->setItem(row, 7, new QTableWidgetItem(query.value("updated_at").toDateTime().toString("yyyy-MM-dd HH:mm:ss")));
        }
        row++;
    }
}
void bdeshka::on_remove_clicked()
{   bool isAdminUser = isAdmin(); // Предполагается, что функция isAdmin() определена в bdeshka.cpp

    // Если текущий пользователь не администратор и пытается удалить билет, выходим из функции
    if (!isAdminUser) {
        QMessageBox::warning(this, "Ошибка", "У вас нет прав на удаление билета.");
        return;
    }
    QList<QTableWidgetItem *> selectedItems = ui->tableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите билет для удаления");
        return;
    }

    int row = selectedItems.first()->row();
    int ticket_id = ui->tableWidget->item(row, 0)->text().toInt();

    // Получаем номер билета для подтверждения
    QString ticket_number = ui->tableWidget->item(row, 0)->text();

    // Показываем диалоговое окно для подтверждения удаления
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение удаления",
                                  QString("Вы действительно хотите удалить билет с номером %1?").arg(ticket_number),
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Удаляем комментарии, связанные с этим билетом
        QSqlQuery deleteCommentsQuery(QSqlDatabase::database("postgres"));
        deleteCommentsQuery.prepare("DELETE FROM comments WHERE ticket_id = :ticket_id");
        deleteCommentsQuery.bindValue(":ticket_id", ticket_id);
        if (!deleteCommentsQuery.exec()) {
            QMessageBox::warning(this, "Ошибка", deleteCommentsQuery.lastError().databaseText());
            return;
        }

        // Удаляем сам билет
        QSqlQuery deleteTicketQuery(QSqlDatabase::database("postgres"));
        deleteTicketQuery.prepare("DELETE FROM tickets WHERE id = :ticket_id");
        deleteTicketQuery.bindValue(":ticket_id", ticket_id);

        if (!deleteTicketQuery.exec()) {
            QMessageBox::warning(this, "Ошибка", deleteTicketQuery.lastError().databaseText());
        } else {
            QMessageBox::information(this, "Успешно", "Билет успешно удален.");
            ui->tableWidget->removeRow(row); // Удалить строку из таблицы
        }
    } else {
        QMessageBox::information(this, "Отмена", "Удаление билета отменено.");
    }
}


void bdeshka::on_add_clicked()
{
    // Получаем информацию о билете с помощью диалоговых окон
    bool ok;
    QString title = QInputDialog::getText(this, "Добавление билета", "Введите заголовок билета:", QLineEdit::Normal, "", &ok);
    if (!ok) return; // Если пользователь нажал "Отмена", выходим из функции

    QString description = QInputDialog::getText(this, "Добавление билета", "Введите описание билета:", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    QString priority = QInputDialog::getText(this, "Добавление билета", "Введите приоритет билета (low/medium/high):", QLineEdit::Normal, "", &ok);
    if (!ok) return;

    // Получаем user_id текущего пользователя из переменной currentUserId
    int user_id = currentUserId;

    // Создаем запрос для добавления нового билета в базу данных
    QSqlQuery query(QSqlDatabase::database("postgres"));
    query.prepare("INSERT INTO tickets (user_id, title, description, priority, created_at, updated_at) "
                  "VALUES (:user_id, :title, :description, :priority, CURRENT_TIMESTAMP, CURRENT_TIMESTAMP)");
    query.bindValue(":user_id", user_id);
    query.bindValue(":title", title);
    query.bindValue(":description", description);
    query.bindValue(":priority", priority);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Билет успешно добавлен.");
        // Обновляем отображение таблицы с билетами
        on_view_clicked();
    }
}



void bdeshka::on_edit_clicked()
{
    QList<QTableWidgetItem *> selectedItems = ui->tableWidget->selectedItems();
    if (selectedItems.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите билет для редактирования");
        return;
    }

    int row = selectedItems.first()->row();
    int ticket_id = ui->tableWidget->item(row, 0)->text().toInt();
    int user_id = ui->tableWidget->item(row, 1)->text().toInt(); // Получаем ID пользователя, связанного с билетом

    // Проверяем, является ли текущий пользователь владельцем билета, или администратором
    if (currentUserId != user_id && !isAdmin()) {
        QMessageBox::warning(this, "Ошибка", "Вы не можете редактировать билет, который не принадлежит вам.");
        return;
    }

    // Получаем текущие значения билета
    QString currentTitle = ui->tableWidget->item(row, 2)->text();
    QString currentDescription = ui->tableWidget->item(row, 3)->text();

    // Отображаем диалоговые окна для ввода новых значений
    bool ok;
    QString newTitle = QInputDialog::getText(this, "Редактирование билета", "Введите новый заголовок билета:", QLineEdit::Normal, currentTitle, &ok);
    if (!ok) return;

    QString newDescription = QInputDialog::getText(this, "Редактирование билета", "Введите новое описание билета:", QLineEdit::Normal, currentDescription, &ok);
    if (!ok) return;

    // Создаем запрос для обновления билета в базе данных
    QSqlQuery query(QSqlDatabase::database("postgres"));
    query.prepare("UPDATE tickets SET title = :title, description = :description, updated_at = CURRENT_TIMESTAMP WHERE id = :ticket_id");
    query.bindValue(":title", newTitle);
    query.bindValue(":description", newDescription);
    query.bindValue(":ticket_id", ticket_id);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", query.lastError().text());
    } else {
        QMessageBox::information(this, "Успех", "Билет успешно обновлен.");
        // Обновляем отображение таблицы с билетами
        on_view_clicked();
    }
}

bool bdeshka::isAdmin()
{
    QSqlQuery query(QSqlDatabase::database("postgres"));
    query.prepare("SELECT COUNT(*) FROM users WHERE name = :name AND password = :password AND role = 'admin'");
    query.bindValue(":name", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось проверить роль пользователя: " + query.lastError().text());
        return false;
    }

    query.next(); // Переходим к первой записи

    int adminCount = query.value(0).toInt();
    return (adminCount > 0); // Если есть хотя бы один админ с такими данными, возвращаем true
}

void bdeshka::on_domoybutton_clicked()
{
    // Создаем экземпляр главного окна
    MainWindow *mainWindow = new MainWindow();

    // Отображаем главное окно
    mainWindow->show();

    // Закрываем окно регистрации
    this->close();
}

