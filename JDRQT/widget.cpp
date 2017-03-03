#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    init();
    handle();
}
void Widget::init(){

    m_model = new ModelJSON();

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

    //remplissage de la liste comp1
    m_comp1 = new QComboBox();

    //remplissage de la liste comp2
    m_comp2 = new QComboBox();

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
    m_origin->addItem("Gnome");

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
    formLayout->addRow(tr("Selectionnez votre compétence 1 :","labelcomp1"), m_comp1);
    formLayout->addRow(tr("Selectionnez votre compétence 2 :","labelcomp2"), m_comp2);
    formLayout->addRow(m_stats);
    formLayout->addRow(m_submit);

    setLayout(formLayout);
}

void Widget::handle(){
    QObject::connect(m_submit.data(), &QPushButton::clicked, this, &Widget::submit);
    QObject::connect(m_stats, &QPushButton::clicked, this, &Widget::openStatsWindow);
    QObject::connect(m_origin, &QComboBox::currentTextChanged, this, &Widget::genComp);
    QObject::connect(m_metier, &QComboBox::currentTextChanged, this, &Widget::genComp);


}


void Widget::submit(){
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
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




Widget::~Widget()
{
    delete m_stats;
}
