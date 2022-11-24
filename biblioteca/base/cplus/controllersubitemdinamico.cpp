#include "controllersubitemdinamico.h"

ControllerSubItemDinamico::ControllerSubItemDinamico(QString idRect, QString msgText, QString url)
{

   this->c_rt.setId_objQStr(idRect);
   this->c_txt.setId_objQStr(idRect);
   this->c_img.setId_objQStr(idRect);

   this->c_txt.setText(msgText);
   this->c_img.setSource(url);
    thisId=  id++;

}

int ControllerSubItemDinamico::id = 0;

ControllerImagem &ControllerSubItemDinamico::getC_img()
{
    return this->c_img;
}

ControllRetanguloQml &ControllerSubItemDinamico::getC_rt()
{return this->c_rt;

}

ControllerCustomText &ControllerSubItemDinamico::getC_txt()
{
    return this->c_txt;
}

int ControllerSubItemDinamico::getId()
{return this->thisId;;

}
