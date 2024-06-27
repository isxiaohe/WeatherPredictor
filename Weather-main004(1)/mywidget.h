#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QFont>
#include <QAction>
#include <QLabel>
#include <QLineEdit>
#include <QTextBrowser>
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui {
class mywidget;
}
QT_END_NAMESPACE









class mywidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit mywidget(QWidget *parent = nullptr);
    ~mywidget();
    //绘制图片
    void paintEvent(QPaintEvent* event);
    bool eventFilter(QObject* obj, QEvent* event);

private slots:
    void on_RefreshBtn_clicked();

    void on_CityBtn_clicked();

    void on_textBrowser_anchorClicked(const QUrl &arg1);

private:
    Ui::mywidget *ui;
};
#endif // MYWIDGET_H
