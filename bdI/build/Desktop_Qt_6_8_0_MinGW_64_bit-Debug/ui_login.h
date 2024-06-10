/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *backlogin;
    QPushButton *loginbut;
    QLineEdit *namelogin;
    QLineEdit *passwordlogin;
    QLabel *labellogin;
    QLabel *label;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1338, 744);
        layoutWidget = new QWidget(login);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(570, 400, 168, 108));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        backlogin = new QPushButton(layoutWidget);
        backlogin->setObjectName("backlogin");

        gridLayout->addWidget(backlogin, 2, 1, 1, 1);

        loginbut = new QPushButton(layoutWidget);
        loginbut->setObjectName("loginbut");

        gridLayout->addWidget(loginbut, 2, 0, 1, 1);

        namelogin = new QLineEdit(layoutWidget);
        namelogin->setObjectName("namelogin");

        gridLayout->addWidget(namelogin, 0, 0, 1, 2);

        passwordlogin = new QLineEdit(layoutWidget);
        passwordlogin->setObjectName("passwordlogin");

        gridLayout->addWidget(passwordlogin, 1, 0, 1, 2);

        labellogin = new QLabel(login);
        labellogin->setObjectName("labellogin");
        labellogin->setGeometry(QRect(520, 410, 31, 16));
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(510, 440, 49, 21));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Form", nullptr));
        backlogin->setText(QCoreApplication::translate("login", "Back", nullptr));
        loginbut->setText(QCoreApplication::translate("login", "Login", nullptr));
        labellogin->setText(QCoreApplication::translate("login", "Login", nullptr));
        label->setText(QCoreApplication::translate("login", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
