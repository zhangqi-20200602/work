#include "MyWidget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <QDateTime>
#include <QMessageBox>

#define Debug

/***************************构造析构函数***************************/
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    for(unsigned int i = 0; i < 8; i++)
    {

        mBusInteriorDeviceStatus[i] = false;
        mFrontScreenFunctionStatus[i] = false;
    }

    mSerialStatus = false;

    InitSerial();
    InitMathFunction();     //数学计算用的对象
    InitLogFileName();      //Log日志文件路径和对象初始化

    InitMyWidgetAttr();     //窗口标题大小位置等初始化
    InitDisplayInterface(); //软件刚打开时初始化窗口上显示的子窗口内容
    InitSignalConnect();    //各种信号和槽关系的初始化
}

Widget::~Widget()
{
    delete ui;

    if(mPLog != NULL)
    {
        delete mPLog;
        mPLog = NULL;
    }

    if(mPMath != NULL)
    {
        delete mPMath;
        mPMath = NULL;
    }
}

void Widget::InitSerial(void)
{
    mSerial = new Serial();
    QStringList SerailNameList = mSerial->SerialScan();

    for (int i = 0; i < SerailNameList.size(); i++)
    {
        //添加所有的串口名字
        ui->comboBoxSerialCom->addItem(SerailNameList[i]); //在comboBox那添加串口号
        //设置默认显示的串口名字
        ui->comboBoxSerialCom->setCurrentIndex(0);
    }

    if(SerailNameList.size() > 0)
    {
        //添加所有可能的波特率值
        ui->comboBoxSerialBaundRate->addItem(QString("4800"));  //0
        ui->comboBoxSerialBaundRate->addItem(QString("9600"));
        ui->comboBoxSerialBaundRate->addItem(QString("19200"));
        ui->comboBoxSerialBaundRate->addItem(QString("38400"));
        ui->comboBoxSerialBaundRate->addItem(QString("57600"));
        ui->comboBoxSerialBaundRate->addItem(QString("115200"));
        ui->comboBoxSerialBaundRate->addItem(QString("128000"));
        ui->comboBoxSerialBaundRate->addItem(QString("256000"));
        //默认显示的波特率值是19200
        ui->comboBoxSerialBaundRate->setCurrentIndex(2);
    }
}

void Widget::InitMathFunction()
{
    mPMath = new CMath;
}

/***************************初始化写日志的文件路径和对象的函数***************************/
void Widget::InitLogFileName(void)
{
    mPLog = new CLog;
    mLogFilePath.insert(CLog::DEBUG,   "D:/0_ZD047LogDir/Debug.txt");
    mLogFilePath.insert(CLog::INFO,    "D:/0_ZD047LogDir/Info.txt");
    mLogFilePath.insert(CLog::WARNING, "D:/0_ZD047LogDir/Warning.txt");
    mLogFilePath.insert(CLog::ERROR,   "D:/0_ZD047LogDir/Error.txt");
    mLogFilePath.insert(CLog::DATA,    "D:/0_ZD047LogDir/SerialTxRxData.txt");
//    mPLog->WriteLog(QString("MyWidget.cpp"), mLogFilePath[CLog::DEBUG],   21, CLog::DEBUG, 0, NULL);
//    mPLog->WriteLog(QString("MyWidget.cpp"), mLogFilePath[CLog::INFO],    22, CLog::INFO, 0, NULL);
//    mPLog->WriteLog(QString("MyWidget.cpp"), mLogFilePath[CLog::WARNING], 23, CLog::WARNING, 0, NULL);
//    mPLog->WriteLog(QString("MyWidget.cpp"), mLogFilePath[CLog::ERROR],   24, CLog::ERROR, 0, NULL);
//    mPLog->WriteLog(QString("MyWidget.cpp"), mLogFilePath[CLog::DATA],    25, CLog::DATA, 0, QString("1234"));
}

