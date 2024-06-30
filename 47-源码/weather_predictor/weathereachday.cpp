#include "weathereachday.h"

weatherEachDay::weatherEachDay(const QJsonObject& dayObject){
    date = dayObject["fxDate"].toString();
    weatherDay = dayObject["textDay"].toString();
    weatherNight = dayObject["textNight"].toString();
    tempMax = dayObject["tempMax"].toString();
    tempMin = dayObject["tempMin"].toString();
    windDirDay = dayObject["windDirDay"].toString();
    windScaleDay = dayObject["windScaleDay"].toString();
    windSpeedDay = dayObject["windSpeedDay"].toString();
    windDirNight = dayObject["windDirNight"].toString();
    windScaleNight = dayObject["windScaleNight"].toString();
    windSpeedNight = dayObject["windSpeedNight"].toString();
    sunRise = dayObject["sunRise"].toString();
    sunSet = dayObject["sunSet"].toString();
    vis = dayObject["vis"].toString();
    cloud = dayObject["cloud"].toString();
    uvIndex = dayObject["uvIndex"].toString();

}

void weatherEachDay::print(){
    qDebug() << "日期:" << date;
    qDebug() << "白天天气:" << weatherDay;
    qDebug() << "夜晚天气:" << weatherNight;
    qDebug() << "最高温度:" << tempMax;
    qDebug() << "最低温度:" << tempMin;
    qDebug() << "白天风向:" << windDirDay;
    qDebug() << "夜晚风向:" << windDirNight;
    qDebug() << "-------------------";
}

//基于数据更新weatherForSevenDay[],在sendWeatherRequest函数中被调用
void updateWeather(const QJsonDocument& data){

    //获取根对象
    QJsonObject rootObject=data.object();

    //获取daily数组
    QJsonArray dailyArray=rootObject["daily"].toArray();

    int i=0;
    for(const QJsonValue& value:dailyArray){
        QJsonObject dayObject=value.toObject();

        weatherForSevenDay[i]=weatherEachDay(dayObject);
        i++;
    }

    return ;
}

//利用位置的id发送天气请求，此时更新weatherForSevenDay[]
void sendWeatherRequest(QNetworkAccessManager *manager,const QString& locId){ //locId为城市的id，需要它来发送天气请求
    QString urlString="https://devapi.qweather.com/v7/weather/7d?location=";
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
            //qDebug() << "Decompressed Response:" << decompressedResponse;

            QJsonParseError jsonError;
            QJsonDocument jsonResponse=QJsonDocument::fromJson(decompressedResponse,&jsonError);

            if(!jsonResponse.isNull()){

                updateWeather(jsonResponse);

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

weatherEachDay weatherForSevenDay[8];
QString updateTime;
