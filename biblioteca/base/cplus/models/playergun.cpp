#include "playergun.h"

PlayerGun::PlayerGun()
{
    this->setDmg(10);
    this->setReload_delay(0.5);
    this->setAmmoSize(7);
    this->setAmmoQtd(this->ammoSize);
    this->setAmmoMax(this->ammoQtd * 4);
    this->setBulletVelocity(10);
    this->setType("default");
}

double PlayerGun::getDmg() const
{
    return dmg;
}

void PlayerGun::setDmg(double newDmg)
{
    if(dmg != newDmg){
       dmg = newDmg;
       emit dmgChanged(dmg);
    }
    return;
}

QString PlayerGun::getType() const
{
    return type;
}

void PlayerGun::setType(const QString &newType)
{   if(type != newType){
        type = newType;
        emit typeChanged(type);
    }
    return;
}

int PlayerGun::getAmmoQtd() const
{
    return ammoQtd;
}

void PlayerGun::setAmmoQtd(int newAmmoQtd)
{   if(ammoQtd != newAmmoQtd){
        ammoQtd = newAmmoQtd;
        emit ammoQtdChanged(ammoQtd);
    }
    return;
}

int PlayerGun::getAmmoMax() const
{
    return ammoMax;
}

void PlayerGun::setAmmoMax(int newAmmoMax)
{
    if(ammoMax != newAmmoMax){
        ammoMax = newAmmoMax;
        emit ammoMaxChanged(ammoMax);
    }
    return;
}

double PlayerGun::getReload_delay() const
{
    return reload_delay;
}

void PlayerGun::setReload_delay(double newReload_delay)
{
    if(reload_delay != newReload_delay){
    reload_delay = newReload_delay;
    emit reload_delayChanged(reload_delay);
    }
    return;
}

bool PlayerGun::shoot()
{
    if(ammoQtd > 0){
        ammoQtd -= 1;
        emit ammoQtdChanged(ammoQtd);
        return true;
    }
    return false;
}

int PlayerGun::getAmmoSize() const
{
    return ammoSize;
}

void PlayerGun::setAmmoSize(int newAmmoSize)
{
    if(ammoSize != newAmmoSize){
        ammoSize = newAmmoSize;
        emit ammoSizeChanged(ammoSize);
    }
    return;
}

int PlayerGun::getBulletVelocity() const
{
    return bulletVelocity;
}

void PlayerGun::setBulletVelocity(int newBulletVelocity)
{
    bulletVelocity = newBulletVelocity;
}
