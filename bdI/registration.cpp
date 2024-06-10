#include "registration.h"
#include "ui_registration.h"
#include <QSqlError>
#include "mainwindow.h"

registration::registration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
}

registration::~registration()
{
    delete ui;
}

void registration::on_registration1_clicked()
{
    // Настраиваем подключение к базе данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    qDebug() << db.drivers();
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setPort(5430); // Порт 5430
    db.setDatabaseName("postgres"); // База данных postgres
    db.setUserName("postgres"); // Пользователь postgres
    db.setPassword("4206");

    if (!db.open()) {
        QString error = db.lastError().text();
        QMessageBox::critical(this, "Ошибка подключения", "Не удалось подключиться к базе данных: " + error);
        return;
    } else {
        qDebug() << "Подключение к базе данных успешно!";
    }

    QString username = ui->nameregistr->text();
    QString password = ui->passwordregistr->text();
    QString email = ui->emailregistr->text();
    QString role = ui->roleComboBox->currentText();

    if (username.isEmpty() || password.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все поля");
        return;
    }

    // Проверка на минимальную длину логина и пароля
    if (username.length() < 3) {
        QMessageBox::warning(this, "Ошибка", "Логин должен быть не менее 3 символов");
        return;
    }

    if (password.length() < 6) {
        QMessageBox::warning(this, "Ошибка", "Пароль должен быть не менее 6 символов");
        return;
    }

    // Проверка безопасности пароля: должен содержать буквы и цифры
    QRegularExpression passwordRe("^(?=.*[a-zA-Z])(?=.*\\d).+$");
    if (!passwordRe.match(password).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Пароль должен содержать буквы и цифры");
        return;
    }

    // Проверка корректности электронной почты
    QRegularExpression emailRe(R"((^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$))");
    if (!emailRe.match(email).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Введите корректный адрес электронной почты");
        return;
    }
    QString roleKey = getRoleKey(role);
    if (roleKey.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Неправильно выбрана роль");
        return;
    }
    if (db.isOpen()) {
        QSqlQuery query;
        query.prepare("INSERT INTO users (user_id, name, password, email, role) VALUES (nextval('users_user_id_seq'), :name, :password, :email, :role)");
        query.bindValue(":name", username);
        query.bindValue(":password", password);
        query.bindValue(":email", email);
        query.bindValue(":role", roleKey);

        if (query.exec()) {
            QMessageBox::information(this, "Успех", "Вы успешно зарегистрировались!");
        } else {
            QString error = query.lastError().text();
            QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос к базе данных: " + error);
        }
    } else {
        QMessageBox::critical(this, "Ошибка", "База данных не открыта!");
    }

    db.close(); // Закрываем подключение к базе данных
}

void registration::on_backregistr_clicked()
{
    MainWindow *mainWindow = new MainWindow(); // Создаем экземпляр главного окна
    mainWindow->show(); // Отображаем главное окно
    this->close(); // Закрываем окно регистрации
}

QString registration::getRoleKey(const QString& role)
{
    if (role == "admin") {
        return adminKey;
    } else if (role == "client") {
        return clientKey;
    } else if (role == "support") {
        return supportKey;
    } else {
        return ""; // Неверная роль
    }
}
