#include "componente.h"

Componente::Componente()
{

}

void Componente::setValor(QString valor)
{
this->valor = valor;
    return;
}

void Componente::setQObj(QObject *obj)
{
this->qObj = obj;
    return;
}

QString Componente::getValor()
{
return this->valor;
}

QObject *Componente::getObj()
{
return this->qObj;
}
