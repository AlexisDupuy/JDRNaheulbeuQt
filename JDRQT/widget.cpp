#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    init();
    handle();
    genComp();
}
void Widget::init(){

    m_model = new ModelJSON();

    m_submit = new QPushButton("Valider",this);
    m_stats = new QPushButton("Génerer stats",this);
    m_armure = new QLineEdit(this);

    m_name = new QLineEdit(m_model->sNom());
    m_force = new QLineEdit(QString::number(m_model->iForce()));
    m_intel = new QLineEdit(QString::number(m_model->iIntel()));
    m_adresse = new QLineEdit(QString::number(m_model->iAddr()));
    m_charisme = new QLineEdit(QString::number(m_model->iChar()));
    m_courage = new QLineEdit(QString::number(m_model->iCourage()));
    m_or = new QLineEdit(QString::number(m_model->iOr()));
    m_destin = new QLineEdit(QString::number(m_model->iDestin()));

    //remplissage de la liste comp1
    m_comp1 = new QComboBox();
    m_comp1->setDuplicatesEnabled (false);

    //remplissage de la liste comp2
    m_comp2 = new QComboBox();
    m_comp2->setDuplicatesEnabled (false);

    //remplissage de la liste sexe
    m_sexe = new QComboBox();
    m_sexe->addItem("Homme");
    m_sexe->addItem("Femme");
    m_sexe->setCurrentText(m_model->sSexe());

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
    m_origin->setCurrentText(m_model->sOrigin());


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
    m_metier->setCurrentText(m_model->sMetier());

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
    formLayout->addRow(tr("Selectionnez votre compétence 1 :","labelcomp1"), m_comp1);
    formLayout->addRow(tr("Selectionnez votre compétence 2 :","labelcomp2"), m_comp2);
    formLayout->addRow(tr("Entrez votre armure : ", "labelarmure"), m_armure);
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
    QObject::connect(m_origin, &QComboBox::currentTextChanged, this, &Widget::genComp);
    QObject::connect(m_metier, &QComboBox::currentTextChanged, this, &Widget::genComp);
}


void Widget::submit(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    m_model->writeJson(m_name->text(), m_sexe->currentText(), m_origin->currentText(), m_metier->currentText(),QString::number(m_model->iEv()),QString::number(m_model->iEa()),QString::number(m_model->iMagPhy()),QString::number(m_model->iMagPsy()),QString::number(m_model->iResMag()),m_courage->text(),m_charisme->text(),m_intel->text(),m_adresse->text(),m_force->text(),QString::number(m_model->iAttaq()),QString::number(m_model->iParad()),QString::number(m_model->iNiveau()),QString::number(m_model->iExpe()),m_destin->text(),m_or->text(),QString::number(m_model->iPr()));
    m_msgBox.setText("Bravo vous avez créé un " + m_origin->currentText() +" " + m_metier->currentText() + " " + m_sexe->currentText() +". \nSon nom est ... " + m_name->text() + " !" );
    m_msgBox.exec();
}

void Widget::openStatsWindow(){
    SOMW = new StatsOrigineMetier();
    SOMW->show();
    m_stats->setEnabled(false);
}

