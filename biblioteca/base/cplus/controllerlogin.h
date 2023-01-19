#ifndef CONTROLLERLOGIN_H
#define CONTROLLERLOGIN_H


#include "models/aluno.h"
#include "conecctionsql.h"
#include <QObject>

class ControllerLogin : public QObject
{Q_OBJECT
public:
    ControllerLogin(QPointer<ConnectionSQL> con);

    Q_INVOKABLE bool login(QString ra, QString pass);
    QPointer<Aluno> getAluno() const;
signals:
    void authorization(bool b);
private:
    QPointer<Aluno> aluno;
    //QPointer<LoginCredenciais> l;
    QPointer<ConnectionSQL> con;

};

#endif // CONTROLLERLOGIN_H