/***************************初始化窗口的大小位置标题等属性的函数***************************/
void Widget::InitMyWidgetAttr()
{
    this->setWindowTitle("车内屏上位机测试软件");
    this->setGeometry(300, 50, 630, 500);
}

/***************************软件刚打开时初始化窗口上显示的子窗口内容***************************/
void Widget::InitDisplayInterface()
{
    //BusInteriorDeviceChosoeDisplay(DEVICE_FRONTSCEEN, false);
   // BusInteriorDeviceChosoeDisplay(DEVICE_BACKSCEEN, false);
    BusInteriorDeviceChosoeCloseAllStatusDisplay();
}

/***************************初始化各种信号和槽关系的函数***************************/
void Widget::InitSignalConnect()
{
//    connect(btn,&QPushButton::clicked,pTea,static_cast<void (Teacher::*)(void)>(&Teacher::hungry));
//    disconnect(btn,&QPushButton::clicked,pTea,static_cast<void (Teacher::*)(void)>(&Teacher::hungry));
//    connect(pTea, SIGNAL(hungry()), pStu, SLOT(treat()));
//    connect(pTea, SIGNAL(hungry(QString)), pStu, SLOT(treat(QString)));
//    connect(ui->baozhanqi,SIGNAL(toggled(bool)),this,SLOT(on_baozhanqi_clicked()));

    //选择车内屏radio后的槽函数BusInteriorDeviceChosoeHandle
    connect(ui->radioButtonFrontScreen,   &QRadioButton::toggled, this, &Widget::BusInteriorDeviceChosoeHandle);
    connect(ui->radioButtonBackScreen,    &QRadioButton::toggled, this, &Widget::BusInteriorDeviceChosoeHandle);
    connect(ui->radioButtonFrontRoad,     &QRadioButton::toggled, this, &Widget::BusInteriorDeviceChosoeHandle);
    connect(ui->radioButtonSideRoad,      &QRadioButton::toggled, this, &Widget::BusInteriorDeviceChosoeHandle);
    connect(ui->radioButtonBackRoad,      &QRadioButton::toggled, this, &Widget::BusInteriorDeviceChosoeHandle);
    connect(ui->radioButtonFrontSection,  &QRadioButton::toggled, this, &Widget::BusInteriorDeviceChosoeHandle);
    connect(ui->radioButtonBackSection,   &QRadioButton::toggled, this, &Widget::BusInteriorDeviceChosoeHandle);
    connect(ui->radioButtonStopAnnouncer, &QRadioButton::toggled, this, &Widget::BusInteriorDeviceChosoeHandle);
    //点击串口打开按钮的槽函数
    connect(ui->pushButtonSerialSwitch, &QPushButton::clicked, this, &Widget::SerialSwitchClick);
    //点击串口发送按钮的槽函数
    connect(ui->pushButtonSerialSend, &QPushButton::clicked, this, &Widget::SerialSendClick);

    //选择前内屏功能的radio后的槽函数FrontScreenFunctionChosoeHandle
    connect(ui->radioButtonFrontScreenSelfCheck,             &QRadioButton::toggled, this, &Widget::FrontScreenFunctionChosoeHandle);
    connect(ui->radioButtonFrontScreenSetTime,               &QRadioButton::toggled, this, &Widget::FrontScreenFunctionChosoeHandle);
    connect(ui->radioButtonFrontScreenSetStopName,           &QRadioButton::toggled, this, &Widget::FrontScreenFunctionChosoeHandle);
    connect(ui->radioButtonFrontScreenSetFirstLast,          &QRadioButton::toggled, this, &Widget::FrontScreenFunctionChosoeHandle);
    connect(ui->radioButtonFrontScreenSetPropagandaLanguage, &QRadioButton::toggled, this, &Widget::FrontScreenFunctionChosoeHandle);
    connect(ui->radioButtonFrontScreenPlayStopName,          &QRadioButton::toggled, this, &Widget::FrontScreenFunctionChosoeHandle);
    connect(ui->radioButtonFrontScreenPlayNumProLanguage,    &QRadioButton::toggled, this, &Widget::FrontScreenFunctionChosoeHandle);
    connect(ui->radioButtonFrontScreenPlayItemProLanguage,   &QRadioButton::toggled, this, &Widget::FrontScreenFunctionChosoeHandle);

}

