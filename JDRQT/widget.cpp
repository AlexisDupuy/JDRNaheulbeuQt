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
    formLayout->addRow(tr("Selectionnez votre origine :","labelorigin"), m_origin);
    formLayout->addRow(tr("Selectionnez votre métier :","labelmetier"), m_metier);
    formLayout->addRow(m_stats);
    formLayout->addRow(m_submit);

    setLayout(formLayout);
}

void Widget::handle(){
    QObject::connect(m_submit.data(), &QPushButton::clicked, this, &Widget::submit);
    QObject::connect(m_stats, &QPushButton::clicked, this, &Widget::openStatsWindow);

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


Widget::~Widget()
{
    delete m_stats;
}
