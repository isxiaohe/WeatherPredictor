#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>
#include<QTimer>
#include<QDateTime>
#include<Qpainter>
#include <QPaintEvent>
#include"search_box.h"
#include<QFont>
#include<QDir>
#include<QCoreApplication>
#include<QPixmap>
#include"followmousewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class mywidget;
}
QT_END_NAMESPACE

class mywidget : public QMainWindow
{
    Q_OBJECT

public:
    mywidget(QWidget *parent = nullptr);
    ~mywidget();
    QTimer * timer;
    void showTime();
    search_box* box;
    void paintEvent(QPaintEvent* event) override;
    //void mouseMoveEvent(QMouseEvent* event);
    bool eventFilter(QObject* obj, QEvent* event) override;
    FollowMouseWidget* MyFollow1 = new FollowMouseWidget();
    FollowMouseWidget* MyFollow2 = new FollowMouseWidget();
// public slots:
//     void receivedData(QString data);
private slots:
    void on_RefreshBtn_clicked();

    void on_CityBtn_clicked(bool checked);

    void on_changeBack_clicked();

    void on_ShowTimeButton_clicked();

    void on_ShowTemperatureButton_clicked();

private:
    Ui::mywidget *ui;
};
#endif // MYWIDGET_H
extern QString pathMywidgetBackground; //mywidget 背景
extern QString pathWeatherIcon;
extern int indexBack;
