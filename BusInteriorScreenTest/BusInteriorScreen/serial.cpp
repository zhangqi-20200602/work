#include "serial.h"
#include<QTextEncoder>
#include<QTime>
#include<QCoreApplication>
#include "CMath.h"

#define Debug

/***********************构造和析构函数***********************/
Serial::Serial()
{
    mPSerialPort = new QSerialPort;
}

Serial::~Serial()
{

}

/***********************扫描可用串口函数***********************/
QStringList Serial::SerialScan()
{
    QStringList serialStrList;

    /*读串口信息*/
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        mPSerialPort->setPort(info);
        /*判断端口能否以读写方式打开*/
        if(mPSerialPort->open(QIODevice::ReadWrite))
        {
            serialStrList.append(mPSerialPort->portName());
            mPSerialPort->close(); //关闭等待人为开启（通过"打开串口按钮"）
        }
    }

    return serialStrList;
}

/***********************打开串口函数***********************/
bool Serial::SerialOpen(const QString serialName, const QString baudRate)
{    
    mPSerialPort->setPortName(serialName);                          //设置串口名

    if(mPSerialPort->open(QIODevice::ReadWrite))                    //打开串口(以读写方式)
    {
        mPSerialPort->setBaudRate(baudRate.toInt());                //设置波特率(默认为19200)
        mPSerialPort->setDataBits( QSerialPort::Data8 );            //设置数据位(数据位为8位)
        mPSerialPort->setParity( QSerialPort::NoParity );           //设置校验位(无校验位)
        mPSerialPort->setStopBits( QSerialPort::OneStop );          //设置停止位(停止位为1)
        mPSerialPort->setFlowControl( QSerialPort::NoFlowControl ); //设置流控制(无数据流控制)
                                           //readyRead是QSerialPortl类内部的标准信号
        connect(mPSerialPort, &QSerialPort::readyRead, this, &Serial::SerialReadData);
        connect(this, &Serial::ManualTriggerReadSignal, this, &Serial::CopyDataBackup);//我新加的20200610

        return true;
    }

    return false;
}

/***********************关闭串口函数***********************/
void Serial::Serialclose()
{
    mPSerialPort->clear();
    mPSerialPort->close();
}

/***********************从系统缓存发送串口数据函数***********************/
qint64 Serial::SerialSendData(QByteArray sendData)
{
   // m_serialPort->write(encodeURI(sendData));
    mPSerialPort->write(sendData);
    sendSignal();

    return 0;
}

/***********************从系统缓存读取串口数据函数***********************/
//接收到一帧数据，这个函数会被readyRead信号触发多次，自己测试：第一次数据已经全了，第二次是空的。
//网上还有人说会是多次才收全一帧的数据
void Serial::SerialReadData()
//void Serial::MySerialReadData()
{
    #ifdef Debug
        qDebug() << "SerialReadData()函数调用开始";
    #endif

   QTime dieTime = QTime::currentTime().addMSecs(100);

   while(QTime::currentTime()<dieTime)
   {
       QCoreApplication::processEvents(QEventLoop::AllEvents,100);
   }

    mSysReadBuf = mPSerialPort->readAll();    //应该是读完就没有数据了 理由：第二次读时是空

    if(mSysReadBuf.isEmpty()) //没有内容，不触发通知信号
    {
        #ifdef Debug
            qDebug() << "m_readBuf.isEmpty()是空不触发信号";
        #endif
    }
    else
    {
        #ifdef Debug
            qDebug() << "m_readBuf.isEmpty()非空触发信号";
        #endif

        ManualTriggerReadSignal();  //通知备份串口数据
    }

    #ifdef Debug
        qDebug() << "SerialReadData()函数调用结束"<<CMath().ByteArrayToHexString(mSysReadBuf);
    #endif
}

void Serial::CopyDataBackup()
{
    mReadBuf.clear();

    mReadBuf = mSysReadBuf;
    TriggerOtherProgramReadSerialDataSignal();  //通知其他程序可以读取串口数据了
}

/***********************从程序缓存读取串口数据函数***********************/
QByteArray Serial::GetSerialReadBuf()
{
    return mReadBuf;
}

/***********************清除程序缓存串口数据函数***********************/
void Serial::ClearSerialReadBuf()
{
    mReadBuf.clear();
}

QSerialPort *Serial::GetQSerialPort()
{
    return mPSerialPort;
}
