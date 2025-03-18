#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建信号槽，建立按钮与页面切换自定义函数的连接
    connect(ui->aButton,&QPushButton::clicked,this,&MainWindow::switchPage);
    connect(ui->bButton,&QPushButton::clicked,this,&MainWindow::switchPage);
    connect(ui->cButton,&QPushButton::clicked,this,&MainWindow::switchPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::switchPage(){
    //获取按下的按钮的指针
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if(button==ui->aButton)
        ui->stack->setCurrentIndex(0);//根据按下的button按索引显示相应的页面
    else if(button==ui->bButton)
        ui->stack->setCurrentIndex(1);
    else if(button==ui->cButton)
        ui->stack->setCurrentIndex(2);

}
