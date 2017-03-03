#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    init();
    handle();
}
void Widget::init(){

    m_submit = new QPushButton("Valider",this);
    m_stats = new QPushButton("Génerer stats",this);

    m_name = new QLineEdit();
    m_force = new QLineEdit();
    m_intel = new QLineEdit();
    m_adresse = new QLineEdit();
    m_charisme = new QLineEdit();
    m_courage = new QLineEdit();
    m_or = new QLineEdit();
    m_destin = new QLineEdit();

//remplissage de la liste sexe
    m_sexe = new QComboBox();
    m_sexe->addItem("Homme");
    m_sexe->addItem("Femme");

//remplissage de la liste origine
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

//remplissage de la liste metier
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

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("Entrez votre nom :","labelname"), m_name);
    formLayout->addRow(tr("Selectionnez votre sexe :","labelsexe"), m_sexe);
    formLayout->addRow(tr("Entrez votre force :","labelforce"), m_force);
    formLayout->addRow(tr("Entrez votre intelligence :","labelintel"), m_intel);
    formLayout->addRow(tr("Entrez votre adresse :","labeladresse"), m_adresse);
    formLayout->addRow(tr("Entrez votre charisme :","labelcharisme"), m_charisme);
    formLayout->addRow(tr("Entrez votre courage :","labelcourage"), m_courage);
    formLayout->addRow(tr("Entrez votre or :","labelor"), m_or);
    formLayout->addRow(tr("Entrez votre destin :","labeldestin"), m_destin);
    formLayout->addRow(tr("Selectionnez votre origine :","labelorigin"), m_origin);
    formLayout->addRow(tr("Selectionnez votre métier :","labelmetier"), m_metier);
    formLayout->addRow(m_stats);
    formLayout->addRow(m_submit);

    setLayout(formLayout);
}

void Widget::handle(){
    QObject::connect(m_submit.data(), &QPushButton::clicked, this, &Widget::submit);
    QObject::connect(m_stats, &QPushButton::clicked, this, &Widget::openStatsWindow);
    QObject::connect(m_force, &QLineEdit::textEdited, this, &Widget::updateAvailableOrigines);
    QObject::connect(m_intel, &QLineEdit::textEdited, this, &Widget::updateAvailableOrigines);
    QObject::connect(m_charisme, &QLineEdit::textEdited, this, &Widget::updateAvailableOrigines);
    QObject::connect(m_courage, &QLineEdit::textEdited, this, &Widget::updateAvailableOrigines);
    QObject::connect(m_adresse, &QLineEdit::textEdited, this, &Widget::updateAvailableOrigines);
    QObject::connect(m_force, &QLineEdit::textEdited, this, &Widget::updateAvailableJobs);
    QObject::connect(m_intel, &QLineEdit::textEdited, this, &Widget::updateAvailableJobs);
    QObject::connect(m_charisme, &QLineEdit::textEdited, this, &Widget::updateAvailableJobs);
    QObject::connect(m_courage, &QLineEdit::textEdited, this, &Widget::updateAvailableJobs);
    QObject::connect(m_adresse, &QLineEdit::textEdited, this, &Widget::updateAvailableJobs);
    QObject::connect(m_origin, &QComboBox::currentTextChanged, this, &Widget::updateAvailableJobs);
}


void Widget::submit(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    m_msgBox.setText("Bravo vous avez créé un " + m_origin->currentText() +" " + m_metier->currentText() + " " + m_sexe->currentText() +". \nSon nom est ... " + m_name->text() + " !" );
    m_msgBox.exec();
}

void Widget::openStatsWindow(){
    SOMW = new StatsOrigineMetier();
    SOMW->show();
}

void Widget::updateAvailableOrigines(){
    int force = m_force->text().toInt();
    int intel = m_intel->text().toInt();
    int charisme = m_charisme->text().toInt();
    int courage = m_courage->text().toInt();
    int adresse = m_adresse->text().toInt();
    m_origin->clear();
    m_origin->addItem("Humain");
    if(force >= 13 && courage >= 12){
        m_origin->addItem("Barbare");
    }
    if(force >= 12 && courage >= 11){
        m_origin->addItem("Nain");
    }
    if(charisme >= 12 && adresse >= 12 && intel >= 11 && force <= 12){
        m_origin->addItem("Haut Elfe");
    }
    if(charisme >= 10 && adresse >= 11){
        m_origin->addItem("Demi-Elfe");
    }
    if(charisme >= 12 && adresse >= 10 && force <= 11){
        m_origin->addItem("Elfe Sylvain");
    }
    if(adresse >= 13 && intel >= 12 && force <= 12){
        m_origin->addItem("Elfe Noir");
    }
    if(courage <= 10 && intel <= 8 && force >= 12){
        m_origin->addItem("Orque");
    }
    if(adresse <= 10 && intel <= 10 && force >= 12){
        m_origin->addItem("Demi-Orque");
    }
    if(courage <= 10 && intel <= 10 && force <= 9 && charisme <= 8){
        m_origin->addItem("Gobelin");
    }
    if(charisme <= 10 && intel <= 9 && adresse <= 11 && force >= 13){
        m_origin->addItem("Ogre");
    }
    if(courage >= 12 && intel >= 10 && force >= 10){
        m_origin->addItem("Semi-Homme");
    }
    if(adresse >= 13 && intel >= 10 && force <= 8){
        m_origin->addItem("Gnôme");
    }
}

void Widget::updateAvailableJobs(){
    int force = m_force->text().toInt();
    int intel = m_intel->text().toInt();
    int charisme = m_charisme->text().toInt();
    int courage = m_courage->text().toInt();
    int adresse = m_adresse->text().toInt();
    m_metier->clear();
    if(force >= 12 && courage >= 12){
        m_metier->addItem("Guerrier");
    }
    if(adresse >= 13){
        m_metier->addItem("Assassin");
    }
    if(adresse >= 12){
        m_metier->addItem("Voleur");
    }
    if(charisme >= 10 && adresse >= 10){
        m_metier->addItem("Ranger");
    }
    if(charisme >= 12 && adresse >= 11){
        m_metier->addItem("Ménestrel");
    }
    if(adresse >= 11 && courage >= 11){
        m_origin->addItem("Pirate");
    }
    if(charisme >= 11 && intel >= 12){
        m_origin->addItem("Marchand");
    }
    if(adresse >= 11){
        m_origin->addItem("Ingénieur");
    }
    if(charisme >= 11 && intel >= 10){
        m_origin->addItem("Noble");
    }
    if(m_origin->currentText() != "Barbare" &&
            m_origin->currentText() != "Nain" &&
            m_origin->currentText() != "Orque" &&
            m_origin->currentText() != "Ogre" &&
            m_origin->currentText() != "Demi-Orque" &&
            m_origin->currentText() != "Orque" &&
            m_origin->currentText() != "Gnôme" &&
            m_origin->currentText() != "Semi-Homme" &&
            m_origin->currentText() != "Gobelin"
            ){
        if(charisme >= 12){
            m_metier->addItem("Prêtre");
        }
        if(intel >= 12){
            m_metier->addItem("Mage");
        }
        if(charisme >= 11 && courage >= 12 && intel >= 10 && force >= 9){
            m_metier->addItem("Paladin");
        }
    }

}

Widget::~Widget()
{
    delete m_stats;
}
