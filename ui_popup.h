/********************************************************************************
** Form generated from reading UI file 'popup.ui'
**
** Created: Thu 1. Jul 00:21:11 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP_H
#define UI_POPUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_popup
{
public:
    QLabel *label;

    void setupUi(QWidget *popup)
    {
        if (popup->objectName().isEmpty())
            popup->setObjectName(QString::fromUtf8("popup"));
        popup->resize(400, 107);
        popup->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(popup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 391, 101));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(39, 39, 39);\n"
"alternate-background-color: rgb(52, 39, 39, 100);\n"
"color: rgb(180, 55, 55);\n"
"\n"
"border-color: rgb(211, 131, 61);\n"
"\n"
"font: 9pt \"Calibri\";\n"
"\n"
"\n"
"margin: 3px;\n"
"border-width: 1px;\n"
"border-radius: 5px;\n"
"border-style:outset;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(popup);

        QMetaObject::connectSlotsByName(popup);
    } // setupUi

    void retranslateUi(QWidget *popup)
    {
        label->setText(QApplication::translate("popup", "TextLabel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(popup);
    } // retranslateUi

};

namespace Ui {
    class popup: public Ui_popup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_H
