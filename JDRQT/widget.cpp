#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    btnStats = new QPushButton(this);
    connect(btnStats, SIGNAL(clicked()), this, SLOT(openStatsWindow()));
}

void Widget::openStatsWindow(){
    SOMW = new StatsOrigineMetier();
    SOMW->show();
}


Widget::~Widget()
{
    delete btnStats;
}
