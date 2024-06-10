#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "bdeshka.h"

login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_backlogin_clicked()
{
    MainWindow *mainWindow = new MainWindow(); // Создаем экземпляр главного окна
    mainWindow->show(); // Отображаем главное окно
    this->close(); // Закрываем окно логина
}

void login::on_loginbut_clicked()
{
    // Настраиваем подключение к базе данных
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
    }

    QString username = ui->namelogin->text(); // Получаем логин из поля ввода
    QString password = ui->passwordlogin->text(); // Получаем пароль из поля ввода

    QSqlQuery query;
    query.prepare("SELECT user_id FROM users WHERE name = :name AND password = :password");
    query.bindValue(":name", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QString error = query.lastError().text();
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос к базе данных: " + error);
        return;
    }

    if (query.next()) {
        // Получаем user_id из результата запроса
        int user_id = query.value(0).toInt();

        // Успешный вход
        QMessageBox::information(this, "Успех", "Вы успешно вошли в систему!");

        // Создаем и отображаем окно bdeshka с переданным user_id
        bdeshka *bdeshkaWindow = new bdeshka(user_id, username, password, this);
        bdeshkaWindow->show();
        this->hide(); // Скрываем окно login
    } else {
        // Неправильный логин или пароль
        QMessageBox::warning(this, "Ошибка", "Неправильный логин или пароль");
    }
}
