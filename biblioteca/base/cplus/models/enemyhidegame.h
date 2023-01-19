#ifndef ENEMYHIDEGAME_H
#define ENEMYHIDEGAME_H

#include <QObject>
#include "qdebug.h"
class EnemyHideGame : public QObject
{Q_OBJECT
public:
    EnemyHideGame(QObject * enemyObj);
    Q_INVOKABLE void position(int x, int y);
    int getId();
    QObject * getEnemyObj();
    int getPositionX() const;
    Q_INVOKABLE void setPositionX(int newPositionX);

    int getPositionY() const;
    Q_INVOKABLE void setPositionY(int newPositionY);
    int getWidth() const;
    Q_INVOKABLE void setWidth(int newWidth);

    int getHeight() const;
    Q_INVOKABLE void setHeight(int newHeight);

    Q_INVOKABLE double getDmg() const;
    Q_INVOKABLE void setDmg(double newDmg);

    Q_INVOKABLE int getVelocity() const;
    Q_INVOKABLE void setVelocity(int newVelocity);

   Q_INVOKABLE  QString getComportamento() const;
    Q_INVOKABLE void setComportamento(const QString &newComportamento);

    Q_INVOKABLE double getLife() const;
    void setLife(double newLife);

signals:
    void positioni(int x, int y);
private:
    static int id;
    QObject * enemyObj;
    int positionX;
    int positionY;
    int width;
    int height;
    double dmg;
    int velocity;
    double life;
    QString comportamento;
};

#endif // ENEMYHIDEGAME_H