void Widget::OrganizeHaiXinSendFrame(Widget::BusInteriorDeviceOrder DeviceType,
                                     unsigned char PackageType, unsigned short PackageLen, QByteArray Data)
{
    QByteArray  SendFrame;
    SendFrame[0] = HAIXIN_BEGIN;

    switch (DeviceType) {
        case DEVICE_FRONTSCEEN:     SendFrame[1] = FRONTSCEENADDR;      break;
        case DEVICE_BACKSCEEN:      SendFrame[1] = BACKSCEENADDR;       break;
        case DEVICE_FRONTROAD:      SendFrame[1] = FRONTROADADDR;       break;
        case DEVICE_SIDEROAD:       SendFrame[1] = SIDEROADADDR;        break;
        case DEVICE_BACKROAD:       SendFrame[1] = BACKROADADDR;        break;
        case DEVICE_FRONTSEC:       SendFrame[1] = FRONTSECADDR;        break;
        case DEVICE_BACKSEC:        SendFrame[1] = BACKSECADDR;         break;
        case DEVICE_STOP_ANNOUNCER: SendFrame[1] = STOPANNOUNCERADDR;   break;

        default:
        break;
    }
    SendFrame[2] = TERMINALADDR;
    SendFrame[3] = PackageType;
    SendFrame[4] = 0x01;              //包序列号
    SendFrame[5] = PackageLen>>8;     //包长度高位
    SendFrame[6] = PackageLen&0x00FF; //包长度低位
    for(int i = 0; i < Data.size(); i++)
    {
        SendFrame[7+i] = Data[i];
    }

    SendFrame.append(mPMath->getXORresult(SendFrame));
    SendFrame.append(HAIXIN_END);

    //保存串口发送的数据，用于之后的显示和保存
    mSaveSerialSendData = SendFrame;
    //串口发送数据
    mSerial->SerialSendData(SendFrame);
}

void Widget::HaiXinSendFrameHandleDispalyAndSave()
{
    #ifdef Debug
        qDebug()<< "HaiXinSendFrameDispalyAndSave()串口发送数据显示和保存函数被调用" ;
    #endif

    QDateTime  curDateTime = QDateTime::currentDateTime();
    QString    OriginStr   = ui->textEditTxRxDataDisplay->toPlainText();//保存接收文本框原本的数据
    //ui->recvTextEdit->clear();
    //ui->textEditTxRxDataDisplay->setText(originStr);
    ui->textEditTxRxDataDisplay->moveCursor(QTextCursor::End); // 在末尾移动光标一格
    ui->textEditTxRxDataDisplay->insertPlainText("[");
    ui->textEditTxRxDataDisplay->insertPlainText(curDateTime.toString("yyyy年MM月dd日 hh:mm:ss.zzzzzz"));
    ui->textEditTxRxDataDisplay->insertPlainText("]");
    ui->textEditTxRxDataDisplay->insertPlainText("发送");
    QByteArray readSerialSendData= mSaveSerialSendData;
    int row = readSerialSendData.length();
    if(row < 10)
    {
        ui->textEditTxRxDataDisplay->insertPlainText(" ");
    }
    QString a =QString::number(row,10);
    ui->textEditTxRxDataDisplay->insertPlainText(a);
    ui->textEditTxRxDataDisplay->insertPlainText("个字节：");
    ui->textEditTxRxDataDisplay->insertPlainText(mPMath->ByteArrayToHexString(readSerialSendData));
    QString temp="";
    ui->textEditTxRxDataDisplay->insertPlainText(temp+='\n');
    QString InterAfterStr = ui->textEditTxRxDataDisplay->toPlainText();
    mPLog->WriteLog(QString("MyWidget.cpp"), mLogFilePath[CLog::DATA], 219, CLog::DATA, 0, InterAfterStr.remove(OriginStr));
}

