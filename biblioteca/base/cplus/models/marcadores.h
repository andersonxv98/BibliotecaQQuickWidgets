#ifndef MARCADORES_H
#define MARCADORES_H

#include <string>


using namespace std;
class Marcadores
{
public:
    Marcadores(string id, string texto);

    string getId();


    string getTexto();


private:
    string id;
    string texto;

     void setId(string newId);
     void setTexto(string newTexto);
};

#endif // MARCADORES_H
