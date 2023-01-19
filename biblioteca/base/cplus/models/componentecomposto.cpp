#include "componentecomposto.h"

ComponenteComposto::ComponenteComposto()
{

}

void ComponenteComposto::setComponent1(Componente *c1)
{
    this->c1 = c1;
}

void ComponenteComposto::setComponent2(Componente *c2)
{this->c2 = c2;

}

Componente *ComponenteComposto::getComponent1()
{
    return this->c1;
}

Componente *ComponenteComposto::getComponent2()
{
return this->c2;
}

