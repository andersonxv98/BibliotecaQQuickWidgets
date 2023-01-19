#ifndef MATERIA_H
#define MATERIA_H

#include "exercicio.h"

#include <QList>
#include <QPointer>
#include "../BibliotecaQQuickWidgets/biblioteca/base/cplus/conecctionsql.h"


class Materia : public QObject
{Q_OBJECT
public:
    Materia(int id, QString nome, QPointer<ConnectionSQL> con, QString serieId);
    //~Materia();


    QString getNome() const;

    QList<QPointer<Exercicio> > getExercicios() const;
    void addExercicio(QPointer<Exercicio> ex);
    QString getSerieId() const;

private:
    void setNome(const QString &newNome);
    void setId(int id);
    void doRequest();
    void setSerieId(const QString &newSerieId);

    QPointer<ConnectionSQL> conection;
    int id;
    QString nome;
    QString serieId;
    QList<QPointer<Exercicio>> exercicios;
};

#endif // MATERIA_H
