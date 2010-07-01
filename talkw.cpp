#include "talkw.h"
#include "ui_talkw.h"



talkw::talkw(QWidget *parent, QString odbiorca, QString domena , databaseclass *baza, volatile int *opened ) :
    QMainWindow(0),
    ui(new Ui::talkw)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->gridLayoutWidget);
    this->ui->label->setText("Rozmowa z "+ odbiorca);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(update_msg()));
    ui->lineEdit->setFocus();;
    db= baza;
    this->domena = domena;
    update_msg();
     this->wopened = opened;
     opened = false;
        if (!timer->isActive()){timer->start(3000);}
        this->setAttribute(Qt::WA_NoChildEventsForParent);


}


talkw::~talkw()
{


}

void talkw::changeEvent(QEvent *e)
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

void talkw::update_msg(){
    QStringList list = db->Open_conversation(domena);
    for (int x = 0; x<list.count();x++){
        this->ui->textEdit->append("<FONT size=4><b>"+domena +":  </b>"+ add_emots(list[x]+"</FONT>\n"));
    }
}

void talkw::on_pushButton_clicked()
{

    db->send_message(ui->lineEdit->text(), this->domena);

    ui->textEdit->append("<FONT size=3 color=#808080><b>JA:    </b>"+add_emots(ui->lineEdit->text()+ "</FONT>\n"));
    ui->lineEdit->clear();
}
QString talkw::add_emots(QString msg){
 QString replaced;
 replaced = msg.replace("0:)" , "<img src=\":/emots/zas/emotki/face-angel.png\" />");
 replaced = msg.replace(":P" , "<img src=\":/emots/zas/emotki/face-raspberry.png\" />");
 replaced = msg.replace(":)" , "<img src=\":/emots/zas/emotki/face-smile.png\" />");
 replaced = msg.replace(":(" , "<img src=\":/emots/zas/emotki/face-sad.png\" />");
 replaced = msg.replace(":*" , "<img src=\":/emots/zas/emotki/face-kiss.png\" />");
 replaced = msg.replace(";)" , "<img src=\":/emots/zas/emotki/face-wink.png\" />");

 replaced = msg.replace(";D" , "<img src=\":/emots/zas/emotki/face-laugh.png\" />");

 return replaced;
}

//QCloseEvent *event
 void talkw::closeEvent(QCloseEvent *event){

     this->wopened = 0;
     timer->stop();
        qDebug("zamykanie okna rozmowy");
        event->ignore();
this->~QMainWindow();
//this->~talkw();

}



void talkw::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}


