#ifndef CLOG_H
#define CLOG_H

#include <QString>

/*
const char *file：文件名称
int line：文件行号
int level：错误级别
        0 -- 没有日志
        1 -- debug级别
        2 -- info级别
        3 -- warning级别
        4 -- err级别
int status：错误码
const char *fmt：可变参数
*/

class CLog
{
public:
    CLog();
    ~CLog();

public:
    enum LogLevel{NOLOG, DEBUG, INFO, WARNING, ERROR, DATA};
    void WriteLog(QString OccurFileName, QString LogFileName,
                  int line, int level, int status, QString DataStr);

private:
    int  LogGetCurTime(QString &strTime);
    void LogCore(QString OccurFileName, QString LogFileName,
                 int line, int level, int status, QString DataStr);
    bool isDirExist(QString fullPath);//判断目录或文件是否存在，不存在创建目录
private:
    const QString LogLevelName[6] = { "NOLOG", "DEBUG", "INFO", "WARNING", "ERROR", "DATA"};
};

#endif // CLOG_H
