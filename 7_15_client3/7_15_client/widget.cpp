#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
#include <QStyle>
#include <QPixmap>
#include <QDebug>
#include<QTime>
#include<QDate>
#include<QDebug>
#include <qpixmap.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建信号槽，建立按钮与页面切换自定义函数的连接
    connect(ui->aButton,&QPushButton::clicked,this,&Widget::switchPage);
    welcome_movie=new QMovie(this);

    ui->ip_line_edit->setStyleSheet("background-color:rgb(255,255,255,60);");
    ui->port_line_edit->setStyleSheet("background-color:rgb(255,255,255,60);");

    ui->flower_label->setPixmap(QPixmap(":/new/prefix1/5.jpg"));
    ui->flower_label->setScaledContents(true);

    ui->back_label->setPixmap(QPixmap(":/new/prefix1/7.png"));
    ui->back_label->setScaledContents(true);
    timer =new QTimer(this);


    ui->stackedWidget->setCurrentWidget(ui->welcome_page);
    welcome_movie->setFileName(":/new/prefix1/swim.gif");
    ui->label->setMovie(welcome_movie);
    ui->label->setScaledContents(true);
    welcome_movie->start();
     timer->start(5000);

     connect(timer,SIGNAL(timeout()),this,SLOT(timeout_slot()));

     QSound *sound=new QSound(":/new/prefix1/welcome.wav",this);
     sound->setLoops(1);
     sound->play();

         //设置left_Btn的图标
         //ui->left_btn->setIcon(QIcon(""));
         //ui->left_btn->setIcon(this->style()->standardIcon(QStyle::SP_ArrowLeft));

    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected_slot()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected_slot()));

   // this->setWindowOpacity(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timeout_slot()
{
    //7秒时间到，跳转到操作界面
    ui->stackedWidget->setCurrentWidget(ui->operator_page);
    //关闭定时器
    timer->stop();
    //动图停止播放
    welcome_movie->stop();

    time_timer=new QTimer(this);
    time_timer->start(1000);
    connect(time_timer,SIGNAL(timeout()),this,SLOT(timeout_1s_slot()));

}

void Widget::on_connect_btn_clicked()
{
    QString ip= ui->ip_line_edit->text();
    int port = ui->port_line_edit->text().toInt();
    socket->connectToHost(ip,port);
}
void Widget::connected_slot()
{
    qDebug()<<"连接小车成功";
    ui->connect_btn->setEnabled(false);
}
void Widget::disconnected_slot()
{
    qDebug()<<"已和小车断开连接";
    ui->connect_btn->setEnabled(true);
}

void Widget::on_forward_btn_pressed()
{
   unsigned char cmd[5]={0xff,0,1,0,0xff};
   socket->write((char*)cmd,sizeof(cmd));
}


void Widget::on_forward_btn_released()
{
    unsigned char cmd[5]={0xff,0,0,0,0xff};
    socket->write((char*)cmd,sizeof(cmd));
}

void Widget::timeout_1s_slot()
{
        //获得当前系统时间并显示
    QString date=QDate::currentDate().toString("yyyy-M-d");
    QString time=QTime::currentTime().toString("hh:mm:ss");
     ui->on_time_label->setText(date + " " + time);
    //QString date=QDate::currentDate().toString("yyyy-M-d ddd");
   // QString time=Qtime::currentTime().toString("hh:mm:ss");
   // ui->time_label->setText(data + " " + time);
}


//void Widget::on_forward_btn_clicked()
//{
    // ui->car_label->setPixmap(QPixmap(":/new/prefix1/forward.jpg"));
   //  qDebug()<<"前进";
//}


//void Widget::on_left_btn_clicked()
//{
    //建立car_label上的图片切换成左转的图片
  //      ui->car_label->setPixmap(QPixmap("::/new/prefix1/left.jpg"));
  //      qDebug()<<"左转";
//}


//void Widget::on_backward_btn_clicked()
//{
    //  ui->car_label->setPixmap(QPixmap(":/new/prefix1/back.jpg"));
   //   qDebug()<<"后退";
//}


//void Widget::on_right_btn_clicked()
//{
  //     ui->car_label->setPixmap(QPixmap(":/new/prefix1/right.jpg"));
  //     qDebug()<<"右转";
//}


//void Widget::on_stop_btn_clicked()
//{
  //  ui->car_label->setPixmap(QPixmap(":/new/prefix1/stop.jpg"));
 //     qDebug()<<"停止";
//}
void Widget::switchPage(){
    //获取按下的按钮的指针
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button==ui->aButton)
        ui->stackedWidget->setCurrentIndex(1);//根据按下的button按索引显示相应的页面
    else if(button==ui->bButton)
        ui->stackedWidget->setCurrentIndex(2);
    else if(button==ui->cButton)
        ui->stackedWidget->setCurrentIndex(0);

}


void Widget::on_aButton_clicked()
{
    switchPage();
}


void Widget::on_bButton_clicked()
{
    switchPage();
}


void Widget::on_cButton_clicked()
{
    switchPage();
}


void Widget::on_left_btn_pressed()
{
    unsigned char cmd[5]={0xff,0,3,0,0xff};
    socket->write((char*)cmd,sizeof(cmd));
}


void Widget::on_left_btn_released()
{
    unsigned char cmd[5]={0xff,0,0,0,0xff};
    socket->write((char*)cmd,sizeof(cmd));
}


void Widget::on_backward_btn_pressed()
{
    unsigned char cmd[5]={0xff,0,2,0,0xff};
    socket->write((char*)cmd,sizeof(cmd));
}


void Widget::on_backward_btn_released()
{
    unsigned char cmd[5]={0xff,0,0,0,0xff};
    socket->write((char*)cmd,sizeof(cmd));
}


void Widget::on_right_btn_pressed()
{
    unsigned char cmd[5]={0xff,0,4,0,0xff};
    socket->write((char*)cmd,sizeof(cmd));
}


void Widget::on_right_btn_released()
{
    unsigned char cmd[5]={0xff,0,0,0,0xff};
    socket->write((char*)cmd,sizeof(cmd));
}


void Widget::on_stop_btn_clicked()
{
    unsigned char cmd[5]={0xff,1,1,1,0xff};
    socket->write((char*)cmd,sizeof(cmd));
}