void Widget::HaiXinReceiveFrameHandleDispalyAndSave()
{
    #ifdef Debug
        qDebug()<< "HaiXinReceiveFrameHandleDispalyAndSave()串口接收到数据后的处理" ;
    #endif

    QDateTime  curDateTime = QDateTime::currentDateTime();
    QString    OriginStr   = ui->textEditTxRxDataDisplay->toPlainText();//保存接收文本框原本的数据

    //ui->recvTextEdit->setText(originStr);
    ui->textEditTxRxDataDisplay->moveCursor(QTextCursor::End); // 在末尾移动光标一格
    ui->textEditTxRxDataDisplay->insertPlainText("[");
    ui->textEditTxRxDataDisplay->insertPlainText(curDateTime.toString("yyyy年MM月dd日 hh:mm:ss.zzzzzz"));
    ui->textEditTxRxDataDisplay->insertPlainText("]");
    ui->textEditTxRxDataDisplay->insertPlainText("接收");
    QByteArray SerialData= mSerial->GetSerialReadBuf();
    int row = SerialData.length();
    QString a =QString::number(row,10);
    ui->textEditTxRxDataDisplay->insertPlainText(a);
    ui->textEditTxRxDataDisplay->insertPlainText("个字节：");
    ui->textEditTxRxDataDisplay->insertPlainText(mPMath->ByteArrayToHexString(SerialData));
    QString temp="";
    ui->textEditTxRxDataDisplay->insertPlainText(temp+='\n');
    QString InterAfterStr = ui->textEditTxRxDataDisplay->toPlainText();

    mPLog->WriteLog(QString("MyWidget.cpp"), mLogFilePath[CLog::DATA], 248, CLog::DATA, 0, InterAfterStr.remove(OriginStr));
//    QFile  myfile("D:/data.txt");//创建一个输出文件的文档;//此路径下没有就会自己创建一个
//    if (myfile.open(QFile::WriteOnly|QFile::Append))//注意WriteOnly是往文本中写入的时候用，ReadOnly是在读文本中内容的时候用，Truncate表示将原来文件中的内容清空
//       {
//           //读取之前setPlainText的内容，或直接输出字符串内容QObject::tr()
//           QTextStream out(&myfile);
//           out<<ui->recvTextEdit->toPlainText();
//       }
//    m_serial->clearReadBuf(); // 读取完后，清空数据缓冲区
}

/***************************当有车内设备的radio按钮被toggled时需要显示相关界面的函数***************************/
void Widget::BusInteriorDeviceChosoeDisplay(unsigned char DeviceType, bool DisplaySwitch)
{
    switch (DeviceType)
    {
        case DEVICE_FRONTSCEEN:
            if(DisplaySwitch)
            {
                ui->groupBoxFrontScreen->show();
            }
            else
            {
                ui->groupBoxFrontScreen->hide();
            }
            break;

        case DEVICE_BACKSCEEN:
            if(DisplaySwitch)
            {
                ui->groupBoxBackScreen->show();
            }
            else
            {
                ui->groupBoxBackScreen->hide();
            }
            break;

        case DEVICE_FRONTROAD:
            break;
        case DEVICE_SIDEROAD:
            break;
        case DEVICE_BACKROAD:
            break;
        case DEVICE_FRONTSEC:
            break;
        case DEVICE_BACKSEC:
            break;
        case DEVICE_STOP_ANNOUNCER:
            break;

        default:
            break;
    }
}

/***************************关闭车内所有设备功能相关的显示界面和状态位***************************/
void Widget::BusInteriorDeviceChosoeCloseAllStatusDisplay()
{
    for(unsigned char i = 0; i < BusInteriorDeviceSum; i++)
    {
        //关闭所有车内设备功能的显示界面
        BusInteriorDeviceChosoeDisplay(i, false);
        //清空所有车内设备数组状态
        mBusInteriorDeviceStatus[i] = false;
    }
}

