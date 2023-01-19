#include "calculadora.h"



Calculadora::Calculadora()
{

}

double Calculadora::multiplicacao(double numA, double numB)
{   setResult(numA * numB);
    return this->result;
}

double Calculadora::divisao(double numA, double numB)
{
    setResult(numA / numB);
    return this->result;
}

double Calculadora::soma(double numA, double numB)
{
    setResult(numA + numB);
    return this->result;
}

double Calculadora::subtracao(double numA, double numB)
{
    setResult(numA - numB);
    return this->result;
}

double Calculadora::expoente(double numA, double numB)
{
    setResult(pow(numA, numB));
    return this->result;
}

double Calculadora::radQuadrada(double numA)
{
    qDebug() << "entrou no calculo de Raiz Quadrada. Valor numA: ", numA;
    setResult(pow(numA, (1/2)));
    return this->result;
}

double Calculadora::getResult()
{
    return this->result;
}

void Calculadora::setResult(double r)
{
    if(this->result != r){
    this->result = r;
    }
}
