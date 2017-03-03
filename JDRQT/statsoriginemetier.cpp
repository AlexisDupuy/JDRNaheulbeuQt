#include "statsoriginemetier.h"

StatsOrigineMetier::StatsOrigineMetier(QWidget *parent) : QWidget(parent)
{
    init();
    handle();
}

void StatsOrigineMetier::init(){
    m_lancerStats = new QPushButton("Génerer Stats",this);
    m_lancerOr = new QPushButton("Génerer Or",this);
    m_lancerDestin = new QPushButton("Génerer Destin",this);


    stat1 = new QLabel(this);
    stat2 = new QLabel(this);
    stat3 = new QLabel(this);
    stat4 = new QLabel(this);
    stat5 = new QLabel(this);

    or1 = new QLabel(this);
    or2 = new QLabel(this);

    totalOr = new QLabel(this);

    destin = new QLabel(this);

    QGL = new QGridLayout(this);
    QGL->addWidget(m_lancerStats, 1, 1);
    QGL->addWidget(stat1, 2, 1);
    QGL->addWidget(stat2, 3, 1);
    QGL->addWidget(stat3, 4, 1);
    QGL->addWidget(stat4, 5, 1);
    QGL->addWidget(stat5, 6, 1);

    QGL->addWidget(m_lancerOr, 1, 2);
    QGL->addWidget(or1, 2, 2);
    QGL->addWidget(or2, 3, 2);
    QGL->addWidget(totalOr, 4, 2);


    QGL->addWidget(m_lancerDestin, 1, 3);
    QGL->addWidget(destin, 2, 3);
}

void StatsOrigineMetier::handle(){
    connect(m_lancerStats, &QPushButton::clicked, this, &StatsOrigineMetier::returnStats);
    connect(m_lancerOr, &QPushButton::clicked, this, &StatsOrigineMetier::returnOr);
    connect(m_lancerDestin, &QPushButton::clicked, this, &StatsOrigineMetier::returnDestin);
}

void StatsOrigineMetier::returnStats(){
    qsrand(qrand());
    stat1->setText(QString::number((qrand() % ((6))+1)+7));
    stat2->setText(QString::number((qrand() % ((6))+1)+7));
    stat3->setText(QString::number((qrand() % ((6))+1)+7));
    stat4->setText(QString::number((qrand() % ((6))+1)+7));
    stat5->setText(QString::number((qrand() % ((6))+1)+7));
}

void StatsOrigineMetier::returnOr(){
    qsrand(qrand());
    int numOr1 = (qrand() % (6))+1;
    int numOr2 = (qrand() % (6))+1;
    or1->setText(QString::number(numOr1));
    or2->setText(QString::number(numOr2));
    totalOr->setText(QString::number((numOr1+numOr2)*10));
}

void StatsOrigineMetier::returnDestin(){
    qsrand(qrand());
    destin->setText(QString::number((qrand() % (4))));
}

StatsOrigineMetier::~StatsOrigineMetier(){

}
