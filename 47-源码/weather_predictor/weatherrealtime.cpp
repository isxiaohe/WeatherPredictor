#include "weatherrealtime.h"

weatherRealTime::weatherRealTime(const QJsonObject& weatherObject){
    obsTime = weatherObject["obsTime"].toString();
    temp = weatherObject["temp"].toString();
    feelsLike = weatherObject["feelsLike"].toString();
    text = weatherObject["text"].toString();
    windDir = weatherObject["windDir"].toString();
    windScale = weatherObject["windScale"].toString();
    windSpeed = weatherObject["windSpeed"].toString();
    humudity = weatherObject["humudity"].toString();
    precip = weatherObject["precip"].toString();
    vis = weatherObject["vis"].toString();
    pressure = weatherObject["pressure"].toString();
    icon = weatherObject["icon"].toString();
}

void weatherRealTime::print(){
    qDebug() << "更新时间:" << obsTime;
    qDebug() << "天气:" << text;
    qDebug() << "气温:" << temp;
    qDebug() << "体感温度:" << feelsLike;
    qDebug() << "风向:" << windDir;
    qDebug() << "icon:" << icon;
    qDebug() << "-------------------";
}

void updateWeatherRealTime(const QJsonDocument& data){
    //获取根对象
    QJsonObject rootObject=data.object();

    //获取now
    QJsonObject weatherObject=rootObject["now"].toObject();

    weatherRealTimeObj = weatherRealTime(weatherObject);

    return ;
}

void sendWeatherRealTimeRequest(QNetworkAccessManager *manager,const QString& locId){ //locId为城市的id，需要它来发送天气请求
    QString urlString="https://devapi.qweather.com/v7/weather/now?location=";
    urlString+=locId;
    urlString+="&key=298da58b269e4ccbbf414fa919d9c7c2";
    QUrl url(urlString);
    QNetworkRequest request(url);

    request.setRawHeader("Accept-Encoding","gzip");

    QNetworkReply *reply=manager->get(request);

    QEventLoop loop;
    QObject::connect(reply,&QNetworkReply::finished,[reply](){
        if(reply->error() == QNetworkReply::NoError){
            QByteArray response=reply->readAll();

            QByteArray decompressedResponse=response;
            if(reply->rawHeader("Content-Encoding")=="gzip"){
                decompressedResponse=decompressGzip(response);
            }else{
                decompressedResponse=response;
            }


            // 打印解压缩后的数据
            // qDebug() << "Decompressed Response:" << decompressedResponse;

            QJsonParseError jsonError;
            QJsonDocument jsonResponse=QJsonDocument::fromJson(decompressedResponse,&jsonError);

            if(!jsonResponse.isNull()){

                updateWeatherRealTime(jsonResponse);

                //                for(int i=0;i<=6;i++)   weatherForSevenDay[i].print();

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

weatherRealTime weatherRealTimeObj;