void Widget::FrontScreenFunctionChosoeDisplay(unsigned char FrontScreenFuncType, bool DisplaySwitch)
{
    switch (FrontScreenFuncType)
    {
        case FRONTSCEEN_SelfCheck:  //自检没有界面
            break;

        case FRONTSCEEN_SetTime:
            if(DisplaySwitch)
            {
                //ui->groupBoxBackScreen->show();
            }
            else
            {
                //ui->groupBoxBackScreen->hide();
            }
            break;

        case FRONTSCEEN_SetStopName:
            break;
        case FRONTSCEEN_SetFirstLast:
            break;
        case FRONTSCEEN_SetPropagandaLanguage:
            break;
        case FRONTSCEEN_PlayStopName:
            break;
        case FRONTSCEEN_PlayNumProLanguage:
            break;
        case FRONTSCEEN_PlayItemProLanguage:
            break;

        default:
            break;
    }
}

void Widget::FrontScreenFunctionChosoeCloseAllStatusDisplay()
{
    for(unsigned char i = 0; i < BusInteriorDeviceSum; i++)
    {
        //关闭所有车内设备功能的显示界面
        FrontScreenFunctionChosoeDisplay(i, false);
        //清空车内屏功能的所有状态
        mFrontScreenFunctionStatus[i] = false;
    }
}

///////////////////////////////////////////////////////槽函数开始处/////////////////////////////////////
/***************************当有车内设备的radio按钮被toggled时触发的槽函数***************************/
void Widget::BusInteriorDeviceChosoeHandle()
{
    //FrontScreenFunctionChosoeCloseAllStatusDisplay();
    /********************前内屏radio被选中********************/
    if(ui->radioButtonFrontScreen->isChecked() == true)
    {
        BusInteriorDeviceChosoeCloseAllStatusDisplay();
        //设置前车内屏功能相关界面
        BusInteriorDeviceChosoeDisplay(DEVICE_FRONTSCEEN, true);
        //设置前车内屏数组状态
        mBusInteriorDeviceStatus[DEVICE_FRONTSCEEN] = true;
    }

    /********************后内屏radio被选中********************/
    else if(ui->radioButtonBackScreen->isChecked() == true)
    {
        BusInteriorDeviceChosoeCloseAllStatusDisplay();
        //设置前车内屏功能相关界面
        BusInteriorDeviceChosoeDisplay(DEVICE_BACKSCEEN, true);
        //设置前车内屏数组状态
        mBusInteriorDeviceStatus[DEVICE_BACKSCEEN] = true;
    }

    /********************前路牌radio被选中********************/
    else if(ui->radioButtonFrontRoad->isChecked() == true)
    {
        BusInteriorDeviceChosoeCloseAllStatusDisplay();
        //设置前车内屏功能相关界面
        BusInteriorDeviceChosoeDisplay(DEVICE_FRONTROAD, true);
        //设置前车内屏数组状态
        mBusInteriorDeviceStatus[DEVICE_FRONTROAD] = true;
    }

    /********************侧路牌radio被选中********************/
    else if(ui->radioButtonSideRoad->isChecked() == true)
    {
        BusInteriorDeviceChosoeCloseAllStatusDisplay();
        //设置前车内屏功能相关界面
        BusInteriorDeviceChosoeDisplay(DEVICE_SIDEROAD, true);
        //设置前车内屏数组状态
        mBusInteriorDeviceStatus[DEVICE_SIDEROAD] = true;
    }

    /********************后路牌radio被选中********************/
    else if(ui->radioButtonBackRoad->isChecked() == true)
    {
        BusInteriorDeviceChosoeCloseAllStatusDisplay();
        //设置前车内屏功能相关界面
        BusInteriorDeviceChosoeDisplay(DEVICE_BACKROAD, true);
        //设置前车内屏数组状态
        mBusInteriorDeviceStatus[DEVICE_BACKROAD] = true;
    }

    /********************前站节牌radio被选中********************/
    else if(ui->radioButtonFrontSection->isChecked() == true)
    {
        BusInteriorDeviceChosoeCloseAllStatusDisplay();
        //设置前车内屏功能相关界面
        BusInteriorDeviceChosoeDisplay(DEVICE_FRONTSEC, true);
        //设置前车内屏数组状态
        mBusInteriorDeviceStatus[DEVICE_FRONTSEC] = true;
    }

    /********************后站节牌radio被选中********************/
   else if(ui->radioButtonBackSection->isChecked() == true)
    {
        BusInteriorDeviceChosoeCloseAllStatusDisplay();
        //设置前车内屏功能相关界面
        BusInteriorDeviceChosoeDisplay(DEVICE_BACKSEC, true);
        //设置前车内屏数组状态
        mBusInteriorDeviceStatus[DEVICE_BACKSEC] = true;
    }

    /********************报站器radio被选中********************/
    else if(ui->radioButtonStopAnnouncer->isChecked() == true)
    {
        BusInteriorDeviceChosoeCloseAllStatusDisplay();
        //设置前车内屏功能相关界面
        BusInteriorDeviceChosoeDisplay(DEVICE_STOP_ANNOUNCER, true);
        //设置前车内屏数组状态
        mBusInteriorDeviceStatus[DEVICE_STOP_ANNOUNCER] = true;
    }
    else
    {
        return;
    }
}

