#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "registration.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    login *loginWindow = new login; // Создаем экземпляр окна логина
    loginWindow->show(); // Отображаем окно логина
    this->hide(); // Скрываем главное окно
}


void MainWindow::on_registr_clicked()
{
    registration *regWindow = new registration; // Создаем экземпляр окна регистрации
    regWindow->show(); // Отображаем окно регистрации
    this->hide(); // Скрываем главное окно
}

