#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <cmath>

#include <qDebug>
class Calculadora
{
public:
    Calculadora();
    double multiplicacao(double numA, double numB);
    double divisao(double numA, double numB);
    double soma(double numA, double numB);
    double subtracao(double numA, double numB);
    double expoente(double numA, double numB);
    double radQuadrada(double numA);
    double getResult();


private:

    void setResult(double r);
    double result;

};

#endif // CALCULADORA_H
