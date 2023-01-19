#include "exercicio.h"

Exercicio::Exercicio(QString id,
                     QString professor,
                     QString enunciado,
                     QString resultado)
{
    this->setEnunciado(enunciado);
    this->setResultado(resultado);
    this->setProfessor(professor);
    this->setId(id);
    qDebug() << "eentrou construtor exercicio> : ";
}

QString Exercicio::getEnunciado()
{
    return this->enunciado;
}

QString Exercicio::getResultado()
{return this->resultado;

}

QString Exercicio::getProfessor()
{
    return this->professor;
}

QString Exercicio::getId()
{
    return this->id;
}

void Exercicio::addLog(QString l)
{
    if(this->log.count() > 0){
        if(this->log[this->log.count()-1] != l){
            this->log.append(l);
        }
    }
    return;
}

QStringList Exercicio::getLog()
{
return this->log;
}

void Exercicio::setEnunciado(QString s)
{
if(this->enunciado != s){
    this->enunciado = s;
}
return;
}

void Exercicio::setResultado(QString s)
{
    if(this->resultado != s){
        this->resultado = s;
    }
    return;
}


void Exercicio::setProfessor(QString s)
{
    if(this->professor != s){
        this->professor = s;
    }
    return;
}

void Exercicio::setId(QString s)
{
    if(this->id != s){
        this->id = s;
    }
    return;
}

