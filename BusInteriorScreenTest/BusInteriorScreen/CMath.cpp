#include "CMath.h"
#include <QMessageBox>
#include<QTextEncoder>
#include <QDebug>

//#define Debug

/***********************构造和析构函数***********************/
CMath::CMath()
{

}

CMath::~CMath()
{

}

//异或码校验
unsigned char CMath::getXORresult(QByteArray ByteArray)
{
    unsigned char relt = 0;

    for (int i = 0 ; i < ByteArray.size(); ++i)
    {
        #ifdef Debug
            qDebug() << "getXORresult()内容是：" << ByteArray[i];
        #endif

        relt ^=  ByteArray[i];
    }

    return relt;
}

//转成其他的数据
QString CMath::ByteArrayToHexString(QByteArray data)
{
    QString ret(data.toHex().toUpper());
    int len = ret.length()/2;

    #ifdef Debug
        qDebug() << "ByteArrayToHexString() len =" << len;
    #endif

    for(int i=1;i<len;i++)
    {       
        #ifdef Debug
            qDebug() << "ByteArrayToHexString() i =" << i;
        #endif
        ret.insert(2*i+i-1," ");
    }

    return ret;
}

QByteArray CMath::hexStringToByteArray(QString HexString)
{
    bool ok;
    QByteArray ret;
    HexString = HexString.trimmed();
    HexString = HexString.simplified();
    QStringList sl = HexString.split(" ");

    foreach (QString s, sl)
    {
        if(!s.isEmpty())
        {
            char c = static_cast<char>(s.toInt(&ok, 16) & 0xFF);
            if(ok)
            {
                ret.append(c);
            }
            else
            {
                qDebug()<<"非法的16进制字符："<<s;
                //QMessageBox::warning(nullptr, tr("错误："), QString("非法的16进制字符: \"%1\"").arg(s));
            }
        }
    }

    return ret;
}

QByteArray CMath::encodeURI(QString str)
{
    QByteArray array;
    QTextCodec *codec=QTextCodec::codecForName("GBK");
    QByteArray tmpArray;
    tmpArray = codec->fromUnicode(str);
    for(int i=0,size = tmpArray.length();i<size;i++){
        char ch = tmpArray.at(i);
            uchar low = ch & 0xff;
            char c[3];
            sprintf(c,"%02x",low);//转换的函数
            array.append("").append(c);
    }

    return array;
}

QByteArray CMath::gb2312ToUtf8(QString strGb2312)
{
    printf("@@@ gb2312 str is:%s\n",strGb2312.toLocal8Bit().data());
    QTextCodec* utf8Codec= QTextCodec::codecForName("utf-8");
    QTextCodec* gb2312Codec = QTextCodec::codecForName("gb2312");

    QString strUnicode= gb2312Codec->toUnicode(strGb2312.toLocal8Bit().data());
    QByteArray ByteUtf8= utf8Codec->fromUnicode(strUnicode);

    char *utf8code = ByteUtf8.data();
    printf("@@@ Utf8  strGb2312toUtf8:%s\n",utf8code);
}
