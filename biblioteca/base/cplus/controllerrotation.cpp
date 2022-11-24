#include "controllerrotation.h"
#include "qvariant.h"


ControllerRotation::ControllerRotation(QObject *parent): QObject(parent)
{
    this->angulo = NULL;

}

void ControllerRotation::setAngulo(double i)
{
    qDebug() << "valor angulo" << i;
    if(this->angulo != i){
        this->angulo = i;
        emit anguloChanged(this->angulo);
    }
    return;
}

void ControllerRotation::setAxisX(double i)
{
    if(this->axisX != i){
        this->axisX = i;
        emit axisXChanged(this->axisX);
    }
    return;
}

void ControllerRotation::setAxisY(double i)
{
    if(this->axisY != i){
        this->axisY = i;
        emit axisYChanged(this->axisY);
    }
    return;
}

void ControllerRotation::setAxisZ(double i)
{
    if(this->axisZ != i){
        this->axisZ = i;
        emit axisZChanged(this->axisZ);
    }
    return;
}

void ControllerRotation::setOriginX(double i)
{
    if(this->originX != i){
        this->originX = i;
        emit originXChanged(this->originX);
    }
    return;
}

void ControllerRotation::setOriginY(double i)
{
    if(this->originY != i){
        this->originY = i;
        emit originYChanged(this->originY);
    }
    return;
}

void ControllerRotation::setValuesofRotation(QList<double> list)
{
    if(this->valuesofRotation != list){
            this->valuesofRotation = list;
        emit valuesofRotationChanged(this->valuesofRotation);
    }
    return;
}

double ControllerRotation::getAngulo()
{
    return this->angulo;
}

double ControllerRotation::getAxisX()
{return this->axisX;

}

double ControllerRotation::getAxisY()
{
    return this->axisY;
}

double ControllerRotation::getAxisZ()
{return this->axisZ;

}

double ControllerRotation::getOriginX()
{   qDebug() << "valor origin.x " << this->originX;
    return this->originX;
}

double ControllerRotation::getOriginY()
{
    qDebug() << "valor origin.x " << this->originY;
    return this->originY;

}

QList<double> ControllerRotation::getValuesofRotation()
{
    return this->valuesofRotation;
}
