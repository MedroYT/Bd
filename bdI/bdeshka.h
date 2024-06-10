#ifndef BDESHKA_H
#define BDESHKA_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QInputDialog>
#include <QTableWidgetItem>
#include <QDateTime>

namespace Ui {
class bdeshka;
}

class bdeshka : public QDialog
{
    Q_OBJECT

public:
    explicit bdeshka(int user_id, const QString &username, const QString &password, QWidget *parent = nullptr);
    ~bdeshka();

private slots:
    void on_view_clicked();
    void on_remove_clicked();
    void on_add_clicked();
    void on_edit_clicked();;
    void on_domoybutton_clicked();
    bool isAdmin();

private:
    Ui::bdeshka *ui;
    int currentUserId;
    QString username;
    QString password;    // Переменная для хранения текущего userId
};

#endif // BDESHKA_H
