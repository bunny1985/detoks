#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QSystemTrayIcon>
#include <QVector>
#include <QObject>
#include <QSqlDatabase>
#include <databaseclass.h>
#include <QFile>
#include <talkw.h>
#include <QMessageBox>
#include <QInputDialog>
#include <QTimer>
#include <QDebug>
#include <QCloseEvent>
#include <QMenu>
#include <QWebView>
#include <QSqlError>
#include "popup.h"
 #include <QDesktopWidget>



namespace Ui {
    class MainWindow;

}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:

    struct user{

            QString domena;
            QString nazwa;
            int id;
            QString status;
            QString mail;
            QString IP;
            volatile int isconversationopen;

        };
    struct mysettings{
        QString myid;
        QString mypass;
        QString databasehost;
        QString databasename;
        QString databaseuid;
        QString databasepwd;
        QString table_prefix;
        QString dbschema;
        QString dbauthenticationtable;
        QString URLWyniki;
    };



    MainWindow(QWidget *parent = 0);
    ~MainWindow();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    void read_conf ();
    void Add_user_to_ui(QString name);
    void read_users ();
    void update_statuses();
    bool checkpass(int proba);
    void menushortcutpresed();
    void closeEvent(QCloseEvent *event);
    void msgpopup(QString msg);
    popup *pop;

     databaseclass baza;
     QListWidgetItem *item;
     QSystemTrayIcon *tacka;
     QVector<user> users;
     QVector<QString> lista; 


     mysettings settings;
     QString status;
     QTimer *timer;


private slots:
    void on_actionWyniki_triggered();
    void on_actionModyfikuj_list_znajomych_triggered();
    void on_actionInfo_triggered();
    void on_actionNet_send_triggered();
    void on_actionEmail_triggered();

    void on_actionUstawienia_triggered();
    void on_actionZamknij_triggered();
    void on_comboBox_currentIndexChanged(int index);
    void on_listWidget_doubleClicked(QModelIndex index);
    void tacka_activated(QSystemTrayIcon::ActivationReason reason);
    void update_im();
};

#endif // MAINWINDOW_H