void Widget::SerialSwitchClick(void)
{
    if(ui->pushButtonSerialSwitch->text() == tr("打开串口"))
    {
        if(mSerial->SerialOpen(ui->comboBoxSerialCom->currentText(), ui->comboBoxSerialBaundRate->currentText()))
        {
            #ifdef Debug
                qDebug()<< "串口" <<ui->comboBoxSerialCom->currentText()<< "被打开" ;
            #endif

            // 关闭下拉列表使能
            ui->comboBoxSerialCom->setEnabled(false);
            ui->comboBoxSerialBaundRate->setEnabled(false);
            //修改按钮名称
            ui->pushButtonSerialSwitch->setText(QString("关闭串口"));
            //ui->pushButtonSerialSwitch->setText(tr("关闭串口"));
            //设置串口状态是打开
            mSerialStatus = true;
            //串口打开后，关联发送数据时触发，对所发数据的处理
            connect(mSerial, &Serial::sendSignal, this, &Widget::HaiXinSendFrameHandleDispalyAndSave);
            //串口打开后，关联接收到数据之后，对接收数据的处理
            connect(mSerial, &Serial::TriggerOtherProgramReadSerialDataSignal, this, &Widget::HaiXinReceiveFrameHandleDispalyAndSave);
        }
    }
    else
    {
        #ifdef Debug
            qDebug()<< "串口" <<ui->comboBoxSerialCom->currentText()<< "被关闭" ;
        #endif

        // 关闭串口
        mSerial->Serialclose();
        // 重新开启下拉列表使能
        ui->comboBoxSerialCom->setEnabled(true);
        ui->comboBoxSerialBaundRate->setEnabled(true);
        //修改按钮名称
        ui->pushButtonSerialSwitch->setText(QString("打开串口"));
        //设置串口状态是关闭
        mSerialStatus = false;
    }
}

