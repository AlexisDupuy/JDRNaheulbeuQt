#ifndef MODELJSON_H
#define MODELJSON_H

#include <QObject>

class QMap;

class ModelJSON : public QObject
{
    Q_OBJECT
public:
    explicit ModelJSON(QObject *parent = 0);

    QString sNom() const;

    void setSNom(const QString &sNom);

    int sSexe() const;

    void setSSexe(int sSexe);

    int sOrigin() const;

    void setSOrigin(int sOrigin);

    int sMetier() const;

    void setSMetier(int sMetier);

    int iEv() const;

    void setIEv(int iEv);

    int iEa() const;

    void setIEa(int iEa);

    int iMagPhy() const;

    void setIMagPhy(int iMagPhy);

    int iMagPsy() const;

    void setIMagPsy(int iMagPsy);

    int iResMag() const;

    void setIResMag(int iResMag);

    int iCourage() const;

    void setICourage(int iCourage);

    int iIntel() const;

    void setIIntel(int iIntel);

    int iChar() const;

    void setIChar(int iChar);

    int iAddr() const;

    void setIAddr(int iAddr);

    int iForce() const;

    void setIForce(int iForce);

    int iAttaq() const;

    void setIAttaq(int iAttaq);

    int iParad() const;

    void setIParad(int iParad);

    int iNiveau() const;

    void setINiveau(int iNiveau);

    int iExpe() const;

    void setIExpe(int iExpe);

    int iDestin() const;

    void setIDestin(int iDestin);

    int iOr() const;

    void setIOr(int iOr);

    int iArgent() const;

    void setIArgent(int iArgent);

    int iCuivre() const;

    void setICuivre(int iCuivre);

    int iPr() const;

    void setIPr(int iPr);

private:
    // Variable de la fiche :
    // aFiche : array[Fiche]
    QString m_sNom; // : string
    int m_sSexe; // : string
    int m_sOrigin; // : enum(string)
    int m_sMetier; // : enum(string)
    int m_iEv; // : int // PV
    int m_iEa; // : int // Mana
    int m_iMagPhy; // : int
    int m_iMagPsy; // : int
    int m_iResMag; // : int
    int m_iCourage; // : int
    int m_iIntel; // : int
    int m_iChar; // : int
    int m_iAddr; // : int
    int m_iForce; // : int
    int m_iAttaq; // : int
    int m_iParad; // : int
    int m_iNiveau; // : int
    int m_iExpe; // : int
    int m_iDestin; // : int
    int m_iOr; // : int
    int m_iArgent; // : int
    int m_iCuivre; // : int
    int m_iPr; // : int // protection totale
    QMap<QString, QString> m_cArmure; // : collection(string) // nom = nom armure (string), valeur = pr de l'armure (int), rupt = rupture de l'armure (string))
    QMap<QString, QString> m_cArme; // : collection(string) // nom = nom arme (string), valeur = pi de l'arme (string), rupt = rupture de l'arme (string))

signals:

public slots:
};

#endif // MODELJSON_H
