/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mywidget
{
public:
    QWidget *centralwidget;
    QPushButton *RefreshBtn;
    QPushButton *CityBtn;
    QTextBrowser *textBrowser;
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
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(80, 110, 401, 271));
        mywidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mywidget);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
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
        textBrowser->setHtml(QCoreApplication::translate("mywidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\227\245\346\234\237: &quot;2024-06-01&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\231\275\345\244\251\345\244\251\346\260\224: &quot;\345\244\232\344\272\221&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\""
                        ">\345\244\234\346\231\232\345\244\251\346\260\224: &quot;\345\244\232\344\272\221&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\351\253\230\346\270\251\345\272\246: &quot;32&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\344\275\216\346\270\251\345\272\246: &quot;18&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\231\275\345\244\251\351\243\216\345\220\221: &quot;\350\245\277\345\215\227\351\243\216&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\244\234\346\231\232\351\243\216\345\220\221: &quot;\344\270\234\345\214\227\351\243\216&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt"
                        "-block-indent:0; text-indent:0px;\">-------------------</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\227\245\346\234\237: &quot;2024-06-02&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\231\275\345\244\251\345\244\251\346\260\224: &quot;\345\244\232\344\272\221&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\244\234\346\231\232\345\244\251\346\260\224: &quot;\345\244\232\344\272\221&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\351\253\230\346\270\251\345\272\246: &quot;32&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\344\275\216\346\270\251"
                        "\345\272\246: &quot;17&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\231\275\345\244\251\351\243\216\345\220\221: &quot;\344\270\234\345\214\227\351\243\216&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\244\234\346\231\232\351\243\216\345\220\221: &quot;\345\215\227\351\243\216&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-------------------</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\227\245\346\234\237: &quot;2024-06-03&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\231\275\345\244\251\345\244\251\346\260\224: &quot;\345\244\232\344\272\221&quot;</p>\n"
"<"
                        "p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\244\234\346\231\232\345\244\251\346\260\224: &quot;\351\230\264&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\351\253\230\346\270\251\345\272\246: &quot;32&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\234\200\344\275\216\346\270\251\345\272\246: &quot;19&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\231\275\345\244\251\351\243\216\345\220\221: &quot;\350\245\277\345\215\227\351\243\216&quot;</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\244\234\346\231\232\351\243\216\345\220\221: &quot;\345\215\227\351\243\216&quot"
                        ";</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-------------------</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mywidget: public Ui_mywidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
