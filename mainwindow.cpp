#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    read_conf();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(update_im()));
    ui->setupUi(this);
    this->setAttribute(Qt::WA_NoChildEventsFromChildren);
    QDesktopWidget *pulpit;
    pulpit = new QDesktopWidget();

    QRect rozmiar = pulpit->geometry();
    this->move(QPoint((int)(rozmiar.bottomRight().x() -250) ,(int)(rozmiar.bottomRight().y() -600 )));
    //ui->listWidget->setSortingEnabled(true);

    // test:

    tacka = new QSystemTrayIcon(QIcon(":/status/offline"),this);
    tacka->show();
    this->setCentralWidget(ui->verticalLayoutWidget);
    connect(tacka, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this , SLOT(tacka_activated(QSystemTrayIcon::ActivationReason)));

    this->ui->comboBox->setCurrentIndex(3);
        QMenu *trayIconMenu = new QMenu(this);

        trayIconMenu->addAction(ui->actionWyniki);
        trayIconMenu->addAction(ui->actionInfo);
        trayIconMenu->addAction(ui->actionZamknij);


        tacka->setContextMenu(trayIconMenu);
    read_users();
    tacka->setToolTip("Detoks - Wersja rozwojowa");
    pop = new popup;
    //pop = new popup;

    //tacka->contextMenu()->addSeparator();
    //
}

