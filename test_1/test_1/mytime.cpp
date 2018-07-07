#include "mytime.h"
#include <QDateTime>
#include <QDate>
#include <QTime>
MyTime::MyTime(QObject *parent) : QObject(parent)
{

}

QString MyTime::getTime(QString format)
{
    QDateTime dateTime=QDateTime::currentDateTime().toLocalTime();
//    QDate date=dateTime.date();
//    QTime time=dateTime.time();
//    QString month=dateTime.toString(tr("MMM"));

    return dateTime.toString(format);
}


