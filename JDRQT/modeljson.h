#ifndef MODELJSON_H
#define MODELJSON_H

#include <QObject>

class ModelJSON : public QObject
{
    Q_OBJECT
public:
    explicit ModelJSON(QObject *parent = 0);

private:
    void readJson();
    void writeJson();

signals:

public slots:
};

#endif // MODELJSON_H
