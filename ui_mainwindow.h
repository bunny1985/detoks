/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 28. Jun 01:19:39 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionUstawienia;
    QAction *actionModyfikuj_list_znajomych;
    QAction *actionZamknij;
    QAction *actionEmail;
    QAction *actionNet_send;
    QAction *actionInfo;
    QAction *actionWyniki;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QComboBox *comboBox;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menu_czno;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(235, 421);
        MainWindow->setMaximumSize(QSize(400, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/zas/icons/penguin.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(39, 39, 39);\n"
"alternate-background-color: rgb(52, 39, 39);\n"
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
"border-style:outset;\n"
""));
        actionUstawienia = new QAction(MainWindow);
        actionUstawienia->setObjectName(QString::fromUtf8("actionUstawienia"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/zas/icons/preferences-system.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUstawienia->setIcon(icon1);
        actionModyfikuj_list_znajomych = new QAction(MainWindow);
        actionModyfikuj_list_znajomych->setObjectName(QString::fromUtf8("actionModyfikuj_list_znajomych"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/zas/icons/resource-group.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionModyfikuj_list_znajomych->setIcon(icon2);
        actionZamknij = new QAction(MainWindow);
        actionZamknij->setObjectName(QString::fromUtf8("actionZamknij"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/zas/icons/window-close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZamknij->setIcon(icon3);
        actionEmail = new QAction(MainWindow);
        actionEmail->setObjectName(QString::fromUtf8("actionEmail"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/msg"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmail->setIcon(icon4);
        actionNet_send = new QAction(MainWindow);
        actionNet_send->setObjectName(QString::fromUtf8("actionNet_send"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/zas/icons/konversation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNet_send->setIcon(icon5);
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/zas/icons/dialog-information.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon6);
        actionWyniki = new QAction(MainWindow);
        actionWyniki->setObjectName(QString::fromUtf8("actionWyniki"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/emots/zas/emotki/face-wink.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionWyniki->setIcon(icon7);
        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, 0, 231, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Verdana"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        listWidget->setFont(font);
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"font: italic 10pt \"Verdana\";"));

        verticalLayout->addWidget(listWidget);

        comboBox = new QComboBox(verticalLayoutWidget);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/status/online"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon8, QString());
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/status/busy"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon9, QString());
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/status/invisible"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon10, QString());
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/status/offline"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon11, QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Calibri"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 66, 99);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(comboBox);

        MainWindow->setCentralWidget(widget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setFont(font1);
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 235, 29));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menu_czno = new QMenu(menuBar);
        menu_czno->setObjectName(QString::fromUtf8("menu_czno"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(31, 24));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menu_czno->menuAction());
        menuMenu->addAction(actionModyfikuj_list_znajomych);
        menuMenu->addAction(actionUstawienia);
        menuMenu->addSeparator();
        menuMenu->addAction(actionZamknij);
        menu_czno->addAction(actionEmail);
        menu_czno->addAction(actionNet_send);
        toolBar->addAction(actionUstawienia);
        toolBar->addAction(actionModyfikuj_list_znajomych);
        toolBar->addAction(actionEmail);
        toolBar->addAction(actionNet_send);
        toolBar->addSeparator();
        toolBar->addAction(actionInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Detoks v 0.2", 0, QApplication::UnicodeUTF8));
        actionUstawienia->setText(QApplication::translate("MainWindow", "Ustawienia", 0, QApplication::UnicodeUTF8));
        actionModyfikuj_list_znajomych->setText(QApplication::translate("MainWindow", "Modyfikuj list\304\231 znajomych", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionModyfikuj_list_znajomych->setToolTip(QApplication::translate("MainWindow", "Modyfikuj list\304\231 znajomych", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionZamknij->setText(QApplication::translate("MainWindow", "Zamknij", 0, QApplication::UnicodeUTF8));
        actionZamknij->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionEmail->setText(QApplication::translate("MainWindow", "Wy\305\233lij Maila", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEmail->setToolTip(QApplication::translate("MainWindow", "wy\305\233lij Maila", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEmail->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionNet_send->setText(QApplication::translate("MainWindow", "Net send", 0, QApplication::UnicodeUTF8));
        actionNet_send->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        actionInfo->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionWyniki->setText(QApplication::translate("MainWindow", "wyniki :)", 0, QApplication::UnicodeUTF8));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Dost\304\231pny", 0, QApplication::UnicodeUTF8));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Zaj\304\231ty", 0, QApplication::UnicodeUTF8));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "Niewidoczny", 0, QApplication::UnicodeUTF8));
        comboBox->setItemText(3, QApplication::translate("MainWindow", "Niedost\304\231pny", 0, QApplication::UnicodeUTF8));

        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        menu_czno->setTitle(QApplication::translate("MainWindow", "Wiadmomo\305\233ci", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
