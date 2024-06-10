/********************************************************************************
** Form generated from reading UI file 'bdeshka.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BDESHKA_H
#define UI_BDESHKA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bdeshka
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *view;
    QPushButton *remove;
    QPushButton *add;
    QPushButton *edit;
    QTableWidget *tableWidget;
    QPushButton *domoybutton;

    void setupUi(QWidget *bdeshka)
    {
        if (bdeshka->objectName().isEmpty())
            bdeshka->setObjectName("bdeshka");
        bdeshka->resize(1346, 763);
        layoutWidget = new QWidget(bdeshka);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 110, 1271, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        view = new QPushButton(layoutWidget);
        view->setObjectName("view");

        horizontalLayout->addWidget(view);

        remove = new QPushButton(layoutWidget);
        remove->setObjectName("remove");

        horizontalLayout->addWidget(remove);

        add = new QPushButton(layoutWidget);
        add->setObjectName("add");

        horizontalLayout->addWidget(add);

        edit = new QPushButton(layoutWidget);
        edit->setObjectName("edit");

        horizontalLayout->addWidget(edit);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(layoutWidget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        domoybutton = new QPushButton(bdeshka);
        domoybutton->setObjectName("domoybutton");
        domoybutton->setGeometry(QRect(570, 690, 141, 31));

        retranslateUi(bdeshka);

        QMetaObject::connectSlotsByName(bdeshka);
    } // setupUi

    void retranslateUi(QWidget *bdeshka)
    {
        bdeshka->setWindowTitle(QCoreApplication::translate("bdeshka", "Form", nullptr));
        view->setText(QCoreApplication::translate("bdeshka", "View", nullptr));
        remove->setText(QCoreApplication::translate("bdeshka", "Remove", nullptr));
        add->setText(QCoreApplication::translate("bdeshka", "Add", nullptr));
        edit->setText(QCoreApplication::translate("bdeshka", "Edit", nullptr));
        domoybutton->setText(QCoreApplication::translate("bdeshka", "\320\235\320\260 \320\263\320\273\320\260\320\262\320\275\321\203\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bdeshka: public Ui_bdeshka {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BDESHKA_H
