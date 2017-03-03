#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QPointer>
#include <QMessageBox>
#include <QComboBox>
#include <QPushButton>
#include <statsoriginemetier.h>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPointer<QPushButton> m_submit;
    QMessageBox m_msgBox;
    QPointer<QLineEdit> m_name;
    QComboBox *m_sexe;

    QPointer<QLineEdit> m_force;
    QPointer<QLineEdit> m_intel;
    QPointer<QLineEdit> m_adresse;
    QPointer<QLineEdit> m_charisme;
    QPointer<QLineEdit> m_courage;
    QPointer<QLineEdit> m_or;
    QPointer<QLineEdit> m_destin;



    QComboBox *m_origin;
    QComboBox *m_metier;



    QPushButton *m_stats;
    StatsOrigineMetier *SOMW;


    void init();
    void handle();

private slots:
    void submit();
    void openStatsWindow();
    void updateAvailableOrigines();
    void updateAvailableJobs();

};

#endif // WIDGET_H
