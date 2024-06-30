#ifndef SEARCH_BOX_H
#define SEARCH_BOX_H

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
#include <QProcess>
#include <QListView>
#include <QStringListModel>
#include <QModelIndex>
#include"cityinfo.h"
#include"weathereachday.h"

namespace Ui {
class search_box;
}

class search_box:public QWidget
{
    Q_OBJECT
public:
    explicit search_box(QWidget* parent = 0);
    QString getBoxText();
    QString nowStr;
private:
    QLineEdit* search_edit1, search_edit2;
    QAction* search_action;
    QPushButton* search_btn;
    QTextBrowser* text;
    QListView* listview;
    QStringListModel* qlistmodel;
    Ui::search_box* ui;


// signals:
//     void itemClicked(QString);

public slots:

private slots:
    void on_search_btn_clicked();
    void on_listview_clicked(const QModelIndex &index);
};
#endif // SEARCH_BOX_H
