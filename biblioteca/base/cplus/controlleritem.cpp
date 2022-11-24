#include "controlleritem.h"
#include "qdebug.h"

ControllerItem::ControllerItem(QObject *parent, int largura, int altura) : ControllerRotation(parent)
{
    this->setAltura(altura);
    this->setLargura(largura);
    this->anchor = false;
}

void ControllerItem::setOpacity(double o)
{
    if(this->opacity != o){
        this->opacity = o;
        emit opacityChanged(this->opacity);
    }
    return;
}


void ControllerItem::setAltura(int a)
{
    if(this->altura != a)
    {
     this->altura = a;
        emit alturaChanged(this->altura);
    }
    return;
}

void ControllerItem::setLargura(int l)
{
    if(this->largura != l){
        this->largura = l;
        emit larguraChanged(this->largura);

    }
    return;
}

void ControllerItem::setId_objQStr(QString id)
{
    if(this->id_objQStr != id){
        this->id_objQStr = id;
        emit idChanged(this->id_objQStr);
    }
    return;
}

void ControllerItem::setAnchor(bool b)
{
    if(this->anchor != b){
        qDebug() << "SET aNCHOR CONDIÇÃO";
        this->anchor= b;
        emit anchorChanged(this->anchor);
    }
    return;
}


double ControllerItem::getOpacity()
{return this->opacity;

}

int ControllerItem::getAltura()
{
    return this->altura;
}

int ControllerItem::getLargura()
{return this->largura;

}

QString ControllerItem::getId_objQStr()
{
    return this->id_objQStr;
}

bool ControllerItem::getAnchor()
{return this->anchor;

}

double ControllerItem::getAlturaCentro()
{
    double result = this->altura/2;
    return result;

}

double ControllerItem::getLarguraCentro()
{

    double result = this->largura/2;
    return result;
}
