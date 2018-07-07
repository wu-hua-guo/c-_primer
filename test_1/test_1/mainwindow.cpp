#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytime.h"
#include <QTimer>
#include <QTime>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateDateTime();

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDateTime()));
    timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDateTime()
{
    ui->timeLabel->setText(MyTime::getTime());
}
