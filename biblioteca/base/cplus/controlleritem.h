#ifndef CONTROLLERITEM_H
#define CONTROLLERITEM_H

#include "controllerrotation.h"

#include <QObject>



 class ControllerItem : public ControllerRotation
{Q_OBJECT
    Q_PROPERTY(int altura READ getAltura WRITE setAltura NOTIFY alturaChanged)
    Q_PROPERTY(int largura READ getLargura WRITE setLargura NOTIFY larguraChanged)
    Q_PROPERTY(double opacity READ getOpacity WRITE setOpacity NOTIFY opacityChanged)
    Q_PROPERTY(QString id_objQStr READ getId_objQStr WRITE setId_objQStr NOTIFY idChanged)
    Q_PROPERTY(bool anchor READ getAnchor WRITE setAnchor NOTIFY anchorChanged)


public:

    ControllerItem(QObject * parent = nullptr, int largura=0, int altura=0);

    void setOpacity(double o);
    void setAltura(int a);
    void setLargura(int l);
    void setId_objQStr(QString id);
    void setAnchor(bool v);

    Q_INVOKABLE double getOpacity();
    Q_INVOKABLE int getAltura();
    Q_INVOKABLE int getLargura();
    Q_INVOKABLE QString getId_objQStr();
    Q_INVOKABLE bool getAnchor();

    Q_INVOKABLE double getAlturaCentro();
    Q_INVOKABLE double getLarguraCentro();

 signals:
    void opacityChanged(double opacity);
    void alturaChanged(int i);
    void larguraChanged(int i);
    void idChanged(QString val);
    void anchorChanged(bool b);


 private:
    QString id_objQStr;
    double opacity;
    int altura;
    int largura;
    bool anchor;

};

#endif // CONTROLLERITEM_H
