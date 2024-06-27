#ifndef CITYINFO_H
#define CITYINFO_H

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

class cityInfo
{
public:
    QString country;
    QString adm1; //一级行政区划，如“江西省” “北京市”
    QString adm2; //二级行政区划，如“上饶” “抚州”（地级市） “北京”
    QString lat; //纬度
    QString lon; //经度
    QString name; //地名，如“鄱阳”(县） “海淀”
    QString id;//城市id
    cityInfo(){}
    cityInfo(const QJsonObject& cityObject);//根据Json文件的一部分生成城市信息

    void print();//用于调试


    };

//基于数据更新cityToSelect[]，在sendCityRequest函数中被调用
void updateCity(const QJsonDocument& data);

//利用输入的城市名发送城市请求，此时更新cityToSelect[]
void sendCityRequest(QNetworkAccessManager *manager,const QString& name="%E8%A5%BF%E5%AE%89");


extern int numCity;//备选城市的数量,最大取10 可能为0，记得判断
extern cityInfo cityToSelect[12];//cityToSelect[0]为第一个备选城市

#endif // CITYINFO_H
