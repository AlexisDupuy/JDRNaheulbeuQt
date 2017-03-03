#ifndef STATSORIGINEMETIER_H
#define STATSORIGINEMETIER_H

#include <QWidget>
#include <QPointer>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class StatsOrigineMetier : public QWidget
{
    Q_OBJECT
public:
    StatsOrigineMetier(QWidget *parent = 0);
    ~StatsOrigineMetier();
    QPointer<QPushButton> m_lancerStats;
    QPointer<QPushButton> m_lancerOr;
    QPointer<QPushButton> m_lancerDestin;

    QPointer<QLabel> stat1;
    QPointer<QLabel> stat2;
    QPointer<QLabel> stat3;
    QPointer<QLabel> stat4;
    QPointer<QLabel> stat5;

    QPointer<QLabel> or1;
    QPointer<QLabel> or2;
    QPointer<QLabel> totalOr;

    QPointer<QLabel> destin;

    QGridLayout *QGL;
    void handle();
    void init();


private slots:
    void returnStats();
    void returnOr();
    void returnDestin();
};

#endif // STATSORIGINEMETIER_H
