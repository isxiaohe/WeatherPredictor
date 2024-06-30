#ifndef FOLLOWMOUSEWIDGET_H
#define FOLLOWMOUSEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QTimer>
#include <QPalette>
#include <QColor>
#include "weathereachday.h"
#include <QStringList>
#include "weatherrealtime.h"

namespace Ui {
class FollowMouseWidget;
}

class FollowMouseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FollowMouseWidget(QWidget *parent = nullptr);
    ~FollowMouseWidget() override;
    void updateText();
    void updateText1();

private:
    QPoint mousePosition;
    void setupInitialPosition();
    QTimer timer;
    QTimer *doubleClickTimer;
    int spaceCount;
    Ui::FollowMouseWidget *ui;
private slots:
    void checkTimeout();
    void hideWidget();

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            move(mouseEvent->globalPos() - QPoint(width() / 7, height() / 5)); // 将窗口中心对准鼠标位置
            //move(mouseEvent->globalPos()); // 将窗口左上角对准鼠标位置
            return true; // 事件已处理，不传递给下一个过滤器
        }
        return false; // 其他事件交给父类处理
    }
    void keyPressEvent(QKeyEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

};

#endif // FOLLOWMOUSEWIDGET_H
