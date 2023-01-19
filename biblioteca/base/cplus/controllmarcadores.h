#ifndef CONTROLLMARCADORES_H
#define CONTROLLMARCADORES_H

//#include "controlleritem.h"

#include "controllersubitemdinamico.h"
#include "controllretanguloqml.h"
#include "models/marcadores.h"



class ControllMarcadores : public ControllRetanguloQml
{Q_OBJECT


public:
    ControllMarcadores();

    Q_INVOKABLE QStringList getLista();

    void  addMarcador(QPointer<ControllerSubItemDinamico> val);

    QList<QPointer<ControllerSubItemDinamico>>  getListaSubItensDinamicos();
    void update();

    void hideMarcadores();
    void showMarcadores();
    void changAlturaTodosMarcadores(double val);
    void changAlturaMarcadorEspecifico(int index,double val);
    void changImgTodosMarcadores(QString url);
    void changImgMarcadorEspecifico(int index,QString url);
    void changTamanhoLabelTodosMarcadores(int tm);
    void changTamanhoLabelMarcadorEspecifico(int index,int tm);
    void changAllTextLabelMarcadores(QString txt);
    void changTextLabelMarcadorEspecifico(int index,QString txt);
    void changAllWeigthImgMarcadores(int w);
    void changWeigthImgMarcadorEspecifico(int index, int w);
    void changAllHeigthImgMarcadores(int h);
    void changHeigthImgMarcadorEspecifico(int index,int h);
    void changAllAngles(double a);
    void changAllAnglesWhileDoSpacing(double a);
    void setSpecificAngle(int index, double a);

    void changPositionOfSpecifcItem(int index, bool v);
    void changPositionOfAllMarks();

    void clearMarcadores();
    //void removeMarcadores();

    int getMarcadoresLength();
signals:
    void listaChanged(QStringList l);
    void marcadorCreated(QString l);
    void clearMarcadoreSignal();
private:
    QStringList bringQlist();
    bool default_bool = false;
    QList<QPointer<ControllerSubItemDinamico>>  lista= {};

};

#endif // CONTROLLMARCADORES_H
