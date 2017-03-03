#include "displaycharactersheet.h"

displayCharacterSheet::displayCharacterSheet(QWidget *parent) : QWidget(parent)
{
    init();
}

void displayCharacterSheet::init(){
    m_layout = new QGridLayout();

    m_eaLabel = new QLabel("Energie Astrale (EA-PA)");
    m_evLabel = new QLabel("Energie Vitale (EV-PV)");
    m_maxLabel = new QLabel("MAX");
    m_maxLabel2 = new QLabel("MAX");
    m_nameLabel = new QLabel("Nom");
    m_sexeLabel = new QLabel("Sexe");
    m_magPhyLabel = new QLabel("Magie Phys.");
    m_magPsyLabel = new QLabel("Magie Psy.");
    m_resMagLabel = new QLabel("Résist. Magie");
    m_courageLabel = new QLabel("Courage");
    m_intelLabel = new QLabel("Intelligence");
    m_charismeLabel = new QLabel("Charisme");
    m_adresseLabel = new QLabel("Adresse");
    m_forceLabel = new QLabel("Force");
    m_originLabel = new QLabel("Origine");
    m_origLabel = new QLabel("ORIG.");
    m_metierLabel = new QLabel("Métier");
    m_attaqueLabel = new QLabel("Attaque");
    m_paradeLabel = new QLabel("Parade");
   // m_lvlLabel = new QLabel("NIVEAU");
    //m_xpLabel = new QLabel("Expérience");
    //m_orLabel = new QLabel("Ma fortune");
   // m_destinLabel = new QLabel("Points de destin");



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
    //m_lvl = new QLineEdit();
    //m_xp = new QLineEdit();
    m_layout->addWidget(m_nameLabel, 0, 3, 1, 1);
    m_layout->addWidget(m_name, 0, 4, 1, 5);
    m_layout->addWidget(m_sexeLabel, 0, 9, 1, 1);
    m_layout->addWidget(m_sexe, 0, 10, 1, 4);
    m_layout->addWidget(m_originLabel, 1, 3, 1, 1);
    m_layout->addWidget(m_origin, 1, 4, 1, 3);
    m_layout->addWidget(m_metierLabel, 1, 7, 1, 1);
    m_layout->addWidget(m_metier, 1, 8, 1, 6);

    m_layout->addWidget(m_maxLabel, 2, 7, 1, 1);
    m_layout->addWidget(m_evLabel, 3, 6, 1, 3);
    m_layout->addWidget(m_evMax, 3, 7, 1, 1);
    m_layout->addWidget(m_damage1, 3, 8, 1, 1);
    m_layout->addWidget(m_damage2, 3, 9, 1, 1);
    m_layout->addWidget(m_damage3, 3, 10, 1, 1);
    m_layout->addWidget(m_damage4, 3, 11, 1, 1);
    m_layout->addWidget(m_damage5, 3, 12, 1, 1);
    m_layout->addWidget(m_damage6, 3, 13, 1, 1);
    m_layout->addWidget(m_damage7, 4, 7, 1, 1);
    m_layout->addWidget(m_damage8, 4, 8, 1, 1);
    m_layout->addWidget(m_damage9, 4, 9, 1, 1);
    m_layout->addWidget(m_damage10, 4, 10, 1, 1);
    m_layout->addWidget(m_damage11, 4, 11, 1, 1);
    m_layout->addWidget(m_damage12, 4, 12, 1, 1);
    m_layout->addWidget(m_damage13, 4, 13, 1, 1);

    m_layout->addWidget(m_maxLabel2, 5, 7, 1, 1);
    m_layout->addWidget(m_eaLabel, 6, 6, 1, 3);
    m_layout->addWidget(m_eaMax, 6, 7, 1, 1);
    m_layout->addWidget(m_eaComsumption1, 6, 8, 1, 1);
    m_layout->addWidget(m_eaComsumption2, 6, 9, 1, 1);
    m_layout->addWidget(m_eaComsumption3, 6, 10, 1, 1);
    m_layout->addWidget(m_eaComsumption4, 6, 11, 1, 1);
    m_layout->addWidget(m_eaComsumption5, 6, 12, 1, 1);
    m_layout->addWidget(m_eaComsumption6, 6, 13, 1, 1);

    //m_layout->addWidget(m_lvlLabel, 7, 0, 1, 1);
    //m_layout->addWidget(m_lvl, 7, 1, 1, 1);
    m_layout->addWidget(m_magPhyLabel, 7, 5, 1, 1);
    m_layout->addWidget(m_magPsyLabel, 7, 8, 1, 1);
    m_layout->addWidget(m_resMagLabel, 7, 12, 1, 1);
    m_layout->addWidget(m_magPhy, 7, 6, 1, 1);
    m_layout->addWidget(m_magPsy, 7, 9, 1, 1);
    m_layout->addWidget(m_resMag, 7, 13, 1, 1);

    //m_layout->addWidget(m_xpLabel, 8, 0, 1, 1);
    //m_layout->addWidget(m_xp, 8, 1, 1, 1);
    m_layout->addWidget(m_origLabel, 8, 6, 1, 1);
    m_layout->addWidget(m_courageLabel, 9, 4, 1, 2);
    m_layout->addWidget(m_courage, 9, 6, 1, 1);
    m_layout->addWidget(m_modCourage1, 9, 8, 1, 1);
    m_layout->addWidget(m_modCourage2, 9, 9, 1, 1);
    m_layout->addWidget(m_modCourage3, 9, 10, 1, 1);
    m_layout->addWidget(m_modCourage4, 9, 11, 1, 1);
    m_layout->addWidget(m_modCourage5, 9, 12, 1, 1);
    m_layout->addWidget(m_modCourage6, 9, 13, 1, 1);

    //m_layout->addWidget(m_destinLabel, 10, 0, 1, 1);
    m_layout->addWidget(m_destin, 10, 1, 1, 1);
    m_layout->addWidget(m_intelLabel, 10, 4, 1, 2);
    m_layout->addWidget(m_intel, 10, 6, 1, 1);
    m_layout->addWidget(m_modIntel1, 10, 8, 1, 1);
    m_layout->addWidget(m_modIntel2, 10, 9, 1, 1);
    m_layout->addWidget(m_modIntel3, 10, 10, 1, 1);
    m_layout->addWidget(m_modIntel4, 10, 11, 1, 1);
    m_layout->addWidget(m_modIntel5, 10, 12, 1, 1);
    m_layout->addWidget(m_modIntel6, 10, 13, 1, 1);


    m_layout->addWidget(m_charismeLabel, 11, 4, 1, 2);
    m_layout->addWidget(m_charisme, 11, 6, 1, 1);
    m_layout->addWidget(m_modCharisme1, 11, 8, 1, 1);
    m_layout->addWidget(m_modCharisme2, 11, 9, 1, 1);
    m_layout->addWidget(m_modCharisme3, 11, 10, 1, 1);
    m_layout->addWidget(m_modCharisme4, 11, 11, 1, 1);
    m_layout->addWidget(m_modCharisme5, 11, 12, 1, 1);
    m_layout->addWidget(m_modCharisme6, 11, 13, 1, 1);


    //m_layout->addWidget(m_orLabel, 12, 2);
    m_layout->addWidget(m_or, 12, 1, 1, 1);
    m_layout->addWidget(m_adresseLabel, 12, 4, 1, 2);
    m_layout->addWidget(m_adresse, 12, 6, 1, 1);
    m_layout->addWidget(m_modAdresse1, 12, 8, 1, 1);
    m_layout->addWidget(m_modAdresse2, 12, 9, 1, 1);
    m_layout->addWidget(m_modAdresse3, 12, 10, 1, 1);
    m_layout->addWidget(m_modAdresse4, 12, 11, 1, 1);
    m_layout->addWidget(m_modAdresse5, 12, 12, 1, 1);
    m_layout->addWidget(m_modAdresse6, 12, 13, 1, 1);

    m_layout->addWidget(m_forceLabel, 13, 4, 1, 2);
    m_layout->addWidget(m_force, 13, 6, 1, 1);
    m_layout->addWidget(m_modForce1, 13, 8, 1, 1);
    m_layout->addWidget(m_modForce2, 13, 9, 1, 1);
    m_layout->addWidget(m_modForce3, 13, 10, 1, 1);
    m_layout->addWidget(m_modForce4, 13, 11, 1, 1);
    m_layout->addWidget(m_modForce5, 13, 12, 1, 1);
    m_layout->addWidget(m_modForce6, 13, 13, 1, 1);

    m_layout->addWidget(m_attaqueLabel, 15, 4, 1, 2);
    m_layout->addWidget(m_attaque, 15, 6, 1, 1);
    m_layout->addWidget(m_modAttaque1, 15, 8, 1, 1);
    m_layout->addWidget(m_modAttaque2, 15, 9, 1, 1);
    m_layout->addWidget(m_modAttaque3, 15, 10, 1, 1);
    m_layout->addWidget(m_modAttaque4, 15, 11, 1, 1);
    m_layout->addWidget(m_modAttaque5, 15, 12, 1, 1);
    m_layout->addWidget(m_modAttaque6, 15, 13, 1, 1);

    m_layout->addWidget(m_paradeLabel, 16, 4, 1, 2);
    m_layout->addWidget(m_parade, 16, 6, 1, 1);
    m_layout->addWidget(m_modParade1, 16, 8, 1, 1);
    m_layout->addWidget(m_modParade2, 16, 9, 1, 1);
    m_layout->addWidget(m_modParade3, 16, 10, 1, 1);
    m_layout->addWidget(m_modParade4, 16, 11, 1, 1);
    m_layout->addWidget(m_modParade5, 16, 12, 1, 1);
    m_layout->addWidget(m_modParade6, 16, 13, 1, 1);

    setLayout(m_layout);

}
