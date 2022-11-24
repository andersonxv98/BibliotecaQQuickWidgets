#ifndef CONTROLLERKEYS_H
#define CONTROLLERKEYS_H

#include <QKeyEvent>
#include <QObject>



class ControllerKeys : public QObject
{Q_OBJECT
    //Q_PROPERTY(QKe name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit ControllerKeys(QObject * parent= nullptr);

    Q_INVOKABLE void showMyKey(QString k);

public:




};

#endif // CONTROLLERKEYS_H
