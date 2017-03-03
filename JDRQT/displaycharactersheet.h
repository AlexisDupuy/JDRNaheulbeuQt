#ifndef DISPLAYCHARACTERSHEET_H
#define DISPLAYCHARACTERSHEET_H

#include <QWidget>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPointer>
#include <QMessageBox>
#include <QComboBox>
#include <QGridLayout>
#include <statsoriginemetier.h>
#include <modeljson.h>

class displayCharacterSheet : public QWidget
{
    Q_OBJECT
public:
    explicit displayCharacterSheet(QWidget *parent = 0);

private:
    QPointer<QLabel> m_nameLabel;
    QPointer<QLineEdit> m_name;
    QPointer<QLabel> m_sexeLabel;
    QComboBox *m_sexe;
    QPointer<QLabel> m_evLabel;
    QPointer<QLabel> m_maxLabel;
    QPointer<QLineEdit> m_evMax;
    QPointer<QLineEdit> m_damage1;
    QPointer<QLineEdit> m_damage2;
    QPointer<QLineEdit> m_damage3;
    QPointer<QLineEdit> m_damage4;
    QPointer<QLineEdit> m_damage5;
    QPointer<QLineEdit> m_damage6;
    QPointer<QLineEdit> m_damage7;
    QPointer<QLineEdit> m_damage8;
    QPointer<QLineEdit> m_damage9;
    QPointer<QLineEdit> m_damage10;
    QPointer<QLineEdit> m_damage11;
    QPointer<QLineEdit> m_damage12;
    QPointer<QLineEdit> m_damage13;


    QPointer<QLabel> m_eaLabel;
    QPointer<QLineEdit> m_eaMax;
    QPointer<QLineEdit> m_eaComsumption1;
    QPointer<QLineEdit> m_eaComsumption2;
    QPointer<QLineEdit> m_eaComsumption3;
    QPointer<QLineEdit> m_eaComsumption4;
    QPointer<QLineEdit> m_eaComsumption5;
    QPointer<QLineEdit> m_eaComsumption6;


    QPointer<QLabel> m_magPhyLabel;
    QPointer<QLineEdit> m_magPhy;

    QPointer<QLabel> m_magPsyLabel;
    QPointer<QLineEdit> m_magPsy;

    QPointer<QLabel> m_resMagLabel;
    QPointer<QLineEdit> m_resMag;

    QPointer<QLabel> m_courageLabel;
    QPointer<QLineEdit> m_courage;
    QPointer<QLineEdit> m_modCourage1;
    QPointer<QLineEdit> m_modCourage2;
    QPointer<QLineEdit> m_modCourage3;
    QPointer<QLineEdit> m_modCourage4;
    QPointer<QLineEdit> m_modCourage5;
    QPointer<QLineEdit> m_modCourage6;

    QPointer<QLabel> m_intelLabel;
    QPointer<QLineEdit> m_intel;
    QPointer<QLineEdit> m_modIntel1;
    QPointer<QLineEdit> m_modIntel2;
    QPointer<QLineEdit> m_modIntel3;
    QPointer<QLineEdit> m_modIntel4;
    QPointer<QLineEdit> m_modIntel5;
    QPointer<QLineEdit> m_modIntel6;

    QPointer<QLabel> m_charismeLabel;
    QPointer<QLineEdit> m_charisme;
    QPointer<QLineEdit> m_modCharisme1;
    QPointer<QLineEdit> m_modCharisme2;
    QPointer<QLineEdit> m_modCharisme3;
    QPointer<QLineEdit> m_modCharisme4;
    QPointer<QLineEdit> m_modCharisme5;
    QPointer<QLineEdit> m_modCharisme6;

    QPointer<QLabel> m_adresseLabel;
    QPointer<QLineEdit> m_adresse;
    QPointer<QLineEdit> m_modAdresse1;
    QPointer<QLineEdit> m_modAdresse2;
    QPointer<QLineEdit> m_modAdresse3;
    QPointer<QLineEdit> m_modAdresse4;
    QPointer<QLineEdit> m_modAdresse5;
    QPointer<QLineEdit> m_modAdresse6;

    QPointer<QLabel> m_forceLabel;
    QPointer<QLineEdit> m_force;
    QPointer<QLineEdit> m_modForce1;
    QPointer<QLineEdit> m_modForce2;
    QPointer<QLineEdit> m_modForce3;
    QPointer<QLineEdit> m_modForce4;
    QPointer<QLineEdit> m_modForce5;
    QPointer<QLineEdit> m_modForce6;

    QPointer<QLabel> m_attaqueLabel;
    QPointer<QLineEdit> m_attaque;
    QPointer<QLineEdit> m_modAttaque1;
    QPointer<QLineEdit> m_modAttaque2;
    QPointer<QLineEdit> m_modAttaque3;
    QPointer<QLineEdit> m_modAttaque4;
    QPointer<QLineEdit> m_modAttaque5;
    QPointer<QLineEdit> m_modAttaque6;

    QPointer<QLabel> m_paradeLabel;
    QPointer<QLineEdit> m_parade;
    QPointer<QLineEdit> m_modParade1;
    QPointer<QLineEdit> m_modParade2;
    QPointer<QLineEdit> m_modParade3;
    QPointer<QLineEdit> m_modParade4;
    QPointer<QLineEdit> m_modParade5;
    QPointer<QLineEdit> m_modParade6;


    QPointer<QLineEdit> m_or;
    QPointer<QLineEdit> m_destin;
    QPointer<ModelJSON> m_model;
    QPointer<QGridLayout> m_layout;

    QPointer<QLabel> m_originLabel;
    QComboBox *m_origin;
    QPointer<QLabel> m_metierLabel;
    QComboBox *m_metier;

    QPushButton *m_stats;
    StatsOrigineMetier *SOMW;
    void init();
signals:

public slots:
};

#endif // DISPLAYCHARACTERSHEET_H
