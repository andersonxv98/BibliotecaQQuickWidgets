#ifndef ALUNO_H
#define ALUNO_H


#include "qobject.h"
class Aluno : public QObject
{Q_OBJECT
public:
    Aluno(QString ra, QString nome, QString idSerie, QString serie);
    QString getRa() const;
    QString getNome() const;
    QString getSerie() const;
    QString getIdSerie() const;
private:
    void setRa(QString newRa);
    void setNome(const QString &newNome);
     void setSerie(const QString &newSerie);
     void setIdSerie(const QString &newIdSerie);
    QString ra;
    QString nome;
    QString serie;
    QString idSerie;
};

#endif // ALUNO_H
