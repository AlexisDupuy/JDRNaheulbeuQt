#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPointer>
#include <QMessageBox>
#include <QComboBox>
#include <statsoriginemetier.h>
#include <modeljson.h>

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
    QPointer<ModelJSON> m_model;

    QComboBox *m_comp1;
    QComboBox *m_comp2;

    QComboBox *m_origin;
    QComboBox *m_metier;

    QPushButton *m_stats;
    StatsOrigineMetier *SOMW;


    void init();
    void handle();

private slots:
    void submit();
    void openStatsWindow();
<<<<<<< HEAD
    void updateAvailableOrigines();
    void updateAvailableJobs();
=======
    void genComp();
>>>>>>> d730d605e1b71617779be4899da3b6c847b21143

};

#endif // WIDGET_H
