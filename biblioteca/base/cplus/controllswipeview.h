#ifndef CONTROLLSWIPEVIEW_H
#define CONTROLLSWIPEVIEW_H

#include "controllercarta.h"
#include "controlleritem.h"
#include "models/carta.h"

//#include <QObject>



class ControllSwipeView : public ControllerItem
{Q_OBJECT
    Q_PROPERTY(bool horizontal READ getHorizontal WRITE setHorizontal NOTIFY horizontalChanged)
    Q_PROPERTY(bool interactive READ getInteractive WRITE setInteractive NOTIFY interactiveChanged)
    Q_PROPERTY(QString orientation READ getOrientation WRITE setOrientation NOTIFY orientationChanged)
    Q_PROPERTY(bool vertical READ getVertical WRITE setVertical NOTIFY verticalChanged)


public:
    ControllSwipeView();
    ~ControllSwipeView();
    void appendItem(QPointer<Carta> l);
    Q_INVOKABLE void rmv_item(QStringList l);
    Q_INVOKABLE bool getHorizontal();
    Q_INVOKABLE bool getVertical();
    Q_INVOKABLE QString getOrientation();
    Q_INVOKABLE bool getInteractive();

    void setNext();

  Q_INVOKABLE  QStringList getNext();
  Q_INVOKABLE  QStringList getPrev();









    void setHorizontal(bool h);
    void setInteractive(bool i);
    void setOrientation(QString ori);
    void setVertical(bool v);

signals:
    void appendedItem(QStringList l);
    void rmvItem(QString idItem);
    void horizontalChanged(bool b);
    void interactiveChanged(bool b);
    void orientationChanged(QString b);
    void verticalChanged(bool b);
    void nextChanged(QStringList l);


private:

    int indice;
    int next;


    bool horizontal;
    bool interactive;
    QString orientation;
    bool vertical;

    QList<QPointer<Carta>> l = {};
};

#endif // CONTROLLSWIPEVIEW_H
