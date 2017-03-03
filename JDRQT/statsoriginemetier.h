#ifndef STATSORIGINEMETIER_H
#define STATSORIGINEMETIER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class StatsOrigineMetier : public QWidget
{
    Q_OBJECT
public:
    StatsOrigineMetier(QWidget *parent = 0);
    ~StatsOrigineMetier();
    QPushButton *btnLancerStats;
    QLabel *stat1;
    QLabel *stat2;
    QLabel *stat3;
    QLabel *stat4;
    QLabel *stat5;
    QGridLayout *QGL;
signals:

private slots:
    void returnStats();
};

#endif // STATSORIGINEMETIER_H
