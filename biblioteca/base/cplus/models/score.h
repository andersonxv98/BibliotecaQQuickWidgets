#ifndef SCORE_H
#define SCORE_H

#include <QObject>



class Score : public QObject
{Q_OBJECT
public:
    Score(double dif);
   Q_INVOKABLE double getValue() const;
    void setValue(int newValue);

   Q_INVOKABLE int getEnemiesKilled() const;
    void setEnemiesKilled(int newEnemiesKilled);

   Q_INVOKABLE double getDificulty() const;
    void setDificulty(double newDificulty);

   Q_INVOKABLE int addScore(double dmgEnemy, double lifeEnemy);
signals:
    void valueChanged(double val);
    void enemiesKilledChanged(int qtd);
    void dificultyChanged(double val);

private:
    double value;
    int enemiesKilled;
    double dificulty;
};

#endif // SCORE_H
