#ifndef COMPONENTECOMPOSTO_H
#define COMPONENTECOMPOSTO_H

#include "componente.h"



class ComponenteComposto : public Componente
{
public:
    ComponenteComposto();

    void setComponent1(Componente * c1);
    void setComponent2(Componente * c2);

    Componente * getComponent1();
    Componente * getComponent2();
 private:
    Componente * c1;
    Componente * c2;

};

#endif // COMPONENTECOMPOSTO_H
