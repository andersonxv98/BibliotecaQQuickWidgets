#ifndef BULLET_H
#define BULLET_H

#include "qdebug.h"
#include "qobject.h"
class Bullet : public QObject
{Q_OBJECT

public:
    Bullet(QObject * bulletObjet);
    QObject * getBulletObj();
    int getId();
    int getPositionX() const;
    Q_INVOKABLE void setPositionX(int newPositionX);

    int getPositionY() const;
    Q_INVOKABLE void setPositionY(int newPositionY);
    int getWidth() const;
    Q_INVOKABLE void setWidth(int newWidth);

    int getHeight() const;
    Q_INVOKABLE void setHeight(int newHeight);

signals:
    void position(int x, int y);
private:
    QObject * bulletObjet;
    static int id;
    int positionX;
    int positionY;
    int width;
    int height;
};

#endif // BULLET_H
