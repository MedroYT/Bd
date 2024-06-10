/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *emailregistr;
    QLineEdit *passwordregistr;
    QLineEdit *nameregistr;
    QPushButton *backregistr;
    QPushButton *registration1;
    QComboBox *roleComboBox;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName("registration");
        registration->resize(1345, 758);
        widget = new QWidget(registration);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(542, 330, 172, 150));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        emailregistr = new QLineEdit(widget);
        emailregistr->setObjectName("emailregistr");

        gridLayout->addWidget(emailregistr, 2, 0, 1, 2);

        passwordregistr = new QLineEdit(widget);
        passwordregistr->setObjectName("passwordregistr");

        gridLayout->addWidget(passwordregistr, 1, 0, 1, 2);

        nameregistr = new QLineEdit(widget);
        nameregistr->setObjectName("nameregistr");

        gridLayout->addWidget(nameregistr, 0, 0, 1, 2);

        backregistr = new QPushButton(widget);
        backregistr->setObjectName("backregistr");

        gridLayout->addWidget(backregistr, 3, 1, 1, 1);

        registration1 = new QPushButton(widget);
        registration1->setObjectName("registration1");

        gridLayout->addWidget(registration1, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        roleComboBox = new QComboBox(widget);
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->addItem(QString());
        roleComboBox->setObjectName("roleComboBox");

        verticalLayout->addWidget(roleComboBox);

        widget1 = new QWidget(registration);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(390, 340, 141, 71));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);


        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QWidget *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "Registration Form", nullptr));
        backregistr->setText(QCoreApplication::translate("registration", "Back", nullptr));
        registration1->setText(QCoreApplication::translate("registration", "Register", nullptr));
        roleComboBox->setItemText(0, QCoreApplication::translate("registration", "client", nullptr));
        roleComboBox->setItemText(1, QCoreApplication::translate("registration", "support", nullptr));
        roleComboBox->setItemText(2, QCoreApplication::translate("registration", "admin", nullptr));

        label->setText(QCoreApplication::translate("registration", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("registration", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("registration", "\320\232\320\276\320\275\321\202\320\260\320\272\321\202\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
