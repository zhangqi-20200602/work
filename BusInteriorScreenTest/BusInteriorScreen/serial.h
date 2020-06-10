#ifndef SERIAL_H
#define SERIAL_H
#include<QTimer>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

class Serial:public QObject // 要继承QObject，才能使用 connect() 函数
{
    Q_OBJECT

public:
    Serial();
    ~Serial();

public:
    QStringList SerialScan();                       //扫描可用串口
    bool SerialOpen(const QString serialName, const QString baudRate); //打开选择的串口
    void Serialclose();                             //关闭串口
    qint64 SerialSendData(QByteArray  sendData);    //发送数据   
    QByteArray GetSerialReadBuf();                  //获取读取的串口数据的备份区mReadBuf
    void ClearSerialReadBuf();                      //清除读取的串口数据的备份区mReadBuf    没有使用
    QSerialPort* GetQSerialPort(void);              //返回Serial类内部指向QSerialPort对象的指针 mPSerialPort

signals:
    void ManualTriggerReadSignal();                 //当读取到的串口数据mSysReadBuf非空时触发这个信号，复制到备份区 内部使用
    void TriggerOtherProgramReadSerialDataSignal(); //通知其他位置（类、函数）去读取串口的数据      内部触发,外部connect
    void sendSignal();     //内部触发,外部connect     //串口数据发送时，触发这个信号去显示或保存或其他需要发送数据的位置

public slots:
    void SerialReadData();                          //读取系统串口数据到mSysReadBuf    内部使用
    //void MySerialReadData();                      //读取系统串口数据到mSysReadBuf    内部使用
    void CopyDataBackup();                          //mSysReadBuf数据复制到mReadBuf  内部使用

private:
    QSerialPort  *mPSerialPort;  //实例化一个指向串口的指针，可以用于访问串口
    QByteArray    mSysReadBuf;   //从系统缓冲区读取的数据存储到此处
    QByteArray    mReadBuf;      //把mSysReadBuf的数据存储到此处  目的：解决readyRead信号多次触发带来的问题
    //QTimer       *m_timer;
};

#endif // SERIAL_H
