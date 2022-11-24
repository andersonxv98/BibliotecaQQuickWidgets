#ifndef CONTROLLERIMAGEM_H
#define CONTROLLERIMAGEM_H

#include "controlleritem.h"

#include <QKeyEvent>
#include <QObject>



class ControllerImagem : public ControllerItem
{
    Q_OBJECT
    Q_PROPERTY(QString source READ getSource WRITE setSource NOTIFY sourceChanged)

public:
    ControllerImagem(QObject * parent = nullptr, int largura=0, int altura=0);

    void setSource(QString caminho);

    Q_INVOKABLE QString getSource();

protected:
    void keyPressEvent(QKeyEvent *event);

public:
    signals:
    void sourceChanged(QString caminho);

private:
    QString source;

};

#endif // CONTROLLERIMAGEM_H
