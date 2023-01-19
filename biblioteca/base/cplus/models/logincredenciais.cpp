#include "logincredenciais.h"

LoginCredenciais::LoginCredenciais()
{

}

QString LoginCredenciais::getUser() const
{
    return user;
}

void LoginCredenciais::setUser(const QString &newUser)
{
    user = newUser;
}

QString LoginCredenciais::getPass() const
{
    return pass;
}

void LoginCredenciais::setPass(const QString &newPass)
{
    pass = newPass;
}
