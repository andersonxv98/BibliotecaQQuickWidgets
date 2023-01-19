#include "enemyhidegame.h"


EnemyHideGame::EnemyHideGame(QObject *enemyObj)
{
    this->enemyObj = enemyObj;
    this->dmg= 10;
    this->life= 10;
    this->velocity= 1;
    this->id++;
}
int EnemyHideGame::id = 0;
void EnemyHideGame::position(int x, int y)
{
    //qDebug() << "ENEMY>> POSITION: " << "X: " << x << "  Y: " << y;
}

int EnemyHideGame::getId()
{
return this->id;
}

QObject *EnemyHideGame::getEnemyObj()
{
    return this->enemyObj;
}

int EnemyHideGame::getPositionX() const
{   qDebug() << "enemy positionX: "<<positionX;
    return positionX;
}

void EnemyHideGame::setPositionX(int newPositionX)
{   //qDebug() << "Enemy Posicao X:  " << newPositionX;
    positionX = newPositionX;
    if(this->positionY != 0){
        emit positioni(this->positionX, this->positionY);
    }
    return;
}

int EnemyHideGame::getPositionY() const
{
    return positionY;
}

void EnemyHideGame::setPositionY(int newPositionY)
{
    positionY = newPositionY;
}

int EnemyHideGame::getWidth() const
{
    return width;
}

void EnemyHideGame::setWidth(int newWidth)
{
    width = newWidth;
}

int EnemyHideGame::getHeight() const
{
    return height;
}

void EnemyHideGame::setHeight(int newHeight)
{
    height = newHeight;
}

double EnemyHideGame::getDmg() const
{
    return dmg;
}

void EnemyHideGame::setDmg(double newDmg)
{
    dmg = newDmg;
}

int EnemyHideGame::getVelocity() const
{
    return velocity;
}

void EnemyHideGame::setVelocity(int newVelocity)
{
    velocity = newVelocity;
}

QString EnemyHideGame::getComportamento() const
{
    return comportamento;
}

void EnemyHideGame::setComportamento(const QString &newComportamento)
{
    comportamento = newComportamento;
}

double EnemyHideGame::getLife() const
{
    return life;
}

void EnemyHideGame::setLife(double newLife)
{
    life = newLife;
}
