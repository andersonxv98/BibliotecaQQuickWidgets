#include "controllercarta.h"

ControllerCarta::ControllerCarta(QString idCard, QString msgText)
{
    this->c_ret.setId_objQStr(idCard);
    this->c_txt.setId_objQStr(idCard);

    this->c_txt.setText(msgText);

    thisId=  id++;
}

int ControllerCarta::id = 0;

ControllRetanguloQml &ControllerCarta::getC_ret()
{
    return this->c_ret;
}

ControllerCustomText &ControllerCarta::getC_txt()
{
    return this->c_txt;
}
