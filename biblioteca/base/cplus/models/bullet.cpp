#include "bullet.h"


Bullet::Bullet(QObject *bulletObjet)
{
    this->bulletObjet = bulletObjet;
    this->id++;
}

int Bullet::id = 0;

QObject *Bullet::getBulletObj()
{
    return this->bulletObjet;
}

int Bullet::getId()
{
    return this->id;
}

int Bullet::getPositionX() const
{   qDebug() << "bullet positionX: "<<positionX;
    return positionX;
}

void Bullet::setPositionX(int newPositionX)
{   //qDebug() << "Bullet Posicao X:  " << newPositionX;
    positionX = newPositionX;
    if(this->positionY != 0){
        emit position(this->positionX, this->positionY);
    }
}

int Bullet::getPositionY() const
{   //qDebug() << "enemy positionX: "<<positionX;
    return positionY;
}

void Bullet::setPositionY(int newPositionY)
{
    positionY = newPositionY;
}

int Bullet::getWidth() const
{
    return width;
}

void Bullet::setWidth(int newWidth)
{
    width = newWidth;
}

int Bullet::getHeight() const
{
    return height;
}

void Bullet::setHeight(int newHeight)
{
    height = newHeight;
}
