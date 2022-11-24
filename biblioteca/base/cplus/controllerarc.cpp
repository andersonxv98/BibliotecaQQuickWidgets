#include "controllerarc.h"

ControllerArc::ControllerArc(QObject * parent) : ControllerItem(parent)
{
    this->buraco = false;
}

void ControllerArc::setPosicaoInicialByPorcentagem(double val)
{
    double result = (val  * 2)  / 100;
    qDebug() << "valor ini resultado: "<< result;
    this->setInit(result);
    return;
}

void ControllerArc::setPosicaoFinalByPorcentagem(double val)
{
    double result = (val  * 2) / 100;
    this->setEnd(result);
    return;
}

void ControllerArc::setAnticlockWise(bool f)
{
if(this->anticlockwise != f)
    {
    this->anticlockwise = f;
    emit anticlockwiseChanged(this->anticlockwise);

    }
return;
}

void ControllerArc::setCor(QString color)
{
    qDebug() << "entrou function: " << color;
    if(this->cor != color){
        this->cor = color;
        qDebug() << "entrou condição: " << this->cor;
        emit corChanged(this->cor);
    }
    return;
}

void ControllerArc::setSizeModificador(double val)
{
    if(this->sizeModificador != val){
        this->sizeModificador = val;
        emit sizeModificadorChanged(this->sizeModificador);

    }
    return;
}

void ControllerArc::setBuraco(bool f)
{
    if(this->buraco != f){
        this->buraco = f;
        emit buracoChanged(this->buraco);
    }
    return;
}

double ControllerArc::getInit()
{
    return this->init;
}

double ControllerArc::getEnd()
{return this->end;

}

bool ControllerArc::getAnticlockWise()
{
return this->anticlockwise;
}

QString ControllerArc::getCor()
{
    return this->cor;
}

int ControllerArc::getSizeModificador()
{
    return this->sizeModificador;
}

bool ControllerArc::getBuraco()
{
return this->buraco;
}

void ControllerArc::setInit(double val)
{

    if (this->init != val){
        this->init = val;
        qDebug() << "entrou condição valor init: " << val;
        emit initChanged(this->init);
    }
    return;
}

void ControllerArc::setEnd(double val)
{
    if (this->end != val){
        this->end = val;
        emit endChanged(this->end);
    }
    return;
}