void Widget::SerialSendClick()
{
    if(mSerialStatus)    //串口正确打开
    {
        #ifdef Debug
            qDebug()<< "串口" <<ui->comboBoxSerialCom->currentText()<< "被打开时，发送按钮被点击" ;
        #endif
        //准备发送数据
        if(mBusInteriorDeviceStatus[DEVICE_FRONTSCEEN] == true)
        {
            #ifdef Debug
                qDebug()<< "前内屏准备发送内容" ;
            #endif

            /*******************根据所选的前/后内屏功能，准备不同的数据发送********************/
            if(mFrontScreenFunctionStatus[FRONTSCEEN_SelfCheck] == true)    //自检功能
            {
                #ifdef Debug
                    qDebug()<< "前内屏或后内屏准备发送自检内容" ;
                #endif

                OrganizeHaiXinSendFrame(DEVICE_FRONTSCEEN, 0x01, 0x00, QByteArray());

            }
            else if(mFrontScreenFunctionStatus[FRONTSCEEN_SetTime] == true) //设置时间功能
            {

            }
            else if(mFrontScreenFunctionStatus[FRONTSCEEN_SetStopName] == true) //设置站名功能
            {


            }
            else if(mFrontScreenFunctionStatus[FRONTSCEEN_SetFirstLast] == true) //设置首末句功能
            {


            }
            else if(mFrontScreenFunctionStatus[FRONTSCEEN_SetPropagandaLanguage] == true) //设置宣传用语功能
            {


            }
            else if(mFrontScreenFunctionStatus[FRONTSCEEN_PlayStopName] == true) //播放站名功能
            {


            }
            else if(mFrontScreenFunctionStatus[FRONTSCEEN_PlayNumProLanguage] == true) //按序号播放宣传用语功能
            {


            }
            else if(mFrontScreenFunctionStatus[FRONTSCEEN_PlayItemProLanguage] == true) //按内容播放宣传用语功能
            {


            }
            else
            {
                QMessageBox::information(this, QString("没有选中前内屏功能"), QString("请先选择前内屏功能"));
            }
        }
        else if(mBusInteriorDeviceStatus[DEVICE_BACKSCEEN] == true)//后内屏
        {
            #ifdef Debug
                qDebug()<< "后内屏准备发送内容" ;
            #endif
        }
        else if(mBusInteriorDeviceStatus[DEVICE_FRONTROAD] == true)//前路牌
        {
            #ifdef Debug
                qDebug()<< "前路牌准备发送内容" ;
            #endif
        }
        else if(mBusInteriorDeviceStatus[DEVICE_SIDEROAD] == true)//侧路牌
        {
            #ifdef Debug
                qDebug()<< "侧路牌准备发送内容" ;
            #endif
        }
        else if(mBusInteriorDeviceStatus[DEVICE_BACKROAD] == true)//后路牌
        {
            #ifdef Debug
                qDebug()<< "后路牌准备发送内容" ;
            #endif
        }
        else if(mBusInteriorDeviceStatus[DEVICE_FRONTSEC] == true)//前站节牌
        {
            #ifdef Debug
                qDebug()<< "前站节牌准备发送内容" ;
            #endif
        }
        else if(mBusInteriorDeviceStatus[DEVICE_BACKSEC] == true)//后站节牌
        {
            #ifdef Debug
                qDebug()<< "后站节牌准备发送内容" ;
            #endif
        }
        else if(mBusInteriorDeviceStatus[DEVICE_STOP_ANNOUNCER] == true)//报站器
        {
            #ifdef Debug
                qDebug()<< "报站器准备发送内容" ;
            #endif
        }
        else    //没有设备被选中
        {
            #ifdef Debug
                qDebug()<< "没有设备被选中不发送内容" ;
            #endif

            QMessageBox::information(this, QString("没有选中车内设备"), QString("请先选择车内设备"));
        }
    }
    else    //串口未打开
    {
        #ifdef Debug
            qDebug()<< "串口" <<ui->comboBoxSerialCom->currentText()<< "被关闭时，发送按钮被点击" ;
        #endif

        QMessageBox::information(this, QString("串口未打开"), QString("请先打开串口"));
    }
}

