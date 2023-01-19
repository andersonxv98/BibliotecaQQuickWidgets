#ifndef EXERCICIO_H
#define EXERCICIO_H


#include <QObject>
#include <QString>
#include <QDebug>>


class Exercicio : public QObject
{Q_OBJECT
public:
    Exercicio(QString id,
    QString professor,
    QString enunciado,
    QString resultado);

    QString getEnunciado();
    QString getResultado();
    QString getProfessor();
    QString getId();

    void addLog(QString l);
    QStringList getLog();
private:
    void setEnunciado(QString s);
    void setResultado(QString s);
    void setProfessor(QString s);
    void setId(QString s);


    QString enunciado;
    QString resultado;
    QString professor;
    QString id;
    QStringList log;
};

#endif // EXERCICIO_H
