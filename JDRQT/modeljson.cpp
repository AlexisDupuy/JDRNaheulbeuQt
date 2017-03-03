#include <modeljson.h>
#include <QDebug>

ModelJSON::ModelJSON(QObject *parent) : QObject(parent)
{
    readJson();
}

void ModelJSON::readJson()
{
    QString m_fiche;
    QFile file;
    file.setFileName("fiche.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(file.exists()){
        m_fiche = file.readAll();
        file.close();
        QJsonDocument ficheJson = QJsonDocument::fromJson(m_fiche.toUtf8());
        QJsonObject jsonObject = ficheJson.object();
        m_sNom = jsonObject.value(QString("nom")).toString();
        m_sSexe = jsonObject.value(QString("sexe")).toString();
        m_sOrigin = jsonObject.value(QString("origin")).toString();
        m_sMetier = jsonObject.value(QString("metier")).toString();
        m_iEv = jsonObject.value(QString("ev")).toDouble();
        m_iEa = jsonObject.value(QString("ea")).toDouble();
        m_iMagPhy = jsonObject.value(QString("magPhy")).toDouble();
        m_iMagPsy = jsonObject.value(QString("magPsy")).toDouble();
        m_iResMag = jsonObject.value(QString("resMag")).toDouble();
        m_iCourage = jsonObject.value(QString("courage")).toDouble();
        m_iChar = jsonObject.value(QString("char")).toDouble();
        m_iIntel = jsonObject.value(QString("intel")).toDouble();
        m_iAddr = jsonObject.value(QString("addr")).toDouble();
        m_iForce = jsonObject.value(QString("force")).toDouble();
        m_iAttaq = jsonObject.value(QString("attaque")).toDouble();
        m_iParad = jsonObject.value(QString("parade")).toDouble();
        m_iNiveau = jsonObject.value(QString("niveau")).toDouble();
        m_iExpe = jsonObject.value(QString("expe")).toDouble();
        m_iDestin = jsonObject.value(QString("destin")).toDouble();
        m_iOr = jsonObject.value(QString("or")).toDouble();
        m_iPr = jsonObject.value(QString("pr")).toDouble();

    } else {
        qDebug() << "existe pas";
        file.close();
        m_sNom = "";
        m_sSexe = "";
        m_sOrigin = "";
        m_sMetier = "";
        m_iEv = 0;
        m_iEa = 0;
        m_iMagPhy = 0;
        m_iMagPsy = 0;
        m_iResMag = 0;
        m_iCourage = 0;
        m_iChar = 0;
        m_iIntel = 0;
        m_iAddr = 0;
        m_iForce = 0;
        m_iAttaq = 0;
        m_iParad = 0;
        m_iNiveau = 0;
        m_iExpe = 0;
        m_iDestin = 0;
        m_iOr = 0;
        m_iPr = 0;
    }
}

void ModelJSON::writeJson(QString _sNom, QString _sSexe, QString _sOrigin, QString _sMetier, QString _iEv, QString _iEa,
                          QString _iMagPhy, QString _iMagPsy, QString _iResMag,
                          QString _iCourage, QString _iChar, QString _iIntel, QString _iAddr, QString _iForce,
                          QString _iAttaq, QString _iParad, QString _iNiveau, QString _iExpe, QString _iDestin,
                          QString _iOr, QString _iPr)
{
    QString m_fiche;
    QFile file;
    file.setFileName("fiche.json");
    file.open(QIODevice::Truncate| QIODevice::ReadWrite);
    m_fiche = file.readAll();
    QJsonDocument ficheJson = QJsonDocument::fromJson(m_fiche.toUtf8());
    QJsonObject jsonObject = ficheJson.object();
    jsonObject["nom"] = _sNom;
    jsonObject["sexe"] = _sSexe;
    jsonObject["origin"] = _sOrigin;
    jsonObject["metier"] = _sMetier;
    jsonObject["ev"] = _iEv.toDouble();
    jsonObject["ea"] = _iEa.toDouble();
    jsonObject["magPhy"] = _iMagPhy.toDouble();
    jsonObject["magPsy"] = _iMagPsy.toDouble();
    jsonObject["resMag"] = _iResMag.toDouble();
    jsonObject["courage"] = _iCourage.toDouble();
    jsonObject["char"] = _iChar.toDouble();
    jsonObject["intel"] = _iIntel.toDouble();
    jsonObject["addr"] = _iAddr.toDouble();
    jsonObject["force"] = _iForce.toDouble();
    jsonObject["attaque"] = _iAttaq.toDouble();
    jsonObject["parade"] = _iParad.toDouble();
    jsonObject["niveau"] = _iNiveau.toDouble();
    jsonObject["expe"] = _iExpe.toDouble();
    jsonObject["destin"] = _iDestin.toDouble();
    jsonObject["or"] = _iOr.toDouble();
    jsonObject["pr"] = _iPr.toDouble();
    QJsonDocument saveDoc(jsonObject);
    file.write(saveDoc.toJson());
    file.close();
}

