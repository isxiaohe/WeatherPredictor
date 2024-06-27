#include "mywidget.h"
#include "./ui_mywidget.h"
#include "search_box.h"

mywidget::mywidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mywidget)
{
    ui->setupUi(this);

    //切换图片
    ui->RefreshBtn->setFlat(true);
    ui->RefreshBtn->installEventFilter(this);
    ui->CityBtn->setFlat(true);
    ui->CityBtn->installEventFilter(this);

    QString displayString;
    QFile file(":/new/prefix1/weather.json.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file!"<<Qt::endl;
    }

    while(!file.atEnd()){
        QByteArray line = file.readLine();
        QString str(line);
        qDebug()<< str;
        displayString.append(str);

    }

    //connect(ui->CityBtn,&QPushButton::clicked(),this,&mywidget::on_CityBtn_clicked());






}

mywidget::~mywidget()
{
    delete ui;
}



bool mywidget::eventFilter(QObject* obj, QEvent* event)
{
    switch(event->type()){
    case QEvent::HoverEnter:
        if(obj == ui->RefreshBtn){//按钮进入
            QFont font1("Microsoft Yahei",11);
            ui->RefreshBtn->setFont(font1);
            ui->RefreshBtn->setText("刷新");

        }
        if(obj == ui->CityBtn){//按钮进入
            QFont font1("Microsoft Yahei",11);
            ui->CityBtn->setFont(font1);
            ui->CityBtn->setText("切换城市");

        }
        break;
    case QEvent::HoverLeave:
        if(obj == ui->RefreshBtn){
            QFont font1("Microsoft Yahei",10);
            ui->RefreshBtn->setFont(font1);
            ui->RefreshBtn->setText("刷新");//按钮离开，恢复默认
        }
        if(obj == ui->CityBtn){
            QFont font1("Microsoft Yahei",10);
            ui->CityBtn->setFont(font1);
            ui->CityBtn->setText("切换城市");//按钮离开，恢复默认
        }

        break;
    case QEvent::MouseButtonPress:
        if(obj == ui->RefreshBtn){//按钮被按下
            QFont font1("Microsoft Yahei",10.5);
            ui->RefreshBtn->setFont(font1);
            ui->RefreshBtn->setText("刷新");
        }
        if(obj == ui->CityBtn){//按钮被按下
            QFont font1("Microsoft Yahei",10.5);
            ui->CityBtn->setFont(font1);
            ui->CityBtn->setText("切换城市");
        }

        break;
    case QEvent::MouseButtonRelease://按钮还原
        if(obj == ui->RefreshBtn){
            QFont font1("Microsoft Yahei",11);
            ui->RefreshBtn->setFont(font1);
            ui->RefreshBtn->setText("刷新");
        }
        if(obj == ui->CityBtn){
            QFont font1("Microsoft Yahei",11);
            ui->CityBtn->setFont(font1);
            ui->CityBtn->setText("切换城市");
        }

        break;
    default:
        break;
    }
    return QWidget::eventFilter(obj,event);
}



void mywidget::paintEvent(QPaintEvent* event)
{
    static int pos=0;
    QString picture[1]={":/new/prefix1/images/WeiMingLake.png"};
    // int n=sizeof(picture)/sizeof(picture[0]);
    //对象
    QPainter* painter=new QPainter(this);
    //画图
    QPixmap pixmap;
    pixmap.load(picture[pos]);
    //pixmap.scaled(300,200);//图片大小
    painter->drawPixmap(0,0,width(),height(),pixmap);//控件大小
    //图片切换

    /*
       pos=!pos;
        pos++;
        if(pos==n){
            pos=0;
        }
    */
    painter->end();
}

void mywidget::on_RefreshBtn_clicked()
{
    qDebug()<<"1";


}


void mywidget::on_CityBtn_clicked()
{
    qDebug()<<"1";
    search_box* sbox1 = new search_box;
    sbox1->move(800,230);
    sbox1->show();


}




void mywidget::on_textBrowser_anchorClicked(const QUrl &arg1)
{

}

