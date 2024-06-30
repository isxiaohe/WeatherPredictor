#ifndef WEATHERREALTIME_H
#define WEATHERREALTIME_H

#include<QApplication>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkReply>
#include<QUrl>
#include<QDebug>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QByteArray>
#include<QEventLoop>
#include"decompressGzip.h"

class weatherRealTime
{
public:
    QString obsTime;//数据观测事件
    QString temp;//温度，单位为摄氏度
    QString feelsLike;//体感温度，单位为摄氏度
    QString text;//天气的文字描述，如晴、多云
    QString windDir;//风向，如东南风
    QString wind360;//风向360°角，如123
    QString windScale;//风力等级
    QString windSpeed;//风速，单位为公里/小时
    QString humudity;//相对湿度，百分比数值，如72
    QString precip;//当前小时累计降水量，单位为毫米，
    QString pressure;//大气压强，单位为百帕
    QString vis;//能见度，单位为公里
    QString icon;//天气状态的图标代码

    weatherRealTime(){}
    weatherRealTime(const QJsonObject& weatherObject);

    void print();
};

void updateWeatherRealTime(const QJsonDocument& data);

void sendWeatherRealTimeRequest(QNetworkAccessManager *manager,const QString& locId="101010100");

extern weatherRealTime weatherRealTimeObj;

#endif // WEATHERREALTIME_H
