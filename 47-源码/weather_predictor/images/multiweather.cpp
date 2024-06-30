#include "multiweather.h"
#include "ui_multiweather.h"

Multiweather::Multiweather(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Multiweather)
{
    ui->setupUi(this);
}

Multiweather::~Multiweather()
{
    delete ui;
}
