#ifndef LOGIN_H
#define LOGIN_H

#include "qsqldatabase.h"
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:

    void on_backlogin_clicked();

    void on_loginbut_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db;
    int user_id; // Объявление переменной user_id
};

#endif // LOGIN_H
