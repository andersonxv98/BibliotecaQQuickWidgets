#ifndef CONTROLLRETANGULOQML_H
#define CONTROLLRETANGULOQML_H

#include <QObject>
#include "controlleritem.h"
#include "qdebug.h"
#include <QColor>
#include <QQuickItem>


class ControllRetanguloQml : public ControllerItem
{Q_OBJECT
    Q_PROPERTY(QString cor READ getCor WRITE setCor NOTIFY corChanged)
    Q_PROPERTY(QString bordaCor READ getBordaCor WRITE setBordaCor NOTIFY bordaCorChanged)
    Q_PROPERTY(int bordaWidth READ getBordaWidth WRITE setBordaWidth NOTIFY bordaWidthChanged)
    Q_PROPERTY(int radius READ getRadius WRITE setRadius NOTIFY radiusChanged)
    //Q_PROPERTY(QVariantList gradients READ getGradients WRITE addGradients NOTIFY gradientsChanged)


public:
    ControllRetanguloQml(QObject * parent =0,int largura=0, int altura=0);

    void setCor(QString color);
    void setBordaCor(QString color);
    void setBordaWidth(int val);
    void setRadius(int r);


   //Q_INVOKABLE int getAltura();
   //Q_INVOKABLE int getLargura();
   Q_INVOKABLE int getBordaWidth();
   Q_INVOKABLE QString  getCor();
   Q_INVOKABLE QString getBordaCor();
   Q_INVOKABLE int getRadius();


public:
    signals:
    void corChanged(QString s) ;
    void bordaWidthChanged(int val);
    void bordaCorChanged(QString cor);
    void radiusChanged(int r);
    void gradientsChanged(QVariantList list);

/*protected:
    void setAltura(int val);
    void setLargura(int val);*/


private:

    int bordaWidth;
    int radius;
    QString cor;
    QString bordaCor;


    QVariantList  l_gradiente;





};

#endif // CONTROLLRETANGULOQML_H
