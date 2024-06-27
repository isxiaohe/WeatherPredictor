#include "search_box.h"
#include <QIcon>
#include <QHBoxLayout>
#include <QString>
#include <QPushButton>

search_box::search_box(QWidget *parent) : QWidget(parent)
{
    this->setWindowIcon(QIcon("://images/location003.png"));
    this->resize(300, 60);

    this->setWindowTitle("搜索城市名称");

    //方法一

    //搜索按钮
    search_btn = new QPushButton(this);
    search_btn->setFixedSize(32, 32);//设置固定大小
    search_btn->setFlat(true);//去掉按钮边框
    //search_btn->setToolTip("搜索");//设置鼠标悬浮的提示
    search_btn->setText("搜索");
    //search_btn->setStyleSheet("QPushButton {background-image: url(:/new/prefix1/loc00)}");//设置样式表

    //connect(search_btn, SIGNAL(returnPressed()),this,SLOT(on_search_btn_clicked()));
    connect(search_btn, &QPushButton::clicked, [&](){
        qDebug()<<search_edit1->text();
        close();
    });

    //第一个编辑框
    search_edit1 = new QLineEdit(this);
    search_edit1->setGeometry(10, 10, 250, 30);//设置编辑框位置大小
    search_edit1->setPlaceholderText("请输入你关心的城市");//设置编辑框没有输入内容时的友好提示
    search_edit1->setTextMargins(0, 0, search_btn->width(), 0);//设置编辑框文字的边距，防止文字写到按钮上 参数：左 上 右 下

    //水平布局
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addStretch();
    hlayout->addWidget(search_btn);
    hlayout->setContentsMargins(0, 0, 0, 0);//设置布局的边距

    //第一个编辑框添加布局（将按钮放在编辑框上）
    search_edit1->setLayout(hlayout);


}

void search_box::on_search_btn_clicked()
{
    QString program =search_edit1->text();
    search_btn->setText(program);
    close();
}
