#ifndef MARCARARANDOMIZADA_H
#define MARCARARANDOMIZADA_H

#include <QObject>
#include <cstdlib>
#include <iostream>
#include <time.h>


class MarcaraRandomizada : public QObject
{Q_OBJECT
public:
    MarcaraRandomizada();


    double getResultadoOriginal() const;
    void setResultadoOriginal(double newResultadoOriginal);

    double getResultadoAluno() const;
    void setResultadoAluno(double newResultadoAluno);

    double getResultadoFrontParaAluno() const;
    void setResultadoFrontParaAluno(double newResultadoFrontParaAluno);

    double randomizar(double var);

    QList<double> getVariaveisOriginais() const;
    QList<double> getVariaveisRandomizadas() const;

    double appendVarOriginal(double var);

    double getNumeroRaizRandom();

signals:
    void mark(double valuMask);

private:
    double numeroRaizRandom;
    void appendVarRandomizada(double var);

    double resultadoOriginal;
    double resultadoAluno;
    double resultadoFrontParaAluno;
    QList<double> variaveisOriginais;
    QList<double> variaveisRandomizadas;
};

#endif // MARCARARANDOMIZADA_H
