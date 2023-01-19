#ifndef CONTROLLERMATERIAS_H
#define CONTROLLERMATERIAS_H


#include "conecctionsql.h"
#include "controllerenunciado.h"
#include "controllerlogin.h"
#include "models/materia.h"
#include "models/marcararandomizada.h"
class ControllerMaterias : public QObject
{Q_OBJECT
public:
    ControllerMaterias(QPointer<ConnectionSQL> conn, ControllerExercicio * c_enun, MarcaraRandomizada * m);

    QList<QPointer<Materia>> getMaterias();
    Q_INVOKABLE QStringList getMateriasToFront();

    Q_INVOKABLE void showExercicios(QString materia_titulo);
    Q_INVOKABLE void showExercicioResolucao(QString idExercicio);
    QPointer<ControllerLogin> getCtrl_aluno();
    Q_INVOKABLE void doRequest();
    Q_INVOKABLE void registLog(QString mov);
    Q_INVOKABLE void registResult(QString result);
    MarcaraRandomizada *getMask() const;

signals:
    void materiaAppended(QString materia, int qtd);
    void materiaExercicios(QString exercId);
    void exercicioResolved(QString exercId);
private:

    void addMaterias(QPointer<Materia> m);
    MarcaraRandomizada * mask;
    QList<QPointer<Materia>> materias;
    QList<QPointer<Exercicio>> current_exer;
    QPointer<ConnectionSQL> conection;
    QPointer<ControllerLogin> ctrl_aluno;
    ControllerExercicio * c_enun;
    QString idEx;
    QStringList listExerHold;
};

#endif // CONTROLLERMATERIAS_H
