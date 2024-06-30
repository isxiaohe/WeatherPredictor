#include "mywidget.h"
#include "cityinfo.h"
#include "weathereachday.h"
#include <QApplication>
#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QUrl>
#include<QDebug>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QByteArray>
#include<zlib.h>
#include"weatherrealtime.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        mywidget w;
        w.show();


    // sendCityRequest(&manager);
    // if(numCity!=0)
    //     for(int i=0;i<=numCity-1;i++)  cityToSelect[i].print();

    // sendWeatherRequest(&manager);
    // for(int i=0;i<=6;i++)   weatherForSevenDay[i].print();

    // sendWeatherRealTimeRequest(&manager);
    // weatherRealTimeObj.print();

    return a.exec();
}
