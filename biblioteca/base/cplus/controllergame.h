#ifndef CONTROLLERGAME_H
#define CONTROLLERGAME_H


#include "controlleritem.h"
#include "models/bullet.h"
#include "models/enemyhidegame.h"
#include "models/playerhidegame.h"
#include "models/score.h"
#include "qdebug.h"
#include <QQmlEngine>
#include "qqmlcontext.h"
#include <QList>
class ControllerGame : public ControllerItem
{Q_OBJECT
public:
    ControllerGame(QQmlContext * rootContext);

    Q_INVOKABLE void shoot(int bulletId);

    Q_INVOKABLE void appendEnemy(QObject *enemy, int idEnemy);
    Q_INVOKABLE void removeEnemy(QObject * enemy);
    Q_INVOKABLE void appendBullet(QObject * bullet, int idBullet, QString hierarchy);
    Q_INVOKABLE void removeBullet(QObject * bullet);
    Q_INVOKABLE QList<QObject*> bulletEnemyColision();
    Q_INVOKABLE QList<int> playerPosition();

    int getEnemies_qtd() const;
    void setEnemies_qtd(int newEnemies_qtd);

   Q_INVOKABLE double getDificulty() const;
    void setDificulty(int newDificulty);

signals:
    void singleShooting(double velocidade, double dmg, QString comportamento, QString context);
    void doubleShooting(double velocidade, double dmg, QString comportamento, QString context);
    void tripleShooting(double velocidade, double dmg, QString comportamento, QString context);
    void flameShooting(double velocidade, double dmg, QString comportamento, QString context);
    void difChanged(int dif);
    void playerDead();
public slots:
    void playerShootAndEnemyColison(Bullet * b, EnemyHideGame * e);

private:
    PlayerHideGame * player_control; // = new PlayerHideGame();
    QList<EnemyHideGame*> l ;
     QList<Bullet*> l_bullet ;
     QQmlContext * rootContext;
    Score * score;
    double dificulty;
    int enemies_qtd;
};

#endif // CONTROLLERGAME_H
