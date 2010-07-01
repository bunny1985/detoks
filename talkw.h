#ifndef TALKW_H
#define TALKW_H

#include <QMainWindow>
#include <QTimer>
#include "databaseclass.h"
#include <QCloseEvent>
#include "mainwindow.h"

namespace Ui {
    class talkw;
}

class talkw : public QMainWindow {
    Q_OBJECT
public:

    talkw(QWidget *parent, QString odbiorca, QString odbdomena, databaseclass *baza, volatile int  *opened );
    ~talkw();
    databaseclass *db;

protected:
    void changeEvent(QEvent *e);

private:
    QString add_emots(QString msg);
    void closeEvent(QCloseEvent *event);
    Ui::talkw *ui;
    QTimer *timer;
    QString domena;
    volatile int *wopened;

private slots:

    //void on_talkw_destroyed();
    void on_lineEdit_returnPressed();
    void on_pushButton_clicked();
    void update_msg();


};

#endif // TALKW_H
