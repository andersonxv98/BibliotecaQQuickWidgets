#include "score.h"

Score::Score(double dif)
{
    this->setValue(0);
    this->setEnemiesKilled(0);
    this->setDificulty(dif);
}

double Score::getValue() const
{
    return value;
}

void Score::setValue(int newValue)
{   if(value != newValue){
        value = newValue;
        emit  valueChanged(value);
    }
    return;
}

int Score::getEnemiesKilled() const
{
    return enemiesKilled;
}

void Score::setEnemiesKilled(int newEnemiesKilled)
{
    if(enemiesKilled != newEnemiesKilled){
        enemiesKilled = newEnemiesKilled;
        emit enemiesKilledChanged(enemiesKilled);
    }
    return;
}

double Score::getDificulty() const
{
    return dificulty;
}

void Score::setDificulty(double newDificulty)
{
    if(dificulty != newDificulty){
    dificulty = newDificulty;
    emit dificultyChanged(dificulty);
    }
    return;
}

int Score::addScore(double dmgEnemy, double lifeEnemy)
{
    double old = this->getValue();
    double result = old + (this->getDificulty() * (lifeEnemy/dmgEnemy));
    this->setValue(result);
    return result;
}
