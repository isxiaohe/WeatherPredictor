#include "followmousewidget.h"
#include "ui_followmousewidget.h"
#include "FollowMouseWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QCursor>

FollowMouseWidget::FollowMouseWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FollowMouseWidget), spaceCount(0)
{
    ui->setupUi(this);
    setMouseTracking(true); // 开启鼠标跟踪，以便能够捕获鼠标移动事件
    installEventFilter(this); // 安装事件过滤器到当前对象（即自身）
    setStyleSheet("background-color: transparent; color: black;");
    setWindowOpacity(0.8);

    this->setWindowTitle("按下两次空格或双击即可隐藏");//设置提示

    setFocusPolicy(Qt::StrongFocus); // 设置焦点策略为强焦点，以便接收键盘事件
    // 设置定时器，0.5秒后超时
    timer.setSingleShot(true);
    timer.setInterval(500); // 500毫秒 = 0.5秒
    // 连接定时器的超时信号到槽函数
    connect(&timer, SIGNAL(timeout()), this, SLOT(checkTimeout()));


    doubleClickTimer = new QTimer(this);
    doubleClickTimer->setInterval(500); // 设置为0.5秒
    doubleClickTimer->setSingleShot(true); // 单次触发

    connect(doubleClickTimer, &QTimer::timeout, this, &FollowMouseWidget::hideWidget);

    setupInitialPosition();
    update();
}

FollowMouseWidget::~FollowMouseWidget() {
    delete doubleClickTimer;
}

void FollowMouseWidget::mouseMoveEvent(QMouseEvent *event)
{
    mousePosition = event->pos(); // Update mouse position when moved
    move(mousePosition); // Move the widget to the current mouse position




}

void FollowMouseWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // Enable antialiasing for smooth drawing

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);

    // Draw a circle at the current mouse position
    //painter.drawEllipse(rect().center() - QPoint(10, 10), 20, 20);
}


void FollowMouseWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        ++spaceCount; // 每次按下空格键增加计数

        if (spaceCount == 1)
        {
            // 启动定时器
            timer.start();
        }
        else if (spaceCount == 2)
        {
            // 如果第二次按下空格键，直接隐藏自己
            hide();
            spaceCount = 0; // 重置计数
        }
    }
    else
    {
        spaceCount = 0; // 如果按下的不是空格键，则重置计数
    }

    QWidget::keyPressEvent(event); // 调用基类的键盘事件处理函数
}

void FollowMouseWidget::checkTimeout()
{
    spaceCount = 0; // 定时器超时，重置计数
}



void FollowMouseWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 如果是双击事件，启动定时器
    if (event->button() == Qt::LeftButton)
    {
        doubleClickTimer->start();
    }
    QWidget::mouseDoubleClickEvent(event);
}

void FollowMouseWidget::hideWidget()
{
    // 双击定时器超时时调用，隐藏自身
    hide();
}


void FollowMouseWidget::setupInitialPosition()
{
    // 获取当前鼠标的全局位置
    QPoint cursorPos = QCursor::pos();

    // 将 Widget 移动到鼠标位置
    move(cursorPos);
    qDebug()<<"Yes！";
}

void FollowMouseWidget::updateText() {
    QStringList lines;
    for (int i = 1; i < 7; i++) {
        lines << "日期:" + weatherForSevenDay[i].date;
        qDebug() << weatherForSevenDay[i].date;
        lines << "白天天气:" + weatherForSevenDay[i].weatherDay;
        lines << "夜晚天气:" + weatherForSevenDay[i].weatherNight;
        lines << "最高温度:" + weatherForSevenDay[i].tempMax;
        lines << "最低温度:" + weatherForSevenDay[i].tempMin;
        lines << "白天风向:" + weatherForSevenDay[i].windDirDay;
        lines << "夜晚风向:" + weatherForSevenDay[i].windDirNight;
        lines << "-------------------";
    }

    foreach (const QString &line, lines) { ui->textBrowser->append(line); }
}

void FollowMouseWidget::updateText1() {
    QStringList lines;
    lines<<"体感温度: " + weatherRealTimeObj.feelsLike << "UV: " + weatherForSevenDay[0].uvIndex << "风力等级: " + weatherRealTimeObj.windScale;
    lines<<"风向: " + weatherRealTimeObj.windDir << "大气压: " + weatherRealTimeObj.pressure;
    foreach (const QString &line, lines) { ui->textBrowser->append(line); }
}