void Widget::FrontScreenFunctionChosoeHandle()
{
    /********************前内屏功能中的自检radio被选中********************/
    if(ui->radioButtonFrontScreenSelfCheck->isChecked() == true)
    {
        //关闭前内屏功能相关界面和清空车内屏功能的所有状态
        FrontScreenFunctionChosoeCloseAllStatusDisplay();
        //设置前内屏功能相关界面
        FrontScreenFunctionChosoeDisplay(DEVICE_FRONTSCEEN, true);
        //设置前车内屏数组状态
        mFrontScreenFunctionStatus[FRONTSCEEN_SelfCheck] = true;
    }
    else if(ui->radioButtonFrontScreenSetTime->isChecked() == true)
    {

        //关闭前内屏功能相关界面和清空车内屏功能的所有状态
        FrontScreenFunctionChosoeCloseAllStatusDisplay();
        //设置前内屏功能相关界面
        FrontScreenFunctionChosoeDisplay(DEVICE_FRONTSCEEN, true);
        //设置前车内屏数组状态
        mFrontScreenFunctionStatus[FRONTSCEEN_SetTime] = true;
    }
    else if(ui->radioButtonFrontScreenSetStopName->isChecked() == true)
    {

        //关闭前内屏功能相关界面和清空车内屏功能的所有状态
        FrontScreenFunctionChosoeCloseAllStatusDisplay();
        //设置前内屏功能相关界面
        FrontScreenFunctionChosoeDisplay(DEVICE_FRONTSCEEN, true);
        //设置前车内屏数组状态
        mFrontScreenFunctionStatus[FRONTSCEEN_SetStopName] = true;
    }
    else if(ui->radioButtonFrontScreenSetFirstLast->isChecked() == true)
    {

        //关闭前内屏功能相关界面和清空车内屏功能的所有状态
        FrontScreenFunctionChosoeCloseAllStatusDisplay();
        //设置前内屏功能相关界面
        FrontScreenFunctionChosoeDisplay(DEVICE_FRONTSCEEN, true);
        //设置前车内屏数组状态
        mFrontScreenFunctionStatus[FRONTSCEEN_SetFirstLast] = true;
    }
    else if(ui->radioButtonFrontScreenSetPropagandaLanguage->isChecked() == true)
    {

        //关闭前内屏功能相关界面和清空车内屏功能的所有状态
        FrontScreenFunctionChosoeCloseAllStatusDisplay();
        //设置前内屏功能相关界面
        FrontScreenFunctionChosoeDisplay(DEVICE_FRONTSCEEN, true);
        //设置前车内屏数组状态
        mFrontScreenFunctionStatus[FRONTSCEEN_SetPropagandaLanguage] = true;
    }
    else if(ui->radioButtonFrontScreenPlayStopName->isChecked() == true)
    {

        //关闭前内屏功能相关界面和清空车内屏功能的所有状态
        FrontScreenFunctionChosoeCloseAllStatusDisplay();
        //设置前内屏功能相关界面
        FrontScreenFunctionChosoeDisplay(DEVICE_FRONTSCEEN, true);
        //设置前车内屏数组状态
        mFrontScreenFunctionStatus[FRONTSCEEN_PlayStopName] = true;
    }
    else if(ui->radioButtonFrontScreenPlayNumProLanguage->isChecked() == true)
    {

        //关闭前内屏功能相关界面和清空车内屏功能的所有状态
        FrontScreenFunctionChosoeCloseAllStatusDisplay();
        //设置前内屏功能相关界面
        FrontScreenFunctionChosoeDisplay(DEVICE_FRONTSCEEN, true);
        //设置前车内屏数组状态
        mFrontScreenFunctionStatus[FRONTSCEEN_PlayNumProLanguage] = true;
    }
    else if(ui->radioButtonFrontScreenPlayItemProLanguage->isChecked() == true)
    {

        //关闭前内屏功能相关界面和清空车内屏功能的所有状态
        FrontScreenFunctionChosoeCloseAllStatusDisplay();
        //设置前内屏功能相关界面
        FrontScreenFunctionChosoeDisplay(DEVICE_FRONTSCEEN, true);
        //设置前车内屏数组状态
        mFrontScreenFunctionStatus[FRONTSCEEN_PlayItemProLanguage] = true;
    }
}
