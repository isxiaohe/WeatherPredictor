#include "cityinfo.h"

cityInfo::cityInfo(const QJsonObject& cityObject){
    country=cityObject["country"].toString();
    adm1=cityObject["adm1"].toString();
    adm2=cityObject["adm2"].toString();
    lat=cityObject["lat"].toString();
    lon=cityObject["lon"].toString();
    name=cityObject["name"].toString();
    id=cityObject["id"].toString();
}

void cityInfo::print(){
    qDebug() << "城市名称:" << name;
    qDebug() << "城市ID:" << id;
    qDebug() << "纬度:" << lat;
    qDebug() << "经度:" << lon;
    qDebug() << "行政区:" << adm2;
    qDebug() << "省:" << adm1;
    qDebug() << "国家:" << country;
    qDebug()<<"-------------";
}

void updateCity(const QJsonDocument& data){
    QJsonObject rootObject=data.object();

    QJsonArray cityArray=rootObject["location"].toArray();

    if(cityArray.size()<10) numCity=cityArray.size();
    else numCity=10;

    if(numCity==0)  return;

    int i=0;
    for(const QJsonValue& value:cityArray){
        if(i>11)    break;
        QJsonObject cityObject=value.toObject();

        cityToSelect[i]=cityInfo(cityObject);
        i++;
    }

    return ;
}

void sendCityRequest(QNetworkAccessManager *manager,const QString& name){
    QString urlString="https://geoapi.qweather.com/v2/city/lookup?location=";
    urlString+=name;
    urlString+="&key=298da58b269e4ccbbf414fa919d9c7c2";
    QUrl url(urlString);
    QNetworkRequest request(url);

    request.setRawHeader("Accept_Encoding","gzip");

    QNetworkReply *reply=manager->get(request);

    QEventLoop loop;

    QObject::connect(reply,&QNetworkReply::finished,[reply,manager](){
        if(reply->error() == QNetworkReply::NoError){
            QByteArray response=reply->readAll();


            //            QByteArray decompressedResponse;
            //            if(reply->rawHeader("Content-Encoding")=="gzip"){
            //
            //                decompressedResponse=decompressGzip(response);
            //
            //            }else{
            //                decompressedResponse=response;
            //            }

            QByteArray decompressedResponse=response;

            QJsonParseError jsonError;
            QJsonDocument jsonResponse=QJsonDocument::fromJson(decompressedResponse,&jsonError);

            if(!jsonResponse.isNull()){

                updateCity(jsonResponse);
//                if(numCity!=0) city=cityToSelect[0].name;

                //sendWeatherRequest(manager,cityToSelect[0].id);

                }else{
                qDebug()<<"Failed to parse JSON.";
            }
        }else{
            qDebug()<<"Error:"<<reply->errorString();
        }
        reply->deleteLater();
    });

    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
}


int numCity=0;
cityInfo cityToSelect[12];
QString nowID = "101110101";
QNetworkAccessManager manager;
QString nowCity[4] = {"西安", "西安", "陕西", "中国"};
