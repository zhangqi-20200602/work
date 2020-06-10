#ifndef CMATH_H
#define CMATH_H


#include <QByteArray>
#include <QString>

class CMath
{
public:
    explicit CMath();
    virtual ~CMath();

public:
    unsigned char getXORresult(QByteArray ByteArray);
    QString    ByteArrayToHexString(QByteArray data);
    QByteArray hexStringToByteArray(QString HexString);
    QByteArray encodeURI(QString str);
    QByteArray gb2312ToUtf8(QString strGb2312);
};

#endif // CMATH_H
