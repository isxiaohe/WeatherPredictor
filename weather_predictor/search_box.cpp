#include "search_box.h"
#include "ui_mywidget.h"
#include <QIcon>
#include <QHBoxLayout>
#include <QLineEdit> // 添加QLineEdit头文件
#include <QDebug>    // 添加QDebug头文件
#include <QListView>
#include <QModelIndex>
#include "mywidget.h"
#include"cityinfo.h"
#include"weathereachday.h"

search_box::search_box(QWidget *parent) : QWidget(parent)
{



    this->setWindowIcon(QIcon("://images/location003.png"));
    this->resize(300, 50);
    this->setWindowTitle("搜索城市名称");

    // 创建搜索按钮
    search_btn = new QPushButton(this);
    search_btn->setFixedSize(36, 32);
    search_btn->setFlat(true);
    search_btn->setText("搜索");

    // 创建编辑框
    search_edit1 = new QLineEdit(this);
    search_edit1->setGeometry(10, 10, 270, 30);
    search_edit1->setPlaceholderText("请输入你关心的城市");
    search_edit1->setTextMargins(0, 0, search_btn->width(), 0);

    //创建联想listview
    listview = new QListView(this);
    QStringList strList;//功能：保存初始化操作数据
    //将数据初始化strList
    strList<<"thu"<<"pku"<<"ruc"<<"zju";
    //创建数据模型
    qlistmodel = new QStringListModel(this);
    //这里我们将为模型设置一个StringList，它自动会导入StringList数据信息
    qlistmodel->setStringList(strList);
    //为listview控件设置数据
    listview->setModel(qlistmodel);
    //setWindowOpacity(0.7);
    listview->close();
    //listview->setWindowOpacity(0.3);

    listview->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
    listview->setAlternatingRowColors(true);

    //------------------------------------------------------
    // 创建水平布局，将搜索按钮添加到布局中
    QHBoxLayout *hlayout = new QHBoxLayout;
    QVBoxLayout *vlayout = new QVBoxLayout;

    hlayout->addStretch();
    hlayout->addWidget(search_btn);
    hlayout->setContentsMargins(0, 0, 0, 0);

    // 将布局应用到编辑框中
    search_edit1->setLayout(hlayout);
    setLayout(vlayout);
    setLayout(hlayout);
    vlayout->addWidget(listview);
    //------------------------------------------------------

    // 连接编辑框的returnPressed信号到槽函数
    connect(search_edit1, &QLineEdit::returnPressed, this, &search_box::on_search_btn_clicked);
    connect(search_btn, &QPushButton::clicked, this, &search_box::on_search_btn_clicked);
    connect(listview, &QListView::clicked, this, &search_box::on_listview_clicked);
}

void search_box::on_search_btn_clicked()
{
    QString program = search_edit1->text();
    search_btn->setText(program);
    qDebug() << search_edit1->text();
    qDebug() << search_edit1->text() << "1111";
    search_edit1->setText(" ");
    search_btn->setText("搜索");
    this->resize(300, 250);
    QStringList s;
    sendCityRequest(&manager, program);
    for(int i=0;i<=6;i++)   s << cityToSelect[i].country + " " + cityToSelect[i].adm1 + " " + cityToSelect[i].adm2 + " " + cityToSelect[i].name;
    QString tmp="以上为【";
    tmp+=program;
    tmp+="】的搜索结果, 选择地区后请点击刷新";
    s<<tmp;
    qlistmodel->setStringList(s);
    listview->show();



    //close();
}

void search_box::on_listview_clicked(const QModelIndex &index)
{
    //把QModelIndex的值用来搜索和刷新
    int x = index.row();
    qDebug() << x;
    //refresh city information
    nowID = cityToSelect[x].id;
    nowCity[0] = cityToSelect[x].name;
    nowCity[1] = cityToSelect[x].adm2;
    nowCity[2] = cityToSelect[x].adm1;
    nowCity[3] = cityToSelect[x].country;
    // QString itemText = qlistmodel->data(index, Qt::DisplayRole).toString();
    // qDebug()<<itemText;
    // emit itemClicked(itemText);
    // nowStr = itemText;
    close();

}

QString search_box::getBoxText()
{
    return nowStr;
}
