#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QInputDialog>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_login_clicked();

    void on_registr_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
