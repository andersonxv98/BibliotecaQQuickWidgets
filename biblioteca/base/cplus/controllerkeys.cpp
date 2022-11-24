#include "controllerkeys.h"

ControllerKeys::ControllerKeys(QObject *parent) : QObject(parent)
{

}

void ControllerKeys::showMyKey(QString k)
{
 qDebug() << "NMO BACK EU PRINTO: " << k;
}


