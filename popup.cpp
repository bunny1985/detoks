#include "popup.h"
#include "ui_popup.h"

popup::popup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::popup)
{

    ui->setupUi(this);

    this->setWindowFlags(Qt::Tool|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

    QDesktopWidget *pulpit;
    pulpit = new QDesktopWidget();
    QRect rozmiar = pulpit->geometry();

    this->move(QPoint((int)(rozmiar.bottomRight().x() -400) ,(int)(rozmiar.bottomRight().y() -150 )));

    timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()),this, SLOT(tick()));
        this->setAttribute(Qt::WA_TranslucentBackground);
        this->setAttribute(Qt::WA_DeleteOnClose);



            ui->label->setWindowOpacity(1.0);
            this->showed = false;
            op=0;
            ui->label->setText("Start systemu notyfikacji");
            this->show();
            timer->start(50);

        }

popup::~popup()
{
    //delete ui;
    //this->~QWidget();
}

void popup::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void popup::tick(){
    if(this->showed){
        op-=0.125;
        this->setWindowOpacity(op);
        if(op<=0.0){this->hide();timer->stop();opened= false;}
    }else{
        op+=0.125;
        this->setWindowOpacity(op);

        if(op>=3.0){showed=true;}
    }
}
void popup::execute(QString msg){
    if (!opened){
    opened= true;
    ui->label->setWindowOpacity(1.0);
    this->showed = false;
    op=0;
    ui->label->setText(msg);
    this->show();
    timer->start(50);
}else{
    ui->label->setText(ui->label->text().append("\n"+msg));
    op=0;
}



    ;

}
