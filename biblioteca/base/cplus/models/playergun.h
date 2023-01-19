#ifndef PLAYERGUN_H
#define PLAYERGUN_H

#include <QObject>



class PlayerGun : public QObject
{ Q_OBJECT
public:
    PlayerGun();
   Q_INVOKABLE double getDmg() const;
    void setDmg(double newDmg);

    Q_INVOKABLE QString getType() const;
    void setType(const QString &newType);

   Q_INVOKABLE int getAmmoQtd() const;
    void setAmmoQtd(int newAmmoQtd);

   Q_INVOKABLE int getAmmoMax() const;
    void setAmmoMax(int newAmmoMax);

  Q_INVOKABLE double getReload_delay() const;
    void setReload_delay(double newReload_delay);

    bool shoot();
    int getAmmoSize() const;
    void setAmmoSize(int newAmmoSize);

    int getBulletVelocity() const;
    void setBulletVelocity(int newBulletVelocity);

signals:
    void dmgChanged(double v);
    void typeChanged(QString v);
    void ammoQtdChanged(int v);
    void ammoMaxChanged(int v);
    void reload_delayChanged(double v);
    void ammoSizeChanged(int v);

private:
    double dmg;
    QString type;
    int ammoQtd;
    int ammoMax;
    int ammoSize;
    double reload_delay;
    int bulletVelocity;
};

#endif // PLAYERGUN_H
