#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <statsoriginemetier.h>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *btnStats;
    StatsOrigineMetier *SOMW;

private slots:
    void openStatsWindow();
};

#endif // WIDGET_H
