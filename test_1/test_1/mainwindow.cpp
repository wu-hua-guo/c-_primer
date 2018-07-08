#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytime.h"
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QMovie>
#include <QLCDNumber>
#include <QPushButton>
#include <QDateTimeEdit>
#include <QScrollArea>
#include <QGroupBox>
#include <QVBoxLayout>
#define myDebug

/**
* @projectName   test_1
* @brief         主界面
* @author        zqw
* @date          2018-07-07  15:58:22
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setStyleSheet("background-color: rgb(88, 88, 88);");
    //ui->timeLabel->setStyleSheet("color: white;");

//    updateDateTime();
//    setTimer();
//    setLCD();
//    addQButtonGroup();
//    addQMenu();
    QLabel *pLabel = new QLabel(this);
    QPushButton *pButton = new QPushButton(this);
    QGroupBox *pGroupBox = new QGroupBox(this);

    pLabel->setObjectName("customLabel");
    pButton->setObjectName("customButton");
    pGroupBox->setObjectName("customGroupBox");

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addStretch();
    pLayout->addWidget(pLabel, 0, Qt::AlignCenter);
    pLayout->addWidget(pButton);
    pLayout->addStretch();
    pLayout->setSpacing(10);
    pLayout->setContentsMargins(10, 10, 10, 10);

    pGroupBox->setLayout(pLayout);
}



MainWindow::~MainWindow()
{
    delete ui;
}
/**
* @brief         更新时间
* @author        zqw
* @dateTime      2018-07-07  16:03:55
*/
void MainWindow::updateDateTime()
{
    ui->timeLabel->setText(MyTime::getTime());
}
/**
* @brief         更新LCD时间
* @author        zqw
* @dateTime      2018-07-07  17:54:19
*/
void MainWindow::upLCDTime()
{
    // 显示的内容
    m_pLCD->display(MyTime::getTime());
}

void MainWindow::onButtonClicked(QAbstractButton *button)
{
    qDebug() << "Clicked Button : " << button->text();
}
/**
* @brief         添加定时器
* @author        zqw
* @dateTime      2018-07-07  16:04:31
*/
void MainWindow::setTimer()
{
#ifdef myDebug
    qDebug()<<MyTime::getTime();
#endif

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDateTime()));
    timer->start(1000);
}
/**
* @brief         添加LCD时间显示
* @author        zqw
* @dateTime      2018-07-07  17:48:20
*/
void MainWindow::setLCD()
{
    m_pLCD = new QLCDNumber(this);
    // 设置能显示的位数
    m_pLCD->setDigitCount(20);
    // 设置显示的模式为十进制
    m_pLCD->setMode(QLCDNumber::Dec);
    // 设置显示外观
    m_pLCD->setSegmentStyle(QLCDNumber::Flat);
    // 设置样式
    m_pLCD->setStyleSheet("border: 3px solid green; color: green; background: silver;");
    m_pLCD->setGeometry(0,200,200,50);
    this->upLCDTime();

    QTimer *timer = new QTimer(this);
    // 设置定时间隔
    //pTimer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(upLCDTime()));

    // 启动定时器
    timer->start(2000);
}
/**
* @brief         添加 QButtonGroup
* @author        zqw
* @dateTime      2018-07-07  20:02:08
*/
void MainWindow::addQButtonGroup()
{
    QButtonGroup *pButtonGroup = new QButtonGroup(this);

    // 设置互斥
    pButtonGroup->setExclusive(true);

    for (int i = 0; i < 3; ++i)
    {
        QAbstractButton *pButton = new QPushButton(this);

        // 设置可选中
        pButton->setCheckable(true);

        // 设置文本

        pButton->setText(QString("Click Me %1").arg(i + 1));
        pButton->setGeometry(i*100,0,70,30);

        pButtonGroup->addButton(pButton);
    }

    connect(pButtonGroup, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(onButtonClicked(QAbstractButton*)));
}
/**
* @brief         添加 QMenu
* @author        zqw
* @dateTime      2018-07-07  20:02:29
*/
void MainWindow::addQMenu()
{
    // 菜单
    QMenu *pMenu = new QMenu(this);
    pMenu->addAction("设置");
    pMenu->addAction("版本检测");
    pMenu->addSeparator();
    pMenu->addAction("关于我们");
    pMenu->addAction("退出");

    // 按钮
    QPushButton *pButton = new QPushButton(this);
    pButton->setText("主菜单");

    // 设置菜单
    pButton->setMenu(pMenu);
    pButton->setGeometry(0,100,80,30);
}
