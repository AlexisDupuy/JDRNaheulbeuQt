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
    QLineEdit *m_name;
    QComboBox *m_sexe;
    QComboBox *m_origin;
    QComboBox *m_metier;

    void init();
    void handle();

private slots:
      void submit();
    QPushButton *btnStats;
    StatsOrigineMetier *SOMW;

private slots:
    void openStatsWindow();
};

#endif // WIDGET_H
