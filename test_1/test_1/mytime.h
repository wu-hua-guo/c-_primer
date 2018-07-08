#ifndef MYTIME_H
#define MYTIME_H

#include <QObject>

class MyTime : public QObject
{
    //Q_OBJECT
public:
    explicit MyTime(QObject *parent = 0);

signals:

public slots:
public:
    static QString getTime(QString format=tr("yyyy-MM-dd HH:mm:ss"));
};

#endif // MYTIME_H