QString ModelJSON::sNom() const
{
    return m_sNom;
}

void ModelJSON::setSNom(const QString &sNom)
{
    m_sNom = sNom;
}

QString ModelJSON::sSexe() const
{
    return m_sSexe;
}

void ModelJSON::setSSexe(const QString &sSexe)
{
    m_sSexe = sSexe;
}

QString ModelJSON::sOrigin() const
{
    return m_sOrigin;
}

void ModelJSON::setSOrigin(const QString &sOrigin)
{
    m_sOrigin = sOrigin;
}

QString ModelJSON::sMetier() const
{
    return m_sMetier;
}

void ModelJSON::setSMetier(const QString &sMetier)
{
    m_sMetier = sMetier;
}

double ModelJSON::iEv() const
{
    return m_iEv;
}

void ModelJSON::setIEv(double iEv)
{
    m_iEv = iEv;
}

double ModelJSON::iEa() const
{
    return m_iEa;
}

void ModelJSON::setIEa(double iEa)
{
    m_iEa = iEa;
}

double ModelJSON::iMagPhy() const
{
    return m_iMagPhy;
}

void ModelJSON::setIMagPhy(double iMagPhy)
{
    m_iMagPhy = iMagPhy;
}

double ModelJSON::iMagPsy() const
{
    return m_iMagPsy;
}

void ModelJSON::setIMagPsy(double iMagPsy)
{
    m_iMagPsy = iMagPsy;
}

double ModelJSON::iResMag() const
{
    return m_iResMag;
}

void ModelJSON::setIResMag(double iResMag)
{
    m_iResMag = iResMag;
}

double ModelJSON::iCourage() const
{
    return m_iCourage;
}

void ModelJSON::setICourage(double iCourage)
{
    m_iCourage = iCourage;
}

double ModelJSON::iIntel() const
{
    return m_iIntel;
}

void ModelJSON::setIntel(double Intel)
{
    m_iIntel = Intel;
}

double ModelJSON::iChar() const
{
    return m_iChar;
}

void ModelJSON::setIChar(double iChar)
{
    m_iChar = iChar;
}

double ModelJSON::iAddr() const
{
    return m_iAddr;
}

void ModelJSON::setIAddr(double iAddr)
{
    m_iAddr = iAddr;
}

double ModelJSON::iForce() const
{
    return m_iForce;
}

void ModelJSON::setIForce(double iForce)
{
    m_iForce = iForce;
}

double ModelJSON::iAttaq() const
{
    return m_iAttaq;
}

void ModelJSON::setIAttaq(double iAttaq)
{
    m_iAttaq = iAttaq;
}

double ModelJSON::iParad() const
{
    return m_iParad;
}

void ModelJSON::setIParad(double iParad)
{
    m_iParad = iParad;
}

double ModelJSON::iNiveau() const
{
    return m_iNiveau;
}

void ModelJSON::setINiveau(double iNiveau)
{
    m_iNiveau = iNiveau;
}

double ModelJSON::iExpe() const
{
    return m_iExpe;
}

void ModelJSON::setIExpe(double iExpe)
{
    m_iExpe = iExpe;
}

double ModelJSON::iDestin() const
{
    return m_iDestin;
}

void ModelJSON::setIDestin(double iDestin)
{
    m_iDestin = iDestin;
}

double ModelJSON::iOr() const
{
    return m_iOr;
}

void ModelJSON::setIOr(double iOr)
{
    m_iOr = iOr;
}

double ModelJSON::iPr() const
{
    return m_iPr;
}

void ModelJSON::setIPr(double iPr)
{
    m_iPr = iPr;
}
