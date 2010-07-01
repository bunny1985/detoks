/********************************************************************************
** Form generated from reading UI file 'talkw.ui'
**
** Created: Sat 26. Jun 01:03:24 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TALKW_H
#define UI_TALKW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_talkw
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *talkw)
    {
        if (talkw->objectName().isEmpty())
            talkw->setObjectName(QString::fromUtf8("talkw"));
        talkw->resize(515, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/zas/icons/konversation.png"), QSize(), QIcon::Normal, QIcon::Off);
        talkw->setWindowIcon(icon);
        talkw->setStyleSheet(QString::fromUtf8("\n"
"border-color: rgb(126, 126, 126);\n"
"\n"
"font: 9pt \"Calibri\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 7px;\n"
"\n"
"margin: 3px;\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(245, 245, 245);"));
        gridLayoutWidget = new QWidget(talkw);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 521, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(gridLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(208, 203, 236);\n"
"color: rgb(0, 0, 0);"));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        textEdit->setAutoFormatting(QTextEdit::AutoAll);
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 1, 0, 1, 2);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 4, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(label, 0, 0, 1, 2);


        retranslateUi(talkw);

        QMetaObject::connectSlotsByName(talkw);
    } // setupUi

    void retranslateUi(QWidget *talkw)
    {
        talkw->setWindowTitle(QApplication::translate("talkw", "Detoks Conversation box ", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("talkw", "Wy\305\233lij", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("talkw", "Rozmowa z :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class talkw: public Ui_talkw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TALKW_H
