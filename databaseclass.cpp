#include "databaseclass.h"
#include <iostream>

databaseclass::databaseclass()
{
// pusta implementacja

}
bool databaseclass::connetc(){

    if(baseobject.open()){
        return true;
    }else{

        return false;
    }
}
bool databaseclass::close(){

    if(this->baseobject.isOpen()==false){
        return true;
            }else{
        baseobject.close();

        return true;
    }
}

void databaseclass::setdatabase(QString ip, QString dbname, QString dbuser, QString dbpass, QString dbschema, QString dbprefix , QString myname, QString authtable){
    this->baseobject = QSqlDatabase::addDatabase("QPSQL");
    baseobject.setHostName(ip);
    baseobject.setDatabaseName(dbname);
    baseobject.setPassword(dbpass);
    baseobject.setUserName(dbuser);
    this->schema = dbschema;
    this->prefix =dbprefix;
    this->myname = myname;
    this->authenticationtable= authtable;

}

void databaseclass::updatemystatus(QString status){
if (this->blokada.tryLock(7)){
    if ( status==QString("offline")||status==QString("invisible")){
        sql=QString("delete from " +this->schema + "." + this->prefix + "im_status where nazwa='" + myname + "';");
        que=  this->baseobject.exec(QString(sql));
    isqueok(que);
    }else {

         sql = QString("delete from " +this->schema + "." + this->prefix + "im_status where nazwa='" + myname + "';""insert into  " +this->schema + "." + this->prefix + "im_status (nazwa, status ,last_seen) VALUES ('" +myname + "', '"+ status +"' , CURRENT_TIMESTAMP );" );
         que =     this->baseobject.exec(sql);
    isqueok(que);
    }
    blokada.unlock();
}
}
void databaseclass::isqueok(QSqlQuery q){
    if (q.isActive()){
        qDebug("zapytanie ok");
        qDebug(q.lastQuery().toStdString().c_str());
    }else{
        qDebug("zapytanie b³êdne");
        qDebug(q.lastQuery().toStdString().c_str());
    }
}
QStringList databaseclass::whois_online(){
    QStringList lista;
    if (blokada.tryLock(7)){
        sql = QString("select nazwa || ';' || status from " + this->schema + "." +this->prefix + "im_status where last_seen> CURRENT_TIMESTAMP - interval '2 minutes' ;");
        que = this->baseobject.exec(sql);
        isqueok(que);
        while(que.next()){
            QString wpis = que.value(0).toString();
            lista.append(wpis);
        }
        blokada.unlock();
    }
    return lista;
}
QStringList databaseclass::New_conversations(){
    QStringList msgs;
    if (blokada.tryLock(7)){
            QString sq;
            sq= QString("Select distinct nadawca from " +this->schema + "." + this->prefix + "msg where odbiorca ='" +myname  + "' AND read=false ");
            que = this->baseobject.exec(sq);
            isqueok(que);

            while(que.next()){
                QString wpis = que.value(0).toString();
                msgs.append(wpis);
            }
        }
    blokada.unlock();
    return msgs;
}
QStringList databaseclass::Open_conversation(QString odbiorca){
    QStringList msgs;
        if (blokada.tryLock(7)){
            QString sq;
            QString msgid;
            sq.append( QString("Select max(id) from " +this->schema + "." + this->prefix + "msg where odbiorca ='" +myname  + "' AND read=false AND nadawca='"+odbiorca+"'; "));
                        que = this->baseobject.exec(sq);
                        isqueok(que);
                        while(que.next()){
                            msgid = que.value(0).toString();

                        }

            sq=  QString("Select tresc from " +this->schema + "." + this->prefix + "msg where odbiorca ='" +myname  + "' AND read=false AND nadawca='"+odbiorca+"'  order by czas;");
                        que = this->baseobject.exec(sq);
                        isqueok(que);
            while(que.next()){
                QString wpis = que.value(0).toString();
                msgs.append(QByteArray::fromHex(wpis.toStdString().c_str()));
            }
            sq=  QString("update  " +this->schema + "." + this->prefix + "msg set read=true where odbiorca ='" +myname  + "' AND read=false AND nadawca='"+odbiorca+"'  AND  id <= '" + msgid+ "';");
                        que = this->baseobject.exec(sq);
                        isqueok(que);
        }
        blokada.unlock();
return msgs;
}
void databaseclass::send_message(QString tresc, QString odbiorca){
       if (blokada.tryLock(7)){
            QString sq;
            sq = "INSERT INTO "+this->schema + "." + this->prefix + "msg (odbiorca , nadawca , czas , tresc, read) Values ('" + odbiorca + "' , '" + this->myname + "' ,  CURRENT_TIMESTAMP,'" +QByteArray(tresc.toStdString().c_str()).toHex()+ "' , false ) ";
            que = this->baseobject.exec(sq);
            isqueok(que);
       }
       blokada.unlock();
}
bool databaseclass::authentication(QString pass){
    if(this->blokada.tryLock(7)){
        QString sql,pwd;
        sql = "select haslo from " +this->schema + "." + this->authenticationtable + " where login='" + this->myname + "' ;";
              que = this->baseobject.exec(sql);
              isqueok(que);
              while(que.next()){pwd = que.value(0).toString();}
              if (pass==pwd){
                  blokada.unlock();
                  return true;
              }else{
                  blokada.unlock();
                  return false;
              }

}
    blokada.unlock();
    return false;

}