void Widget::genComp(){
    m_comp1->clear();
    m_comp2->clear();

    if(m_origin->currentText()=="Barbare")
    {
        m_comp1->addItem("Armes de bourrin");
        m_comp1->addItem("Bourre-pif");
        m_comp1->addItem("Chevaucher");
        m_comp1->addItem("Escalader");
        m_comp1->addItem("Intimider");
        m_comp1->addItem("Nager");
        m_comp1->addItem("Pister");
        m_comp1->addItem("Tirer correctement");
        m_comp1->addItem("Truc de mauviette");

        m_comp2->addItem("Armes de bourrin");
        m_comp2->addItem("Bourre-pif");
        m_comp2->addItem("Chevaucher");
        m_comp2->addItem("Escalader");
        m_comp2->addItem("Intimider");
        m_comp2->addItem("Nager");
        m_comp2->addItem("Pister");
        m_comp2->addItem("Tirer correctement");
        m_comp2->addItem("Truc de mauviette");
    }else if(m_origin->currentText()=="Nain")
    {
        m_comp1->addItem("Appel des renforts");
        m_comp1->addItem("Arnaque et carambouille");
        m_comp1->addItem("Bourre-pif");
        m_comp1->addItem("Bricolo du dimanche");
        m_comp1->addItem("Chercher des noises");
        m_comp1->addItem("Fariboles");
        m_comp1->addItem("Forgeron");
        m_comp1->addItem("Mefiance");
        m_comp1->addItem("Tirer correctement(hache de jet)");
        m_comp1->addItem("Truc de mauviette");

        m_comp2->addItem("Appel des renforts");
        m_comp2->addItem("Arnaque et carambouille");
        m_comp2->addItem("Bourre-pif");
        m_comp2->addItem("Bricolo du dimanche");
        m_comp2->addItem("Chercher des noises");
        m_comp2->addItem("Fariboles");
        m_comp2->addItem("Forgeron");
        m_comp2->addItem("Mefiance");
        m_comp2->addItem("Tirer correctement(hache de jet)");
        m_comp2->addItem("Truc de mauviette");
    }else if(m_origin->currentText()=="Haut Elfe")
    {
        m_comp1->addItem("Chef de groupe");
        m_comp1->addItem("Chevaucher");
        m_comp1->addItem("Jonglage et danse");
        m_comp1->addItem("Nager");
        m_comp1->addItem("Premiers soins");
        m_comp1->addItem("Nager");
        m_comp1->addItem("Tirer correctement");

        m_comp2->addItem("Chef de groupe");
        m_comp2->addItem("Chevaucher");
        m_comp2->addItem("Jonglage et danse");
        m_comp2->addItem("Nager");
        m_comp2->addItem("Premiers soins");
        m_comp2->addItem("Nager");
        m_comp2->addItem("Tirer correctement");
    }else
    {
        m_comp1->addItem("Chevaucher");
        m_comp1->addItem("Escalader");
        m_comp1->addItem("Intimider");
        m_comp1->addItem("Nager");
        m_comp1->addItem("Pister");
        m_comp1->addItem("Truc de mauviette");

        m_comp2->addItem("Chevaucher");
        m_comp2->addItem("Escalader");
        m_comp2->addItem("Intimider");
        m_comp2->addItem("Nager");
        m_comp2->addItem("Pister");
        m_comp2->addItem("Truc de mauviette");
    }

    if(m_metier->currentText() == "Guerrier"){
        m_comp1->addItem("Ambidextrie");
        m_comp1->addItem("Chercher des noises");
        m_comp1->addItem("Chevaucher");
        m_comp1->addItem("Forgeron");
        m_comp1->addItem("Intimider");
        m_comp1->addItem("Tirer correctement");
        m_comp1->addItem("Truc de mauviette");

        m_comp2->addItem("Ambidextrie");
        m_comp2->addItem("Chercher des noises");
        m_comp2->addItem("Chevaucher");
        m_comp2->addItem("Forgeron");
        m_comp2->addItem("Intimider");
        m_comp2->addItem("Tirer correctement");
        m_comp2->addItem("Truc de mauviette");
    }
    else if(m_metier->currentText() == "Assassin"){
        m_comp1->addItem("Ambidextrie");
        m_comp1->addItem("Chercher des noises");
        m_comp1->addItem("Chevaucher");
        m_comp1->addItem("Erudition");
        m_comp1->addItem("Escalader");
        m_comp1->addItem("Méfiance");
        m_comp1->addItem("Nager");
        m_comp1->addItem("Ressemble à rien");

        m_comp2->addItem("Ambidextrie");
        m_comp2->addItem("Chercher des noises");
        m_comp2->addItem("Chevaucher");
        m_comp2->addItem("Erudition");
        m_comp2->addItem("Escalader");
        m_comp2->addItem("Méfiance");
        m_comp2->addItem("Nager");
        m_comp2->addItem("Ressemble à rien");
    }
    else if(m_metier->currentText() == "Voleur"){
        m_comp1->addItem("Arnaque et carambouille");
        m_comp1->addItem("Désamorcer");
        m_comp1->addItem("Erudition");
        m_comp1->addItem("Escalader");
        m_comp1->addItem("Fouiller les poubelles");
        m_comp1->addItem("Frapper lâchement");
        m_comp1->addItem("Méfiance");
        m_comp1->addItem("Ressemble à rien");

        m_comp2->addItem("Arnaque et carambouille");
        m_comp2->addItem("Désamorcer");
        m_comp2->addItem("Erudition");
        m_comp2->addItem("Escalader");
        m_comp2->addItem("Fouiller les poubelles");
        m_comp2->addItem("Frapper lâchement");
        m_comp2->addItem("Méfiance");
        m_comp2->addItem("Ressemble à rien");
    }
    else{
        m_comp1->addItem("Arnaque et carambouille");
        m_comp1->addItem("Désamorcer");
        m_comp1->addItem("Tirer correctement");
        m_comp1->addItem("Truc de mauviette");
        m_comp1->addItem("Méfiance");
        m_comp2->addItem("Arnaque et carambouille");
        m_comp2->addItem("Désamorcer");
        m_comp2->addItem("Tirer correctement");
        m_comp2->addItem("Truc de mauviette");
        m_comp2->addItem("Méfiance");
    }
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
        m_metier->addItem("Pirate");
    }
    if(charisme >= 11 && intel >= 12){
        m_metier->addItem("Marchand");
    }
    if(adresse >= 11){
        m_metier->addItem("Ingénieur");
    }
    if(charisme >= 11 && intel >= 10){
        m_metier->addItem("Noble");
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
