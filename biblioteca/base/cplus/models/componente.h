#ifndef COMPONENTE_H
#define COMPONENTE_H


#include "qobject.h"
class Componente : public QObject
{
    Q_OBJECT
public:
    Componente();

    Q_INVOKABLE void setValor(QString valor);
    Q_INVOKABLE void setQObj(QObject * obj);

    Q_INVOKABLE QString getValor();
    Q_INVOKABLE QObject * getObj();
private:
    QString valor;
    QObject * qObj;
};

#endif // COMPONENTE_H
