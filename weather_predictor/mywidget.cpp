#include "mywidget.h"
#include "./ui_mywidget.h"
#include"weathereachday.h"
#include "cityinfo.h"
#include"search_box.h"
#include<QTimer>
#include<QDateTime>
#include"weatherrealtime.h"
#include <QPaintEvent>

mywidget::mywidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mywidget)
{
    ui->setupUi(this);
    //改变按钮透明度
    setWindowTitle("战损高坚果的天气信息系统");
    ui->MainCityBtn->setFlat(true);
    ui->MainCityBtn->setStyleSheet( "color:rgb(250, 250, 250);font-weight: bold;");
    ui->ShowTemperatureButton->setStyleSheet( "color:rgb(250, 250, 250);font-weight: bold;");
    ui->ShowTimeButton->setFlat(true);
    ui->ShowTimeButton->setStyleSheet( "color:rgb(250, 250, 250);");
    ui->ShowTemperatureButton->setFlat(true);
    ui->minimaxT->setFlat(true);
    ui->minimaxT->setStyleSheet( "color:rgb(250, 250, 250);font-weight: bold;");
    ui->RefreshBtn->setStyleSheet("background-color: rgba(173,173,173,40); color:rgb(250, 250, 250);border-radius: 10px;");
    ui->changeBack->setStyleSheet("background-color: rgba(173,173,173,40); color:rgb(250, 250, 250);border-radius: 10px;");
    ui->CityBtn->setStyleSheet("background-color: rgba(173,173,173,40); color:rgb(250, 250, 250);border-radius: 10px;");
    ui->NowRegion->setStyleSheet( "color:rgb(250, 250, 250);");
    // ui->Humidity->setStyleSheet( "color:rgb(250, 250, 250);");
    // ui->UV->setStyleSheet( "color:rgb(250, 250, 250);");
    // ui->WindDir->setStyleSheet( "color:rgb(250, 250, 250);");
    // ui->WindScale->setStyleSheet( "color:rgb(250, 250, 250);");
    ui->weatherLabel->setStyleSheet("color:rgb(250, 250, 250);font-weight: bold");

    ui->MainCityBtn->setFont(QFont("", 30));
    ui->ShowTemperatureButton->setFont(QFont("", 25));
    ui->weatherLabel->setFont(QFont("", 15));

    ui->RefreshBtn->installEventFilter(this);
    ui->CityBtn->installEventFilter(this);
    ui->MainCityBtn->installEventFilter(this);
    ui->ShowTimeButton->installEventFilter(this);
    //ui->OtherDayDirectLabel->installEventFilter(this);
    ui->ShowTemperatureButton->installEventFilter(this);
    ui->DetailWidget->installEventFilter(this);



    ui->RefreshBtn->show();
    ui->CityBtn->show();
    timer = new QTimer;
    connect(timer,&QTimer::timeout,this,&mywidget::showTime);   // 信号连接 每一秒执行一次槽函数
    timer->start(1);
    this->resize(630, 380);//widget size
    //setWindowOpacity(0.3);
    // box = new search_box;
    // connect(box, SIGNAL(itemClicked(QString)), this, SLOT(mywidget::on_RefreshBtn_clicked()));
}

void mywidget::showTime()
{
    QString string;
    QDateTime Timedata = QDateTime::currentDateTime();   //  获取当前时间
    string = Timedata.toString("yyyy-MM-dd hh:mm:ss");   //  设置显示格式
    ui->ShowTimeButton->setFlat(true);
    ui->ShowTimeButton->setText(string);  // 设置标签内容
    // ui->MainCityBtn->setText(box->getBoxText());


}

mywidget::~mywidget()
{
    delete ui;
}

void mywidget::on_RefreshBtn_clicked()
{
    sendWeatherRequest(&manager, nowID);
    sendWeatherRealTimeRequest(&manager, nowID);
    ui->MainCityBtn->setText(nowCity[0]);
    ui->ShowTemperatureButton->setText(weatherRealTimeObj.temp + "℃");
    // ui->UV->setText("UV: " + weatherForSevenDay[0].uvIndex);
    // ui->Humidity->setText("相对湿度: " + weatherRealTimeObj.humudity);
    // ui->WindDir->setText("风向: " + weatherRealTimeObj.windDir);
    // ui->WindScale->setText("风力等级: " + weatherRealTimeObj.windScale);
    ui->minimaxT->setText("最高: " + weatherForSevenDay[0].tempMax + "℃ 最低: " +  weatherForSevenDay[0].tempMin + "℃");
    ui->NowRegion->setText(nowCity[3] + ", " + nowCity[2] + ", " + nowCity[1]);
    ui->weatherLabel->setText(weatherRealTimeObj.text);
    pathWeatherIcon = ":new/icons/icons/" + weatherRealTimeObj.icon + ".png";
    qDebug() << "now icon:" << weatherRealTimeObj.icon;
    QPixmap iconNow(pathWeatherIcon);
    ui->weatherIcon->setPixmap(iconNow);
    qDebug() << QDir::currentPath();
    MyFollow1->updateText();
}


