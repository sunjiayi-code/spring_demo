/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *welcome_page;
    QLabel *label;
    QPushButton *aButton;
    QWidget *operator_page;
    QPushButton *connect_btn;
    QLabel *ip_label;
    QLabel *port_label;
    QLineEdit *ip_line_edit;
    QLineEdit *port_line_edit;
    QLabel *on_time_label;
    QPushButton *bButton;
    QLabel *signin_label;
    QLabel *flower_label;
    QWidget *page;
    QStackedWidget *stackedWidget_2;
    QWidget *page_2;
    QPushButton *stop_btn;
    QPushButton *backward_btn;
    QPushButton *left_btn;
    QPushButton *forward_btn;
    QPushButton *right_btn;
    QPushButton *cButton;
    QLabel *back_label;
    QWidget *page_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 801, 601));
        QFont font;
        font.setFamily(QString::fromUtf8("Franklin Gothic Demi Cond"));
        stackedWidget->setFont(font);
        welcome_page = new QWidget();
        welcome_page->setObjectName(QString::fromUtf8("welcome_page"));
        label = new QLabel(welcome_page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 801, 601));
        aButton = new QPushButton(welcome_page);
        aButton->setObjectName(QString::fromUtf8("aButton"));
        aButton->setGeometry(QRect(270, 540, 211, 50));
        aButton->setMinimumSize(QSize(0, 50));
        stackedWidget->addWidget(welcome_page);
        operator_page = new QWidget();
        operator_page->setObjectName(QString::fromUtf8("operator_page"));
        connect_btn = new QPushButton(operator_page);
        connect_btn->setObjectName(QString::fromUtf8("connect_btn"));
        connect_btn->setGeometry(QRect(520, 320, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Hebrew"));
        connect_btn->setFont(font1);
        ip_label = new QLabel(operator_page);
        ip_label->setObjectName(QString::fromUtf8("ip_label"));
        ip_label->setGeometry(QRect(260, 180, 72, 15));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe Hebrew"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        ip_label->setFont(font2);
        ip_label->setContextMenuPolicy(Qt::PreventContextMenu);
        port_label = new QLabel(operator_page);
        port_label->setObjectName(QString::fromUtf8("port_label"));
        port_label->setGeometry(QRect(260, 240, 71, 16));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe Hebrew"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        port_label->setFont(font3);
        ip_line_edit = new QLineEdit(operator_page);
        ip_line_edit->setObjectName(QString::fromUtf8("ip_line_edit"));
        ip_line_edit->setGeometry(QRect(410, 170, 191, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("ESRI Pipeline US 1"));
        ip_line_edit->setFont(font4);
        ip_line_edit->setFrame(false);
        port_line_edit = new QLineEdit(operator_page);
        port_line_edit->setObjectName(QString::fromUtf8("port_line_edit"));
        port_line_edit->setGeometry(QRect(410, 230, 191, 41));
        port_line_edit->setFrame(false);
        on_time_label = new QLabel(operator_page);
        on_time_label->setObjectName(QString::fromUtf8("on_time_label"));
        on_time_label->setGeometry(QRect(520, 30, 251, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Franklin Gothic Demi Cond"));
        font5.setPointSize(10);
        on_time_label->setFont(font5);
        on_time_label->setFrameShape(QFrame::NoFrame);
        bButton = new QPushButton(operator_page);
        bButton->setObjectName(QString::fromUtf8("bButton"));
        bButton->setGeometry(QRect(680, 560, 121, 41));
        bButton->setFont(font2);
        signin_label = new QLabel(operator_page);
        signin_label->setObjectName(QString::fromUtf8("signin_label"));
        signin_label->setGeometry(QRect(200, 130, 441, 181));
        signin_label->setFrameShape(QFrame::Box);
        signin_label->setLineWidth(2);
        flower_label = new QLabel(operator_page);
        flower_label->setObjectName(QString::fromUtf8("flower_label"));
        flower_label->setGeometry(QRect(0, 0, 801, 601));
        flower_label->setFrameShape(QFrame::NoFrame);
        stackedWidget->addWidget(operator_page);
        flower_label->raise();
        on_time_label->raise();
        bButton->raise();
        signin_label->raise();
        ip_label->raise();
        port_label->raise();
        ip_line_edit->raise();
        port_line_edit->raise();
        connect_btn->raise();
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget_2 = new QStackedWidget(page);
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        stackedWidget_2->setGeometry(QRect(10, 10, 801, 591));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stop_btn = new QPushButton(page_2);
        stop_btn->setObjectName(QString::fromUtf8("stop_btn"));
        stop_btn->setGeometry(QRect(500, 180, 221, 201));
        stop_btn->setFlat(true);
        backward_btn = new QPushButton(page_2);
        backward_btn->setObjectName(QString::fromUtf8("backward_btn"));
        backward_btn->setGeometry(QRect(150, 360, 71, 61));
        backward_btn->setFlat(true);
        left_btn = new QPushButton(page_2);
        left_btn->setObjectName(QString::fromUtf8("left_btn"));
        left_btn->setGeometry(QRect(70, 280, 71, 61));
        left_btn->setFlat(true);
        forward_btn = new QPushButton(page_2);
        forward_btn->setObjectName(QString::fromUtf8("forward_btn"));
        forward_btn->setGeometry(QRect(150, 190, 71, 61));
        forward_btn->setFlat(true);
        right_btn = new QPushButton(page_2);
        right_btn->setObjectName(QString::fromUtf8("right_btn"));
        right_btn->setGeometry(QRect(240, 270, 71, 61));
        right_btn->setFlat(true);
        cButton = new QPushButton(page_2);
        cButton->setObjectName(QString::fromUtf8("cButton"));
        cButton->setGeometry(QRect(300, 400, 161, 61));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Adobe Hebrew"));
        font6.setPointSize(15);
        font6.setBold(true);
        font6.setWeight(75);
        cButton->setFont(font6);
        back_label = new QLabel(page_2);
        back_label->setObjectName(QString::fromUtf8("back_label"));
        back_label->setGeometry(QRect(-9, -6, 801, 601));
        stackedWidget_2->addWidget(page_2);
        back_label->raise();
        stop_btn->raise();
        backward_btn->raise();
        left_btn->raise();
        forward_btn->raise();
        right_btn->raise();
        cButton->raise();
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget_2->addWidget(page_3);
        stackedWidget->addWidget(page);

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        aButton->setText(QApplication::translate("Widget", "\347\202\271   \345\207\273  \350\277\233   \345\205\245", nullptr));
        connect_btn->setText(QApplication::translate("Widget", "\350\277\236 \346\216\245 \345\260\217 \350\275\246", nullptr));
        ip_label->setText(QApplication::translate("Widget", "IP:", nullptr));
        port_label->setText(QApplication::translate("Widget", "PORT:", nullptr));
        on_time_label->setText(QString());
        bButton->setText(QApplication::translate("Widget", "MODE", nullptr));
        signin_label->setText(QString());
        flower_label->setText(QString());
        stop_btn->setText(QString());
        backward_btn->setText(QString());
        left_btn->setText(QString());
        forward_btn->setText(QString());
        right_btn->setText(QString());
        cButton->setText(QApplication::translate("Widget", "ESC", nullptr));
        back_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
