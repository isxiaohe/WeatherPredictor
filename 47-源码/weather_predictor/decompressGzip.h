#ifndef DECOMPRESSGZIP_H
#define DECOMPRESSGZIP_H

#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QByteArray>
#include<zlib.h>

//解压gzip，返回天气的json文件，如果失败，返回空数组QByteArray()
QByteArray decompressGzip(const QByteArray &data);

#endif // DECOMPRESSGZIP_H
