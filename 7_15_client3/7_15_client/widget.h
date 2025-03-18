#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QMovie>
#include<QSound>
#include<QTimer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void timeout_slot();
     void timeout_1s_slot();

private slots:
    void on_connect_btn_clicked();
    void connected_slot();
    void disconnected_slot();
    //void on_left_btn_clicked();
    //void on_right_btn_clicked();
    //void on_backward_btn_clicked();
    //void on_forward_btn_clicked();
   // void on_stop_btn_clicked();

    void switchPage();//切换界面


   void on_forward_btn_pressed();

    void on_forward_btn_released();


    void on_aButton_clicked();

    void on_bButton_clicked();

    void on_cButton_clicked();

    void on_left_btn_pressed();

    void on_left_btn_released();

    void on_backward_btn_pressed();

    void on_backward_btn_released();

    void on_right_btn_pressed();

    void on_right_btn_released();

    void on_stop_btn_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
    QMovie *welcome_movie;
    QTimer *timer;
    QTimer *time_timer;

};
#endif // WIDGET_H
