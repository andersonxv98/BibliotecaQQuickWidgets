#include "aluno.h"

Aluno::Aluno(QString ra, QString nome, QString idSerie, QString serie)
{
    this->setRa(ra);
    this->setNome(nome);
    this->setSerie(serie);
    this->setIdSerie(idSerie);
}

QString Aluno::getRa() const
{
    return ra;
}

void Aluno::setRa(QString newRa)
{
    ra = newRa;
}

QString Aluno::getNome() const
{
    return nome;
}

void Aluno::setNome(const QString &newNome)
{
    nome = newNome;
}

QString Aluno::getSerie() const
{
    return serie;
}

void Aluno::setSerie(const QString &newSerie)
{
    serie = newSerie;
}

QString Aluno::getIdSerie() const
{
    return idSerie;
}

void Aluno::setIdSerie(const QString &newIdSerie)
{
    idSerie = newIdSerie;
}
