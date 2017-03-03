#include "statsoriginemetier.h"

StatsOrigineMetier::StatsOrigineMetier(QWidget *parent) : QWidget(parent)
{
    btnLancerStats = new QPushButton(this);
    connect(btnLancerStats, SIGNAL(clicked()), this, SLOT(returnStats()));
    stat1 = new QLabel(this);
    stat2 = new QLabel(this);
    stat3 = new QLabel(this);
    stat4 = new QLabel(this);
    stat5 = new QLabel(this);
    QGL = new QGridLayout(this);
    QGL->addWidget(stat1);
    QGL->addWidget(stat2);
    QGL->addWidget(stat3);
    QGL->addWidget(stat4);
    QGL->addWidget(stat5);
}

void StatsOrigineMetier::returnStats(){
    qsrand(qrand());
    stat1->setText(QString::number((qrand() % ((6))+1)+7));
    stat2->setText(QString::number((qrand() % ((6))+1)+7));
    stat3->setText(QString::number((qrand() % ((6))+1)+7));
    stat4->setText(QString::number((qrand() % ((6))+1)+7));
    stat5->setText(QString::number((qrand() % ((6))+1)+7));
}

StatsOrigineMetier::~StatsOrigineMetier(){

}
