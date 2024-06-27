#ifndef WEATHEREACHDAY_H
#define WEATHEREACHDAY_H

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
#include"decompressGzip.h"

class weatherEachDay
{
public:
    QString date;
    QString weatherDay;//白天天气
    QString weatherNight;//晚上天气
    QString tempMin;//最低温度
    QString tempMax;//最高温度
    QString windDirDay;//白天风向，“东南”
    QString windScaleDay;//白天风力等级
    QString windSpeedDay;//白天风速，公里/小时
    QString windDirNight;//晚上风向
    QString windScaleNight;//晚上风力等级
    QString windSpeedNight;//晚上风速
    QString sunRise;//日出时间
    QString sunSet;//日落时间
    int vis;//能见度，公里
    int cloud;//云量，百分比数值，可能为空
    int uvIndex;//紫外线强度指数

    weatherEachDay(){}
    weatherEachDay(const QJsonObject& dayObject);

    void print();
};

//基于数据更新weatherForSevenDay[],在sendWeatherRequest函数中被调用
void updateWeather(const QJsonDocument& data);

//利用位置的id发送天气请求，此时更新weatherForSevenDay[]
void sendWeatherRequest(QNetworkAccessManager *manager,const QString& locId="101010100");

extern weatherEachDay weatherForSevenDay[8];
extern QString updateTime;

#endif // WEATHEREACHDAY_H
