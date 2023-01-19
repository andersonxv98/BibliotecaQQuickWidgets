#include "marcararandomizada.h"

MarcaraRandomizada::MarcaraRandomizada()
{
    srand(time(0));

    int N= 100;
    this->variaveisRandomizadas.clear();
    this->variaveisOriginais.clear();
   this->numeroRaizRandom =  rand() % N + 1; //randomizar numero de 1 a 100

}

double MarcaraRandomizada::getResultadoOriginal() const
{
    return resultadoOriginal;
}

void MarcaraRandomizada::setResultadoOriginal(double newResultadoOriginal)
{
    resultadoOriginal = newResultadoOriginal;
}

double MarcaraRandomizada::getResultadoAluno() const
{
    return resultadoAluno;
}

void MarcaraRandomizada::setResultadoAluno(double newResultadoAluno)
{
    resultadoAluno = newResultadoAluno;
}

double MarcaraRandomizada::getResultadoFrontParaAluno() const
{
    return resultadoFrontParaAluno;
}

void MarcaraRandomizada::setResultadoFrontParaAluno(double newResultadoFrontParaAluno)
{
    resultadoFrontParaAluno = newResultadoFrontParaAluno;
}

double MarcaraRandomizada::randomizar(double var)
{
    double result = var * this->numeroRaizRandom;
    return result;
}

QList<double> MarcaraRandomizada::getVariaveisOriginais() const
{
    return variaveisOriginais;
}

QList<double> MarcaraRandomizada::getVariaveisRandomizadas() const
{
    return variaveisRandomizadas;
}

double  MarcaraRandomizada::appendVarOriginal(double var)
{
    this->variaveisOriginais.append(var);
    double result  = this->randomizar(var);
    this->variaveisRandomizadas.append(result);
    return result;
}

double MarcaraRandomizada::getNumeroRaizRandom()
{
    return numeroRaizRandom;
}