void mywidget::on_CityBtn_clicked(bool checked)
{
    qDebug()<<"1";
    box = new search_box;
    box->move(800,230);
    if(!box->isVisible()){
        box->show();
    }


}


bool mywidget::eventFilter(QObject* obj, QEvent* event)
{
    switch(event->type()){

    case QEvent::MouseButtonPress:
        if(obj == ui->RefreshBtn){//按钮被按下
            ui->RefreshBtn->setFont(QFont("", 10));
            ui->RefreshBtn->setText("刷新");
        }
        if(obj == ui->CityBtn){//按钮被按下
            ui->CityBtn->setFont(QFont("", 10));
            ui->CityBtn->setText("切换城市");
        }
        if(obj == ui->MainCityBtn){//按钮被按下
            QFont font1("KaiTi",27);
            ui->MainCityBtn->setFont(font1);

        }
        // if(obj == ui->ShowTimeButton){//按钮被按下

        //     //ui->Locationlabel->move(event->pos);
        //     ui->OtherDayDirectLabel->close();

        // }
        // if(obj == ui->ShowTemperatureButton){//按钮被按下

        //     //ui->Locationlabel->move(event->pos);
        //     //ui->OtherDayDirectLabel->close();

        // }

        break;
    case QEvent::MouseButtonRelease://按钮还原
        if(obj == ui->RefreshBtn){
            QFont font1("Microsoft Yahei",13);
            ui->RefreshBtn->setFont(font1);
            ui->RefreshBtn->setText("刷新");
        }
        if(obj == ui->CityBtn){
            QFont font1("Microsoft Yahei",13);
            ui->CityBtn->setFont(font1);
            ui->CityBtn->setText("切换城市");
        }
        if(obj == ui->MainCityBtn){
            QFont font1("KaiTi",30);
            ui->MainCityBtn->setFont(font1);
            //ui->Locationlabel->move(MouseEvent->x(),MouseEvent->y());

        }
        // if(obj == ui->ShowTimeButton){//按钮还原

        //     //ui->Locationlabel->move(event->pos);
        //     ui->OtherDayDirectLabel->show();

        // }
        // if(obj == ui->ShowTemperatureButton){//按钮还原

        //     //ui->Locationlabel->move(event->pos);
        //     ui->DetailWidget->show();


        //     /*search_box* sbox1 = new search_box;
        //     sbox1->move(800,230);
        //     sbox1->show();*/




        // }

        break;
    default:
        break;
    }
    return QObject::eventFilter(obj, event);
}

void mywidget::paintEvent(QPaintEvent* event)
{
    // int n=sizeof(picture)/sizeof(picture[0]);
    //对象
    QPainter* painter=new QPainter(this);
    //画图
    QPixmap pixmap;
    pixmap.load(pathMywidgetBackground);
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

void mywidget::on_changeBack_clicked()
{
    indexBack += 1;
    indexBack %= 4;
    switch(indexBack){
        case 0:
            pathMywidgetBackground = ":new/images/images/back_ground1.jpg";
            break;
        case 1:
            pathMywidgetBackground = ":new/images/images/back_ground3.jpg";
            break;
        case 2:
            pathMywidgetBackground = ":new/images/images/back_ground2.jpeg";
            break;
        case 3:
            pathMywidgetBackground = ":new/images/images/back_ground4.png";
            break;
    }
        update();
}

// void mywidget::receivedData(QString Data){
//     ui->MainCityBtn->setText(Data);
// }
QString pathMywidgetBackground = ":new/images/images/back_ground4.png";
QString pathWeatherIcon;
int indexBack = 0;



void mywidget::on_ShowTimeButton_clicked()
{
    MyFollow1->show();
}


void mywidget::on_ShowTemperatureButton_clicked()
{
    MyFollow2->updateText1();
    MyFollow2->show();
}

