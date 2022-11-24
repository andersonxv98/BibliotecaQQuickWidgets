#include "marcadores.h"

Marcadores::Marcadores(string id, string texto)
{
    this->setId(id);
    this->setTexto(texto);
}

 string Marcadores::getId()
{
    return id;
}

void Marcadores::setId(string newId)
{
    id = newId;
}

string Marcadores::getTexto()
{
    return texto;
}

void Marcadores::setTexto(string newTexto)
{
    texto = newTexto;
}
