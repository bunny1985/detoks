#ifndef DATABASECLASS_H
#define DATABASECLASS_H

#include <QSqlDatabase>
#include <QMutex>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>



class databaseclass
{
public:
bool authentication(QString pass);
bool connetc();
bool close();
void updatemystatus(QString status);
void unregister_connection();
void register_connection();
void setdatabase(QString ip, QString dbname ,QString dbuser, QString dbpass , QString dbschema, QString dbprefix, QString myname , QString password);

QStringList whois_online();
QStringList New_conversations();
QStringList Open_conversation(QString odbiorca);
void send_message(QString tresc , QString odbiorca);

    databaseclass();

    QSqlDatabase baseobject;





private:
    void isqueok(QSqlQuery q);


    QString schema;
    QString prefix;
    QString myname;
    QString sql;
    QSqlQuery que;
    QMutex blokada;
    QString password;
    QString authenticationtable;
};

#endif // DATABASECLASS_H
