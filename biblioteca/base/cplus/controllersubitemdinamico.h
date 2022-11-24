#ifndef CONTROLLERSUBITEMDINAMICO_H
#define CONTROLLERSUBITEMDINAMICO_H


#include "controllercustomtext.h"
#include "controllerimagem.h"
#include "controllretanguloqml.h"
class ControllerSubItemDinamico : public QObject
{
public:
    ControllerSubItemDinamico(QString idRect= "", QString msgText="", QString url= "");

    ControllerImagem &getC_img();
    ControllRetanguloQml &getC_rt();
    ControllerCustomText &getC_txt();
    int getId();


private:
    static int id;
    int thisId;
    ControllerImagem c_img;
    ControllRetanguloQml c_rt;
    ControllerCustomText c_txt;
};

#endif // CONTROLLERSUBITEMDINAMICO_H
