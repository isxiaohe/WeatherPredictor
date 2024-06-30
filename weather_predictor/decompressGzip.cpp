#include"decompressGzip.h"

//解压gzip，返回天气的json文件，如果失败，返回空数组QByteArray()
QByteArray decompressGzip(const QByteArray &data){
    if(data.size()<4){
        return QByteArray();
    }

    QByteArray result;
    z_stream strm;
    memset(&strm,0,sizeof(z_stream));

    if(inflateInit2(&strm,16+MAX_WBITS)!=Z_OK){
        return QByteArray();
    }

    strm.next_in=(Bytef *)data.data();
    strm.avail_in=data.size();

    int ret;
    char buffer[32768]={0};

    do{
        strm.next_out=reinterpret_cast<Bytef*>(buffer);
        strm.avail_out=sizeof(buffer);
        ret=inflate(&strm,Z_NO_FLUSH);

        if(result.size()<strm.total_out){
            result.append(buffer,strm.total_out-result.size());
        }
    }while(ret==Z_OK);

    inflateEnd(&strm);
    if(ret!=Z_STREAM_END){
        return QByteArray();
    }

    return result;
}
