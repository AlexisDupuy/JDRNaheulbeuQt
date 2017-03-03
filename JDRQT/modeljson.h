#ifndef MODELJSON_H
#define MODELJSON_H

#include <QObject>
#include <QMap>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

class ModelJSON : public QObject
{
    Q_OBJECT
public:
    explicit ModelJSON(QObject *parent = 0);

    QString sNom() const;

    void setSNom(const QString &sNom);

    QString sSexe() const;

    void setSSexe(const QString &sSexe);

    QString sOrigin() const;

    void setSOrigin(const QString &sOrigin);

    QString sMetier() const;

    void setSMetier(const QString &sMetier);

    double iEv() const;

    void setIEv(double iEv);

    double iEa() const;

    void setIEa(double iEa);

    double iMagPhy() const;

    void setIMagPhy(double iMagPhy);

    double iMagPsy() const;

    void setIMagPsy(double iMagPsy);

    double iResMag() const;

    void setIResMag(double iResMag);

    double iCourage() const;

    void setICourage(double iCourage);

    double iIntel() const;

    void setIntel(double iIntel);

    double iChar() const;

    void setIChar(double iChar);

    double iAddr() const;

    void setIAddr(double iAddr);

    double iForce() const;

    void setIForce(double iForce);

    double iAttaq() const;

    void setIAttaq(double iAttaq);

    double iParad() const;

    void setIParad(double iParad);

    double iNiveau() const;

    void setINiveau(double iNiveau);

    double iExpe() const;

    void setIExpe(double iExpe);

    double iDestin() const;

    void setIDestin(double iDestin);

    double iOr() const;

    void setIOr(double iOr);

    double iPr() const;

    void setIPr(double iPr);

private:
    // Variable de la fiche :
    // aFiche : array[Fiche]
    QString m_sNom; // : string
    QString m_sSexe; // : string
    QString m_sOrigin; // : enum(string)
    QString m_sMetier; // : enum(string)
    double m_iEv; // : double // PV
    double m_iEa; // : double // Mana
    double m_iMagPhy; // : int
    double m_iMagPsy; // : int
    double m_iResMag; // : int
    double m_iCourage; // : int
    double m_iIntel; // : int
    double m_iChar; // : int
    double m_iAddr; // : int
    double m_iForce; // : int
    double m_iAttaq; // : int
    double m_iParad; // : int
    double m_iNiveau; // : int
    double m_iExpe; // : int
    double m_iDestin; // : int
    double m_iOr; // : int
    double m_iPr; // : double // protection totale
    QMap<QString, QString> m_cArmure; // : collection(string) // nom = nom armure (string), valeur = pr de l'armure (int), rupt = rupture de l'armure (string))
    QMap<QString, QString> m_cArme; // : collection(string) // nom = nom arme (string), valeur = pi de l'arme (string), rupt = rupture de l'arme (string))
    void readJson();
    void writeJson();

signals:

public slots:
};

#endif // MODELJSON_H
