#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMap>
#include "CLog.h"
#include "serial.h"
#include "CMath.h"
#include <QByteArray>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
/***************************构造析构函数***************************/
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private:
/************与海信协议有关的变量*************/
    const unsigned char HAIXIN_BEGIN = 0x7E;
    const unsigned char HAIXIN_END   = 0x7F;
    const unsigned char UPDATE_BEGIN = 0x5E;

    const unsigned char FRONTSCEENADDR  = 0x10;
    const unsigned char BACKSCEENADDR   = 0x11;
    const unsigned char FRONTROADADDR   = 0x30;
    const unsigned char SIDEROADADDR    = 0x31;
    const unsigned char BACKROADADDR    = 0x32;
    const unsigned char FRONTSECADDR    = 0x20;
    const unsigned char BACKSECADDR     = 0x21;
    const unsigned char STOPANNOUNCERADDR   = 0x02;
    const unsigned char TERMINALADDR        = 0x01;

/************与显示界面有关的private变量*************/
private:         
    /***********公交车内设备相关变量****************/
    const unsigned char BusInteriorDeviceSum = 8;
    enum BusInteriorDeviceOrder
    {
        DEVICE_FRONTSCEEN = 0,
        DEVICE_BACKSCEEN,
        DEVICE_FRONTROAD,
        DEVICE_SIDEROAD,
        DEVICE_BACKROAD,
        DEVICE_FRONTSEC,
        DEVICE_BACKSEC,
        DEVICE_STOP_ANNOUNCER,
    };
    /***********前内屏相关变量****************/
    const unsigned char FrontScreenFunSum = 8;
    enum FrontScreenFunOrder
    {
        FRONTSCEEN_SelfCheck = 0,
        FRONTSCEEN_SetTime,
        FRONTSCEEN_SetStopName,
        FRONTSCEEN_SetFirstLast,
        FRONTSCEEN_SetPropagandaLanguage,
        FRONTSCEEN_PlayStopName,
        FRONTSCEEN_PlayNumProLanguage,
        FRONTSCEEN_PlayItemProLanguage,
    };

    /***********前内屏相关变量****************/
    const unsigned char BackScreenFunSum = 8;
    enum BackScreenFunOrder
    {
        BACKSCEEN_SelfCheck = 0,
        BACKSCEEN_SetTime,
        BACKSCEEN_SetStopName,
        BACKSCEEN_SetFirstLast,
        BACKSCEEN_SetPropagandaLanguage,
        BACKSCEEN_PlayStopName,
        BACKSCEEN_PlayNumProLanguage,
        BACKSCEEN_PlayItemProLanguage,
    };

/************private类型函数*************/
private:
    /***************************初始化串口的函数***************************/
    void InitSerial(void);
    /***************************初始化数学计算对象CMath的函数***************************/
    void InitMathFunction(void);
    /***************************初始化写日志的文件路径和对象的函数***************************/
    void InitLogFileName(void);
    /***************************初始化窗口的大小位置标题等属性的函数***************************/
    void InitMyWidgetAttr(void);
    /***************************软件刚打开时初始化窗口上显示的子窗口内容***************************/
    void InitDisplayInterface(void);
    /***************************初始化各种信号和槽关系的函数***************************/
    void InitSignalConnect(void);
    /***************************所有设备组帧准备发送***************************/
    void OrganizeHaiXinSendFrame(Widget::BusInteriorDeviceOrder DeviceType,
                                 unsigned char PackageType, unsigned short PackageLen, QByteArray Data);
    /***************************发送数据的显示和保存函数***************************/
    void HaiXinSendFrameHandleDispalyAndSave(void);
    /***************************接收到串口数据后的处理函数***************************/
    void HaiXinReceiveFrameHandleDispalyAndSave(void);

    /***************1-车内设备选择功能***************/
    /***************************当有车内设备的radio按钮被toggled时需要显示相关界面的函数***************************/
    void BusInteriorDeviceChosoeDisplay(unsigned char DeviceType, bool DisplaySwitch);
    /***************************关闭车内所有设备功能相关的显示界面和状态位***************************/
    void BusInteriorDeviceChosoeCloseAllStatusDisplay(void);

    /***************1-前内屏功能***************/
    void FrontScreenFunctionChosoeDisplay(unsigned char FrontScreenFuncType, bool DisplaySwitch);
    void FrontScreenFunctionChosoeCloseAllStatusDisplay(void);
    /***************2-后内屏功能***************/

    /***************3-前路牌功能***************/

    /***************4-侧路牌功能***************/

    /***************5-后路牌功能***************/

    /***************6-前站节牌功能***************/

    /***************7-后站节牌功能***************/

    /***************8-报站器功能***************/

/************public slots函数*************/
public slots:
    /***************************当有车内设备的radio按钮被toggled时触发的槽函数***************************/
    void BusInteriorDeviceChosoeHandle(void);
    /***************************点击串口打开按钮时的槽函数***************************/
    void SerialSwitchClick(void);
    /***************************点击串口发送按钮时的槽函数***************************/
    void SerialSendClick(void);
    /***************************当车内屏功能的radio被选中时的槽函数***************************/
    void FrontScreenFunctionChosoeHandle(void);

/************与其他类有关的private变量*************/
private:
    Ui::Widget          *ui;            //指向ui界面对象的指针
    CMath               *mPMath;        //数学计算时用到的对象
    CLog                *mPLog;         //写日志时用的对象
    QMap<int, QString>  mLogFilePath;   //写日志时用的文件路径名
    bool                mBusInteriorDeviceStatus[8];//记录设备按钮被选中的状态
    Serial              *mSerial;       //指向自定义串口类对象的指针
    bool                mSerialStatus;  //记录串口是打开还是关闭状态
    bool                mFrontScreenFunctionStatus[8];//记录前内屏功能被选中的状态
    QByteArray          mSaveSerialSendData;
};

#endif // MYWIDGET_H
