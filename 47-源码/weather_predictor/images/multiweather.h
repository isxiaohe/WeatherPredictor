#ifndef MULTIWEATHER_H
#define MULTIWEATHER_H

#include <QDialog>

namespace Ui {
class Multiweather;
}

class Multiweather : public QDialog
{
    Q_OBJECT

public:
    explicit Multiweather(QWidget *parent = nullptr);
    ~Multiweather();

private:
    Ui::Multiweather *ui;
};

#endif // MULTIWEATHER_H
