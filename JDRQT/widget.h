#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
<<<<<<< HEAD
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QPointer>
#include <QMessageBox>
#include <QComboBox>

=======
#include <QPushButton>
#include <statsoriginemetier.h>
>>>>>>> dda14d6791868e41cb2bdeba6aa62165931c3a1c

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
<<<<<<< HEAD
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

=======
    QPushButton *btnStats;
    StatsOrigineMetier *SOMW;

private slots:
    void openStatsWindow();
>>>>>>> dda14d6791868e41cb2bdeba6aa62165931c3a1c
};

#endif // WIDGET_H
