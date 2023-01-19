#ifndef CONTROLLERCARTA_H
#define CONTROLLERCARTA_H


#include "controllercustomtext.h"
#include "controllretanguloqml.h"
class ControllerCarta : public QObject
{
public:
    ControllerCarta(QString idCard = "", QString msgText= "");

    ControllRetanguloQml &getC_ret();
    ControllerCustomText &getC_txt();

 private:
    static int id;
    int thisId;

    ControllRetanguloQml c_ret;
    ControllerCustomText c_txt;
};

#endif // CONTROLLERCARTA_H
