#include "carta.h"

Carta::Carta(QString nome, QString cor, QString url_img)
{
this->nome = nome;
    this->cor = cor;
    this->url_img = url_img;
}

QString Carta::getNome()
{
    return this->nome;
}

QString Carta::getCor()
{return this->cor;

}

QString Carta::getImg()
{
return this->url_img;
}
