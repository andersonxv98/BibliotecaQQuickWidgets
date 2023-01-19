#include "controllerenunciado.h"
#include "models/calculadora.h"

#include <QString>

ControllerExercicio::ControllerExercicio(MarcaraRandomizada *maks)
{
    this->mask = maks->getNumeroRaizRandom();
    this->log = {};
}

void ControllerExercicio::setEnunciadoOnFront(QList<QStringList> enunciado)
{
    //if(this->enunciado != enunciado){
        this->enunciado = enunciado;
        emit enunciadoChanged(this->enunciado);
    //}
    return;
}

void ControllerExercicio::setResultadoCorreto(QString r)
{
this->resultadoCorreto = r;
}

void ControllerExercicio::addLog(QString mov)
{

    this->log.append(mov);
}

QString ControllerExercicio::calcular(QString A, QString B, QString operador)
{
    qDebug() << "entrou em calcular: ";
    QString resultado= "Erro: não foi possivel Calcular";
    double a = A.toDouble();
    double b = B.toDouble();
    double noMask = this->mask;
    double aNoMask = a / noMask;
    double bNoMask = b / noMask;
    qDebug() << "valores no mask dentro da funcao calcular: " << aNoMask << " : " << bNoMask;
    QString rnoMask= "erro: não calculavel";
    if((A != "" && B != "") && (A != resultado && B != resultado)){

        if(operador.contains("+")){
            double r = c.soma(a, b);
            double rnM = c.soma(aNoMask, bNoMask);
            rnoMask = QString::number(rnM);
            resultado = QString::number(r);
        }
        else if (operador.contains("-")){
            double r = c.subtracao(a, b);
            double rnM = c.subtracao(aNoMask, bNoMask);
            rnoMask = QString::number(rnM);
            resultado = QString::number(r);
        }
        else if (operador.contains("/") || operador.contains("───")){
            double r = c.divisao(a, b);
            double rnM = c.divisao(aNoMask, bNoMask);
            rnoMask = QString::number(rnM);
            resultado = QString::number(r);
        }
        else if (operador.contains("*")){
            double r = c.multiplicacao(a, b);
            double rnM = c.multiplicacao(aNoMask, bNoMask);
            rnoMask = QString::number(rnM);
            resultado = QString::number(r);
        }
        else if (operador.contains("^")){
            double r = c.expoente(a, b);
            double rnM = c.expoente(aNoMask, bNoMask);
            rnoMask = QString::number(rnM);
            resultado = QString::number(r);
        }

        else{
            qDebug() << "VALOR OPERADOR: " << operador;
        }
    }
    else{
        if(A != resultado && B !=resultado){
            if (operador.contains("√") || operador.contains("v") ){
                qDebug() << "valor A: "<< a;
                qDebug() << "valor B: "<< b;
                double r = c.expoente(a, 0.5);
                resultado = QString::number(r);
                if(a > 0  && b > 0){
                    double bb = c.expoente(b, 1/a);
                    resultado = QString::number(bb);
                }
            }
        }
    }
    this->resultadoNoMask = rnoMask;
    this->resultado = resultado;
    if(rnoMask == this->resultadoCorreto){
        qDebug() << "entrou condiçao resultados iguais" ;
        emit correctResult();
    }
    return resultado;

}

void ControllerExercicio::setMascaraRandomizada(MarcaraRandomizada *mask)
{
    qDebug() << "entrou em set Maks dentro da classe controllerExercicio";
    this->mask = mask->getNumeroRaizRandom();
}

QStringList ControllerExercicio::getLog()
{
    for(QString moviment: this->log){
        qDebug() <<"Movimento:  " << moviment;
    }
    return this->log;
}

void ControllerExercicio::enviar()
{
    this->c.getResult();
}

QString ControllerExercicio::getResultadoCalculador()
{
    return this->resultado;
}

QString ControllerExercicio::getResultadoNoMask() const
{
    return resultadoNoMask;
}
