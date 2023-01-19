#include "playerhidegame.h"

PlayerHideGame::PlayerHideGame()
{
    this->setMaxHealt(100);
    this->setHealt(this->maxHealt);
    //gun = PlayerGun();
}

QString PlayerHideGame::getMaxHealt() const
{
    this->getAmmoMax();
    this->getAmmoQtd();
    return QString::number(maxHealt);
}

void PlayerHideGame::setMaxHealt(double newMaxHealt)
{
    if(maxHealt != newMaxHealt){
        maxHealt = newMaxHealt;
        emit maxHealtChanged(maxHealt);
    }
    return;
}

QString PlayerHideGame::getHealt() const
{
    return QString::number(healt);
}

void PlayerHideGame::setHealt(double newHealt)
{
    if(healt != newHealt){
        healt = newHealt;
        emit healtChanged(healt);
    }
    return;
}

void PlayerHideGame::reloadWeapon()
{
    int max = this->getAmmoMax();
    if(max > 0){
        int ammo = this->getAmmoQtd();
        int pente = this->getAmmoSize();
        if(ammo < pente){
            int new_val = 0;
            if(max > pente){
                new_val = pente - ammo;
                this->setAmmoMax((max - new_val));
            }
            else{
                new_val = max;
                this->setAmmoMax(0);
            }
            this->setAmmoQtd(new_val + ammo);
        }
    }
    return;
}

int PlayerHideGame::getPositionX() const
{
    return positionX;
}

void PlayerHideGame::setPositionX(int newPositionX)
{
    positionX = newPositionX;
}

int PlayerHideGame::getPositionY() const
{
    return positionY;
}

void PlayerHideGame::setPositionY(int newPositionY)
{
    positionY = newPositionY;
}

QObject *PlayerHideGame::getObj() const
{
    return obj;
}

void PlayerHideGame::setObj(QObject *newObj)
{
    obj = newObj;
}

void PlayerHideGame::receiveDmg(double val)
{
    this->setHealt((this->getHealt().toDouble() - val));
    if(this->getHealt().toDouble() <= 0){
        emit dead();
    }
    return;
}


