#ifndef LOGINCREDENCIAIS_H
#define LOGINCREDENCIAIS_H


#include "qobject.h"
class LoginCredenciais: public QObject
{Q_OBJECT
public:
    LoginCredenciais();
    QString getUser() const;
    void setUser(const QString &newUser);

    QString getPass() const;
    void setPass(const QString &newPass);

private:
    QString user;
    QString pass;

};

#endif // LOGINCREDENCIAIS_H