MainWindow::~MainWindow()
{
    delete(tacka);
    baza.close();
    delete ui;

}
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void MainWindow::Add_user_to_ui(QString name){
//funkcja zbyteczna
}
void MainWindow::on_listWidget_doubleClicked(QModelIndex index)
{

    //qDebug("------------------------kno ma wartosc :"+users[index.row()].isconversationopen );
    if(baza.baseobject.isOpen()&&users[index.row()].isconversationopen==0){
        volatile int *op;
        op = &(users[index.row()].isconversationopen);
        talkw *okienko = new talkw(this, QString(ui->listWidget->item(index.row())->text()), users[index.row()].domena, &baza,op );
    ui->listWidget->item(index.row())->setIcon(QIcon(":/imstatus/"+users[index.row()].status));

      //  users[index.row()].isconversationopen = 1 ;
    okienko->show();


    tacka->setIcon(QIcon(":/status/"+status));
}
}
void MainWindow::tacka_activated(QSystemTrayIcon::ActivationReason reason){
    if(reason==QSystemTrayIcon::DoubleClick){ // tray icon duble clicked
        if (this->isHidden()){// show and activate /hide main window
            this->show();
            this->setFocus();
            this->activateWindow();
            this->setWindowState(Qt::WindowActive);

        }else{
                this->setHidden(true);
               //this->hide();
           }


    }
}
void MainWindow::on_comboBox_currentIndexChanged(int index)
{


    switch(index){ // tray icon changing
    case 3:
        tacka->setIcon(QIcon(":/status/offline"));
        status = "offline";

        break;
    case 1:
        tacka->setIcon(QIcon(":/status/busy"));
        status = "busy";

        break;
    case 2:
        tacka->setIcon(QIcon(":/status/invisible"));
        status = "invisible";

        break;
    case 0:
        tacka->setIcon(QIcon(":/status/online"));
        status = "online";

        break;
    }

    if(index==3){
        baza.updatemystatus("offline");
        baza.close();
        if (timer->isActive()){timer->stop();}
        tacka->showMessage("", "Zamkniêto po³¹czenie",QSystemTrayIcon::Information,300);
        this->ui->statusBar->showMessage("Nie po³¹czony");
            }else{
                if(baza.baseobject.isOpen()==false){
        if(baza.connetc()){

            this->ui->statusBar->showMessage("Po³¹czony");

            baza.updatemystatus(status);
            if (!timer->isActive()){timer->start(10000);}
            if (!this->checkpass(1)){this->ui->comboBox->setCurrentIndex(3);tacka->showMessage("B£¥D AUTORYZACJI" , "B£ÊDNY LOGIN LUB HAS£O");}
        }else{

            this->ui->comboBox->setCurrentIndex(3);
            this->tacka->showMessage("B£¥D",baza.baseobject.lastError().text());
            this->ui->statusBar->showMessage("B³¹d Po³¹czenia");

        }


    }else{
        baza.updatemystatus(status);
    }
    }
}
void MainWindow::read_users(){
qDebug("czytanie znajomych");
    QFile plik("friends.conf");
    QString linia;
    if (!plik.open(QFile::ReadOnly)){
        QMessageBox msgBox;
         msgBox.setText("Nie znalaz³em pliku listy znajomych friends.conf\n IdŸ na NK i poznaj jakichs ludzi !");
         msgBox.setIcon(QMessageBox::Critical);
         msgBox.exec();
         exit(2);
    }
    int x =0;
    while(!plik.atEnd()){
         linia= plik.readLine();
         qDebug(linia.toStdString().c_str());
         QStringList splited = linia.split(";");
        user u;
        u.domena= splited[0];
        u.nazwa= QString(splited[1]);
        u.mail = splited[2];
        u.IP = splited[3].left(QString(splited[3]).length()-2);
        u.id = x;
        u.isconversationopen = 0;
        item=new QListWidgetItem(QIcon(":/imstatus/offline"),u.nazwa,0);
        ui->listWidget->addItem(item);
        


        u.status = "offline";
        x++;
        lista.append(u.nazwa);
        users.append(u);
        //Add_user_to_ui(u.nazwa);
    }
}
void MainWindow::read_conf(){
qDebug("czytanie Konfiguracji z pliku");
    QFile plik("settings.conf");

        ;

    if (!plik.open(QFile::ReadOnly)){
        QMessageBox msgBox;
         msgBox.setText("Nie uda³o siê otworzyæ pliku settings.conf\n SprawdŸ czy plik istnieje!");
         msgBox.setIcon(QMessageBox::Critical);
         msgBox.exec();
         exit(2);
    }

    while(!plik.atEnd()){
            QString linia = plik.readLine();
            QStringList  atribute= linia.split("=");

            if (atribute[0]==QString("username")){
                this->settings.myid = QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else if (atribute[0]==QString("userpwd")){
                this->settings.mypass=QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else if (atribute[0]==QString("dbhostip")){
                this->settings.databasehost =QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else if(atribute[0]==QString("dbname")){
                this->settings.databasename = QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else if (atribute[0]==QString("dbuser")){
                this->settings.databaseuid=QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else if(atribute[0]==QString("dbpwd")){
                this->settings.databasepwd=QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else if(atribute[0]==QString("dbschema")){
                this->settings.dbschema=QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else if(atribute[0]==QString("dbprefix")){
                this->settings.table_prefix=QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else if(atribute[0]==QString("dbauthtable")){
                this->settings.dbauthenticationtable=QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else if(atribute[0]==QString("kpiurl")){
                this->settings.URLWyniki=QString(atribute[1]).left(QString(atribute[1]).length()-2);
            }else{
                qDebug("Nie rozpoznana opcja");
            }

//W razie nie podania has³a , lub loginu upomnimy siê o niego


    }
    if (this->settings.myid == ""){this->settings.myid= QInputDialog::getText(this, "Brak loginu", "Podaj login - mo¿esz go zapisaæ w pliku z ustawieniami",QLineEdit::Normal);}
    if (this->settings.mypass == ""){this->settings.mypass= QInputDialog::getText(this, "Brak has³o", "Podaj has³o - mo¿esz je zapisaæ w pliku z ustawieniami",QLineEdit::Password);}
baza.setdatabase(this->settings.databasehost, this->settings.databasename, this->settings.databaseuid, this->settings.databasepwd, this->settings.dbschema , this->settings.table_prefix, this->settings.myid, this->settings.dbauthenticationtable);
plik.close();
//plik.~QFile();
}
void MainWindow::update_statuses(){
    QStringList cstatusy = this->baza.whois_online();
    //QStringList msgs = this->baza.New_conversations(settings.myid);
    bool obecny;
    for(int x = 0;x<users.count();x++){
            obecny=false;
            for (int y = 0;y<cstatusy.count();y++){
                QStringList ludek = cstatusy[y].split(";");
                if(ludek[0]==users[x].domena){
                    obecny=true;
                    if (ludek[1]!=users[x].status){
                        //tacka->showMessage(users[x].nazwa, QString( " jest teraz "+ ludek[1]));
                        msgpopup(QString(users[x].nazwa+ QString( " jest teraz "+ ludek[1])));
                        users[x].status = ludek[1];
                        ui->listWidget->item(x)->setIcon(QIcon(QString(":/imstatus/"+ludek[1])));
                    }
                }
            }
            if(!obecny&&users[x].status!=QString("offline")){
                    msgpopup(QString(users[x].nazwa+ QString( " jest teraz niedostêpny")));
                    users[x].status = QString("offline");
                    ui->listWidget->item(x)->setIcon(QIcon(QString(":/imstatus/offline")));
            }
     }
   baza.updatemystatus(status );
   QStringList new_msgs_nadawca= baza.New_conversations();
   for (int x = 0 ;x<users.count();x++){
       for (int y = 0;y<new_msgs_nadawca.size();y++){

           if(new_msgs_nadawca[y]==users[x].domena){
                    ui->listWidget->item(x)->setIcon(QIcon(QString(":/icons/msg")));
                    msgpopup("Wiadomoœæ od" + users[x].nazwa );
                    this->tacka->setIcon(QIcon(QString(":/icons/msg")));
           }
       }
   }



}
void MainWindow::update_im(){
    update_statuses();

}
void MainWindow::on_actionZamknij_triggered()
{
    delete(tacka);
    baza.close();
    delete ui;
    exit(0);
    //this->close();
}
bool MainWindow::checkpass(int proba){
bool uwierzytelniono = false;
//if(proba==0){return false;}
if (!baza.authentication(this->settings.mypass)){
           this->settings.mypass= QInputDialog::getText(this, "B³êdne has³o", "Podaj has³o dla "+this->settings.myid+ "- mo¿esz je zapisaæ w pliku z ustawieniami",QLineEdit::Password);
           if (baza.authentication(this->settings.mypass)){uwierzytelniono=true;}
           //checkpass(0);
       }else{
            uwierzytelniono = true;

    }
return uwierzytelniono;
}


void MainWindow::on_actionUstawienia_triggered()
{
    if (timer->isActive()){timer->stop();}
    system("notepad settings.conf");
    this->read_conf();
    if (timer->isActive()){timer->stop();}
     timer->start(10000);
}



void MainWindow::on_actionEmail_triggered()
{
    if (timer->isActive()){timer->stop();}
    if(ui->listWidget->currentRow()!=-1){
    int a =system(QString("smail.vbs " + users[this->ui->listWidget->currentRow()].mail  ).toStdString().c_str());

   if(a!=0){
       msgpopup(QString("Nie uda³o siê wys³aæ maila :( "));
   }
}
 timer->start(10000);
}

void MainWindow::on_actionNet_send_triggered()
{
if (timer->isActive()){timer->stop();}
bool ok;
    QString msg =QInputDialog::getText(this, QString("pos³aniec ")+ users[this->ui->listWidget->currentRow()].IP , "Wpisz treœæ wiadomoœci jak¹ chcesz wys³aæ", QLineEdit::Normal, "", &ok);
 if (ok && !msg.isEmpty()){
    int a = system(QString("net send " + users[this->ui->listWidget->currentRow()].IP + " " + this->settings.myid + ": "+ msg).toStdString().c_str());
    if(a!=0){
        msgpopup(QString("Wys³anie pos³añca nie udane"));
    }else{
        msgpopup(QString("Wys³ano pos³añca o treœci :")+  msg);
    }
}
 timer->start(10000);
}

void MainWindow::on_actionInfo_triggered()
{
    QFile plik("README.txt");



    if (!plik.open(QFile::ReadOnly)){
        QMessageBox::about(this, "O programie", "INFORMACJA O programie<br> brak pliku readme ");
        //msg.setIcon(QMessageBox);
    }else{
     QString ab = plik.readAll();
     QMessageBox::about(this, "O programie", ab);
    }

}

void MainWindow::on_actionModyfikuj_list_znajomych_triggered()
{
    this->ui->comboBox->setCurrentIndex(3);
    system ("notepad friends.conf");
    ui->listWidget->clear();
    this->users.clear();
    this->read_users();
}
void MainWindow::menushortcutpresed(){
on_actionInfo_triggered();
}
void MainWindow::closeEvent(QCloseEvent *event){
    if (!this->isHidden()){this->hide();}
      //this->show();
        event->ignore();

}

void MainWindow::on_actionWyniki_triggered()
{
    QWebView *view ;

           view = new QWebView(0);
    view->load(QUrl(this->settings.URLWyniki));

    view->show();

    msgpopup("przegl¹darka WEBKIT");

}
void MainWindow::msgpopup(QString msg){

pop->execute(msg);

}
