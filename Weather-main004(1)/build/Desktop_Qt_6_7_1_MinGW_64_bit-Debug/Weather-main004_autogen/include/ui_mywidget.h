/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mywidget
{
public:
    QWidget *centralwidget;
    QPushButton *RefreshBtn;
    QPushButton *CityBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mywidget)
    {
        if (mywidget->objectName().isEmpty())
            mywidget->setObjectName("mywidget");
        mywidget->resize(800, 600);
        mywidget->setStyleSheet(QString::fromUtf8("#MainWindow{background-image: url(:/new/prefix1/images/WeiMingLake.png);}"));
        centralwidget = new QWidget(mywidget);
        centralwidget->setObjectName("centralwidget");
        RefreshBtn = new QPushButton(centralwidget);
        RefreshBtn->setObjectName("RefreshBtn");
        RefreshBtn->setGeometry(QRect(610, 20, 80, 24));
        CityBtn = new QPushButton(centralwidget);
        CityBtn->setObjectName("CityBtn");
        CityBtn->setGeometry(QRect(610, 60, 80, 24));
        CityBtn->setStyleSheet(QString::fromUtf8(""));
        mywidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mywidget);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        mywidget->setMenuBar(menubar);
        statusbar = new QStatusBar(mywidget);
        statusbar->setObjectName("statusbar");
        mywidget->setStatusBar(statusbar);

        retranslateUi(mywidget);

        QMetaObject::connectSlotsByName(mywidget);
    } // setupUi

    void retranslateUi(QMainWindow *mywidget)
    {
        mywidget->setWindowTitle(QCoreApplication::translate("mywidget", "mywidget", nullptr));
        RefreshBtn->setText(QCoreApplication::translate("mywidget", "\345\210\267\346\226\260", nullptr));
        CityBtn->setText(QCoreApplication::translate("mywidget", "\345\210\207\346\215\242\345\237\216\345\270\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mywidget: public Ui_mywidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
