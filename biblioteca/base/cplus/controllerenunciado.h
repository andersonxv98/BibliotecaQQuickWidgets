#ifndef CONTROLLERENUNCIADO_H
#define CONTROLLERENUNCIADO_H


#include "conecctionsql.h"
#include "controlleritem.h"
#include "models/calculadora.h"
#include "models/marcararandomizada.h"

class ControllerExercicio : public ControllerItem
{Q_OBJECT
public:
    ControllerExercicio(MarcaraRandomizada * maks);
    void setEnunciadoOnFront(QList<QStringList> enunciado);
    void setResultadoCorreto(QString r);
    Q_INVOKABLE void addLog(QString mov);
    Q_INVOKABLE QString calcular(QString A, QString B, QString operador);
    void setMascaraRandomizada(MarcaraRandomizada * mask);
   Q_INVOKABLE QStringList getLog();
    Q_INVOKABLE void enviar();
    Q_INVOKABLE QString getResultadoCalculador();
  Q_INVOKABLE  QString getResultadoNoMask() const;

signals:
   void enunciadoChanged(QList<QStringList> enunciado);
   void correctResult();
private:
   //QPointer<ConnectionSQL> con;
   QList<QStringList> enunciado;
   QStringList log;
   QString resultadoCorreto;
   QString resultado;
   QString resultadoNoMask;
    Calculadora c;
    double mask;
};

#endif // CONTROLLERENUNCIADO_H
