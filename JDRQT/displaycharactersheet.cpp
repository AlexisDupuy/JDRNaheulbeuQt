#include "displaycharactersheet.h"

displayCharacterSheet::displayCharacterSheet(QWidget *parent) : QWidget(parent)
{
    init();
}

void displayCharacterSheet::init(){
    m_layout = new QGridLayout();

    m_eaLabel = new QLabel("EA");
    m_evLabel = new QLabel("EV");
    m_maxLabel = new QLabel("MAX");
    m_nameLabel = new QLabel("Nom");
    m_sexeLabel = new QLabel("Sexe");
    m_magPhyLabel = new QLabel("Mag Phy");
    m_magPsyLabel = new QLabel("Mag Psy");
    m_resMagLabel = new QLabel("Res Mag");
    m_courageLabel = new QLabel("Courage");
    m_intelLabel = new QLabel("Intelligence");
    m_charismeLabel = new QLabel("Charisme");
    m_adresseLabel = new QLabel("Adresse");
    m_forceLabel = new QLabel("Force");
    m_originLabel = new QLabel("Origine");
    m_metierLabel = new QLabel("Métier");
    m_attaqueLabel = new QLabel("Attaque");
    m_paradeLabel = new QLabel("Parade");



    m_name = new QLineEdit();
    m_sexe = new QComboBox();
    m_evMax = new QLineEdit();
    m_damage1 = new QLineEdit();
    m_damage2 = new QLineEdit();
    m_damage3 = new QLineEdit();
    m_damage4 = new QLineEdit();
    m_damage5 = new QLineEdit();
    m_damage6 = new QLineEdit();
    m_damage7 = new QLineEdit();
    m_damage8 = new QLineEdit();
    m_damage9 = new QLineEdit();
    m_damage10 = new QLineEdit();
    m_damage11 = new QLineEdit();
    m_damage12 = new QLineEdit();
    m_damage13 = new QLineEdit();


    m_eaMax = new QLineEdit();
    m_eaComsumption1 = new QLineEdit();
    m_eaComsumption2 = new QLineEdit();
    m_eaComsumption3 = new QLineEdit();
    m_eaComsumption4 = new QLineEdit();
    m_eaComsumption5 = new QLineEdit();
    m_eaComsumption6 = new QLineEdit();

    m_magPhy = new QLineEdit();
    m_magPsy = new QLineEdit();
    m_resMag = new QLineEdit();


    m_courage = new QLineEdit();
    m_modCourage1 = new QLineEdit();
    m_modCourage2 = new QLineEdit();
    m_modCourage3 = new QLineEdit();
    m_modCourage4 = new QLineEdit();
    m_modCourage5 = new QLineEdit();
    m_modCourage6 = new QLineEdit();

    m_intel = new QLineEdit();
    m_modIntel1 = new QLineEdit();
    m_modIntel2 = new QLineEdit();
    m_modIntel3 = new QLineEdit();
    m_modIntel4 = new QLineEdit();
    m_modIntel5 = new QLineEdit();
    m_modIntel6 = new QLineEdit();

    m_charisme = new QLineEdit();
    m_modCharisme1 = new QLineEdit();
    m_modCharisme2 = new QLineEdit();
    m_modCharisme3 = new QLineEdit();
    m_modCharisme4 = new QLineEdit();
    m_modCharisme5 = new QLineEdit();
    m_modCharisme6 = new QLineEdit();

    m_adresse = new QLineEdit();
    m_modAdresse1 = new QLineEdit();
    m_modAdresse2 = new QLineEdit();
    m_modAdresse3 = new QLineEdit();
    m_modAdresse4 = new QLineEdit();
    m_modAdresse5 = new QLineEdit();
    m_modAdresse6 = new QLineEdit();

    m_force = new QLineEdit();
    m_modForce1 = new QLineEdit();
    m_modForce2 = new QLineEdit();
    m_modForce3 = new QLineEdit();
    m_modForce4 = new QLineEdit();
    m_modForce5 = new QLineEdit();
    m_modForce6 = new QLineEdit();

    m_attaque = new QLineEdit();
    m_modAttaque1 = new QLineEdit();
    m_modAttaque2 = new QLineEdit();
    m_modAttaque3 = new QLineEdit();
    m_modAttaque4 = new QLineEdit();
    m_modAttaque5 = new QLineEdit();
    m_modAttaque6 = new QLineEdit();

    m_parade = new QLineEdit();
    m_modParade1 = new QLineEdit();
    m_modParade2 = new QLineEdit();
    m_modParade3 = new QLineEdit();
    m_modParade4 = new QLineEdit();
    m_modParade5 = new QLineEdit();
    m_modParade6 = new QLineEdit();


    m_origin = new QComboBox();
    m_origin->addItem("Humain");
    m_origin->addItem("Barbare");
    m_origin->addItem("Nain");
    m_origin->addItem("Haut Elfe");
    m_origin->addItem("Demi-Elfe");
    m_origin->addItem("Elfe Sylvain");
    m_origin->addItem("Elfe Noir");
    m_origin->addItem("Orque");
    m_origin->addItem("Demi-Orque");
    m_origin->addItem("Gobelin");
    m_origin->addItem("Ogre");
    m_origin->addItem("Semi-homme");
    m_origin->addItem("Gnôme");


    m_metier = new QComboBox();
    m_metier->addItem("Guerrier");
    m_metier->addItem("Assassin");
    m_metier->addItem("Voleur");
    m_metier->addItem("Prêtre");
    m_metier->addItem("Mage");
    m_metier->addItem("Paladin");
    m_metier->addItem("Ranger");
    m_metier->addItem("Ménestrel");
    m_metier->addItem("Pirate");
    m_metier->addItem("Marchand");
    m_metier->addItem("Ingénieur");
    m_metier->addItem("Noble");

    m_or = new QLineEdit();
    m_destin = new QLineEdit();
    m_layout->addWidget(m_nameLabel, 0, 3);
    m_layout->addWidget(m_name, 0, 4, 1, 5);
    m_layout->addWidget(m_sexeLabel, 0, 10);
    m_layout->addWidget(m_sexe, 0, 11, 1, 4);
    m_layout->addWidget(m_originLabel, 1, 3);
    m_layout->addWidget(m_origin, 1, 4, 1, 3);
    m_layout->addWidget(m_metierLabel, 1, 10);
    m_layout->addWidget(m_metier, 1, 9, 1, 6);

    m_layout->addWidget(m_maxLabel, 2, 7);
    m_layout->addWidget(m_evLabel, 3, 6);
    m_layout->addWidget(m_evMax, 3, 7);
    m_layout->addWidget(m_damage1, 3, 8);
    m_layout->addWidget(m_damage2, 3, 9);
    m_layout->addWidget(m_damage3, 3, 10);
    m_layout->addWidget(m_damage4, 3, 11);
    m_layout->addWidget(m_damage5, 3, 12);
    m_layout->addWidget(m_damage6, 3, 13);
    m_layout->addWidget(m_damage7, 4, 7);
    m_layout->addWidget(m_damage8, 4, 8);
    m_layout->addWidget(m_damage9, 4, 9);
    m_layout->addWidget(m_damage10, 4, 10);
    m_layout->addWidget(m_damage11, 4, 11);
    m_layout->addWidget(m_damage12, 4, 12);
    m_layout->addWidget(m_damage13, 4, 13);

    m_layout->addWidget(m_maxLabel, 5, 7);
    m_layout->addWidget(m_eaLabel, 6, 6);
    m_layout->addWidget(m_eaMax, 6, 7);
    m_layout->addWidget(m_eaComsumption1, 6, 8);
    m_layout->addWidget(m_eaComsumption2, 6, 9);
    m_layout->addWidget(m_eaComsumption3, 6, 10);
    m_layout->addWidget(m_eaComsumption4, 6, 11);
    m_layout->addWidget(m_eaComsumption5, 6, 12);
    m_layout->addWidget(m_eaComsumption6, 6, 13);
    setLayout(m_layout);

}
