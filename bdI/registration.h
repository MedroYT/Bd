#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class registration;
}

class registration : public QWidget
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_registration1_clicked();
    void on_backregistr_clicked();

private:
    Ui::registration *ui;
    QString getRoleKey(const QString& role);

    // Переменные для хранения ключей ролей
    QString adminKey = "admin";
    QString clientKey = "client";
    QString supportKey = "support";
};

#endif // REGISTRATION_H
