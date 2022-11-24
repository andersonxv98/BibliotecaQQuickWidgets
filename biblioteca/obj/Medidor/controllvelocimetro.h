#ifndef CONTROLLVELOCIMETRO_H
#define CONTROLLVELOCIMETRO_H


#include "qqmlengine.h"
#include <QQuickWidget>
#include "qqmlcontext.h"
#include <QObject>
#include <biblioteca/base/cplus/controllerarc.h>
#include <biblioteca/base/cplus/controllerimagem.h>
#include <biblioteca/base/cplus/controllerkeys.h>
#include <biblioteca/base/cplus/controllmarcadores.h>
#include <biblioteca/base/cplus/controllretanguloqml.h>




class ControllVelocimetro :public  QQuickWidget
{ Q_OBJECT

public:
    ControllVelocimetro(QQuickWidget * parent = nullptr);
    virtual ~ControllVelocimetro();

    ControllRetanguloQml &getControladorRetanguloPai();//= new ControllRetanguloQml(nullptr,50,300);
    ControllerImagem  &getControlladorImagemFundo();//c_img;//= new  ControllerImagem(nullptr,50,50);
    ControllerImagem  &getControlladorImgCentro();//PRIMEROO COMPOENTE DO CIRCULO CENTRO RELOGIO  c_imgCentro;// = new  ControllerImagem(nullptr,50,50);
    ControllerImagem  &getControlladorImgCentro2();//SEGUNDO COMPOENTE DO CIRCULO CENTRO RELOGIO   c_imgCentro2;// = new  ControllerImagem(nullptr,50,50);
    ControllerImagem  &getControlladorImgPonteiroHora();//c_imgPonteiro;// = new ControllerImagem(nullptr, 50,50);
    //ControllerImagem  &getControlladorImgPonteiroMin();//c_imgPonteiroMaior;// = new ControllerImagem(nullptr, 50,50);
    //ControllerImagem  &getControlladorImgPonteiroSegundos();//c_imgPonteiroSegundos;//=  new ControllerImagem(nullptr, 50,50);
    ControllerKeys  &getControlladorKeysPress();// = new ControllerKeys();
    ControllerArc  &getControlladorArc0();//c_canvas;// = new ControllerArc();
    ControllerArc  &getControlladorArc1();// = new ControllerArc();
    ControllerArc  &getControlladorArc2();// = new ControllerArc();
    ControllerArc  &getControlladorArc3();// = new ControllerArc();
    ControllMarcadores &getControladorMarcadores();


   //QList<QPointer<ControllerSubItemDinamico>>  getListControlladoresMarcadoresRomanos();//list_;// = QList<ControllRetanguloQml *>();


    void start();

public slots:
    void test(bool v);





private:
    QPointer<QQmlEngine> self_engine;

    ControllMarcadores c_mark;
    ControllRetanguloQml  c_ret;//= new ControllRetanguloQml(nullptr,50,300);
    ControllerImagem  c_img;//= new  ControllerImagem(nullptr,50,50);
    ControllerImagem  c_imgCentro;// = new  ControllerImagem(nullptr,50,50);
    ControllerImagem  c_imgCentro2;// = new  ControllerImagem(nullptr,50,50);
    ControllerImagem  c_imgPonteiro;// = new ControllerImagem(nullptr, 50,50);
    //ControllerImagem  c_imgPonteiroMaior;// = new ControllerImagem(nullptr, 50,50);
    //ControllerImagem  c_imgPonteiroSegundos;//=  new ControllerImagem(nullptr, 50,50);

    ControllerKeys  kyes;// = new ControllerKeys();
    ControllerArc c_canvas;// = new ControllerArc();
    ControllerArc c_canvas2;// = new ControllerArc();
    ControllerArc c_canvas3;// = new ControllerArc();
    ControllerArc c_canvas0;// = new ControllerArc();

    int alt;
    int larg;


    //Q_PROPERTYS ATRIBUTES:






};

#endif // CONTROLLVELOCIMETRO_H
