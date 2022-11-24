#ifndef CONTROLLERARC_H
#define CONTROLLERARC_H


#include "controlleritem.h"
#include "QDebug"


class ControllerArc : public ControllerItem
{Q_OBJECT

    Q_PROPERTY(double init READ getInit WRITE setInit NOTIFY initChanged)
    Q_PROPERTY(double end READ getEnd WRITE setEnd NOTIFY endChanged)
    Q_PROPERTY(bool anticlockwise READ getAnticlockWise WRITE setAnticlockWise NOTIFY anticlockwiseChanged)
    Q_PROPERTY(QString cor READ getCor WRITE setCor NOTIFY corChanged)
    Q_PROPERTY(int sizeModificador READ getSizeModificador WRITE setSizeModificador NOTIFY sizeModificadorChanged)
    Q_PROPERTY(bool buraco READ getBuraco WRITE setBuraco NOTIFY buracoChanged)


public:
    ControllerArc(QObject * parent = nullptr);

    void setPosicaoInicialByPorcentagem(double val);
    void setPosicaoFinalByPorcentagem(double val);
    void setAnticlockWise(bool f);
    void setCor(QString color);
    void setSizeModificador(double val);
    void setBuraco(bool f);

    Q_INVOKABLE  double getInit();
    Q_INVOKABLE double getEnd();
    Q_INVOKABLE  bool getAnticlockWise();
    Q_INVOKABLE QString getCor();
    Q_INVOKABLE int getSizeModificador();
    Q_INVOKABLE bool getBuraco();

signals:
   void initChanged(double val);
   void endChanged(double val);
   void anticlockwiseChanged(double val);
   void corChanged(QString cor);
   void sizeModificadorChanged(double mod);
   void buracoChanged(bool f);
private:
   void setInit(double val);
    void setEnd(double val);

    double init;
    double end;
    int sizeModificador;
    bool anticlockwise;
    QString cor;
    bool buraco;

};

#endif // CONTROLLERARC_H
