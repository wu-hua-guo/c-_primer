#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bannerwidget.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BannerWidget *myText=new BannerWidget(this);
    myText->setGeometry(50,50,400,400);

}

MainWindow::~MainWindow()
{
    delete ui;
}
