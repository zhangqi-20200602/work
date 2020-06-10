#include "CLog.h"
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

//#define Debug

/***********************构造和析构函数***********************/
CLog::CLog()
{

}

CLog::~CLog()
{

}

/***********************写日志函数***********************/
void CLog::WriteLog(QString OccurFileName, QString LogFileName,
                    int line, int level, int status, QString DataStr)
{
   if (level == NOLOG)
   {
       return;
   }

   LogCore(OccurFileName, LogFileName, line, level, status, DataStr);
}

/***********************获取当前时间函数***********************/
int CLog::LogGetCurTime(QString &strTime)
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    strTime = curDateTime.toString("yyyy年MM月dd日 hh:mm:ss.zzzzzz");

    return 0;
}

void CLog::LogCore(QString OccurFileName, QString LogFileName,
                   int line, int level, int status, QString DataStr)
{
    QString str;
    QString tmpStr;

    isDirExist(LogFileName);
    if(level == DATA)
    {
        /*****加入LOG的时间******/
//        str += "[";
//        LogGetCurTime(tmpStr);
//        str += tmpStr;
//        str += "]";
        if(DataStr != NULL)
        {
            str +=DataStr;
        }
        else
        {
            return;
        }

        //str+='\n';

        /*****打开要写入日志的文件******/
        #ifdef Debug
            qDebug() << "写入的文件名字是：" << LogFileName;
        #endif

        QFile  LogFile(LogFileName);
        //注意WriteOnly是往文本中写入的时候用，ReadOnly是在读文本中内容的时候用，Truncate表示将原来文件中的内容清空
        if(LogFile.open(QFile::WriteOnly | QFile::Append))
        {
            QTextStream out(&LogFile);
            //out.setCodec("UTF-8");//可以设置所需要的编码格式的
            out<<str;
        }
        else
        {
            #ifdef Debug
                qDebug() << "写入的文件打开失败\n";
            #endif
        }
    }
    else
    {
        /*****加入LOG的时间******/
        str += "[";
        LogGetCurTime(tmpStr);
        str += tmpStr;
        str += "]";

        /*****加入LOG的级别******/
        str += "[";
        str += LogLevelName[level];
        str += "]";

        /*****加入LOG的状态******/
        if (status != 0)
        {
            str += "[ERRNO is ";
            QString strStatus =QString::number(status,10);
            str += strStatus;
            str += "]";
        }
        else
        {
            str += "[SUCCESS    ]";
        }

        /*****加入LOG发生的文件******/
        str += "[OccurFileName: ";
        str += OccurFileName;
        str += "]";

        /*****加入LOG发生的行数******/
        str += "[Line: ";
        QString strStatus =QString::number(line,10);
        str += strStatus;
        str += "]";
        str+='\n';

        /*****打开要写入日志的文件******/
        #ifdef Debug
            qDebug() << "写入的文件名字是：" << LogFileName;
        #endif

        QFile  LogFile(LogFileName);
        //注意WriteOnly是往文本中写入的时候用，ReadOnly是在读文本中内容的时候用，Truncate表示将原来文件中的内容清空
        if(LogFile.open(QFile::WriteOnly | QFile::Append))
        {
            QTextStream out(&LogFile);
            out<<str;
        }
        else
        {
            #ifdef Debug
                qDebug() << "写入的文件打开失败\n";
            #endif
        }
    }
}

bool CLog::isDirExist(QString fullPath)
{
    //"D:/ZD047LogDir/Debug.txt"

    QString str1 = "/";
    int pos = 0;
    int posArray[20] = {0};
    int i = 0;

    #ifdef Debug
        qDebug()<< "fullPath删除前:"<<fullPath;
    #endif

    while(pos != -1)
    {
        pos = fullPath.indexOf(str1, pos+1);
        posArray[i++] = pos;

        #ifdef Debug
            qDebug()<<"pos:"<<pos;
        #endif
    }

    if(i >= 2)
    {
        QString str2;
        for(int j = posArray[i-2]; j <fullPath.size(); j++)
        {
            str2 += fullPath.at(j);
        }

        fullPath.remove(str2);
        #ifdef Debug
            qDebug()<< "fullPath删除后:"<<fullPath;
            qDebug()<<"i = " << i ;  //减去2之后就是最后一个/
        #endif
    }

    QDir dir(fullPath);
    if(dir.exists())
    {
        return true;
    }
    else
    {
        bool ok = dir.mkdir(fullPath);//只创建一级子目录，即必须保证上级目录存在
        return ok;
    }

//    QDir dir(fullPath);
//    if(dir.exists())
//    {
//        return true;
//    }
//    else
//    {
//        bool ok = dir.mkpath(fullPath);//创建多级目录
//        return ok;
//    }
}


/***********************判断文件夹是否存在,不存在则创建************************/
///*方法1*/
//bool isDirExist(QString fullPath)
//{
//    QDir dir(fullPath);
//    if(dir.exists())
//    {
//      return true;
//    }
//    else
//    {
//       bool ok = dir.mkdir(fullPath);//只创建一级子目录，即必须保证上级目录存在
//       return ok;
//    }
//}
///*方法2*/
//bool isDirExist(QString fullPath)
//{
//    QDir dir(fullPath);
//    if(dir.exists())
//    {
//      return true;
//    }
//    else
//    {
//       bool ok = dir.mkpath(fullPath);//创建多级目录
//       return ok;
//    }
//}

////3、判断文件或文件夹是不是存在(即不确定字符串是文件还是文件夹路径)
////参数说明：
////QString fullFilePath;//路径名
///*方法1*/
//bool isFileExist(QString fullFilePath)
//{
//    QFileInfo fileInfo(fullFilePath);
//    if(fileInfo.exists())
//    {
//        return true;
//    }
//    return false;
//}
///*方法2*/
//bool isFileExist(QString fullFilePath)
//{
//    QFile file(fullFilePath);
//    if(file.exists())
//    {
//        return true;
//    }
//    return false;
//}



