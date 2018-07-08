#include "mainwindow.h"
#include <QApplication>
#include <QDialog>
#include <QDebug>
#define mydebug
#if defined(qApp)
#undef qApp
#endif
#define qApp (static_cast<QApplication *>(QCoreApplication::instance()))
//#define noPattern
//#define banPattern
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 加载QSS样式
    CommonHelper::setStyle(":/qss/style.qss");
    MainWindow *w=new MainWindow();
    w->setWindowTitle(QString("主界面"));
    w->show();

#ifdef banPattern
    QDialog *pDialog=new QDialog(w);
    pDialog->setWindowTitle(QString("模式对话框"));
    pDialog->setModal(true);
    pDialog->show();
#ifdef mydebug
    qDebug()<<w->windowTitle();
#endif
    w->setWindowTitle(QString("主界面-模式对话框"));
#ifdef mydebug
    qDebug()<<w->windowTitle();
#endif
#endif

#ifdef noPattern
    QDialog *pDialog=new QDialog(w);
    pDialog->setWindowTitle(QString("模式对话框"));
    pDialog->exec();
#ifdef mydebug
    qDebug()<<w->windowTitle();
#endif
    w->setWindowTitle(QString("主界面-模式对话框"));
#ifdef mydebug
    qDebug()<<w->windowTitle();
#endif
#endif

    int ret = a.exec();
    delete w;
    return ret;
}
