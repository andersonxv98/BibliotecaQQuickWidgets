#include "controllretanguloqml.h"




ControllRetanguloQml::ControllRetanguloQml(QObject *parent, int largura, int altura): ControllerItem(parent, largura, altura)
{

    //this->setAltura(altura);
    //this->setLargura(largura);
}

void ControllRetanguloQml::setCor(QString color)
{
if (this->cor != color){
    this->cor = color;
    emit corChanged(this->cor);
    }
return;
}

void ControllRetanguloQml::setBordaCor(QString color)
{
    if(color != this->bordaCor){
        this->bordaCor = color;
        emit bordaCorChanged(this->bordaCor);
    }
    return;
}

void ControllRetanguloQml::setBordaWidth(int val)
{
    if(this-> bordaWidth != val){
        this->bordaWidth = val;
        emit bordaWidthChanged(this->bordaWidth);

    }
    return;
}

void ControllRetanguloQml::setRadius(int r)
{
if (this->radius != r){
    this->radius = r;
    emit radiusChanged(this->radius);


}
return;
}



int ControllRetanguloQml::getBordaWidth()
{
    return this->bordaWidth;
}

QString ControllRetanguloQml::getCor()
{return this->cor;

}


QString ControllRetanguloQml::getBordaCor()
{
    return this->bordaCor;
}

int ControllRetanguloQml::getRadius()
{
    return this->radius;
}




