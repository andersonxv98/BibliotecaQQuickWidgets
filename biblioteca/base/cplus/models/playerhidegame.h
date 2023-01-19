#ifndef PLAYERHIDEGAME_H
#define PLAYERHIDEGAME_H


#include "playergun.h"
#include "qobject.h"
class PlayerHideGame : public PlayerGun
{Q_OBJECT
public:
    PlayerHideGame();

    Q_INVOKABLE QString getMaxHealt() const;
    Q_INVOKABLE void setMaxHealt(double newMaxHealt);

    Q_INVOKABLE QString getHealt() const;
    Q_INVOKABLE void setHealt(double newHealt);
    Q_INVOKABLE void reloadWeapon();
    int getPositionX() const;
    Q_INVOKABLE void setPositionX(int newPositionX);

    int getPositionY() const;
    Q_INVOKABLE void setPositionY(int newPositionY);

    Q_INVOKABLE QObject *getObj() const;
    Q_INVOKABLE void setObj(QObject *newObj);
    Q_INVOKABLE void receiveDmg(double val);


signals:
    void dead();
    void maxHealtChanged(double h);
    void healtChanged(double h);
private:
    double maxHealt;
    double healt;
    int positionX;
    int positionY;
    QObject * obj;


    //PlayerGun gun;


};

#endif // PLAYERHIDEGAME_H
