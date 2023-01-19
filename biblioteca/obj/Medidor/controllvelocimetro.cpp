#include "controllvelocimetro.h"




ControllVelocimetro::ControllVelocimetro(QQuickWidget *parent) : QQuickWidget(parent)
{
    self_engine = this->engine();
    this->setResizeMode(QQuickWidget::SizeRootObjectToView);
     QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
    self_engine->rootContext()->setContextProperty("controllador",&c_ret);
   self_engine->rootContext()->setContextProperty("controllimg",&c_img);
   self_engine->rootContext()->setContextProperty("controllkeys",&kyes);
   self_engine->rootContext()->setContextProperty("controllStaticImg",&c_imgCentro);
   self_engine->rootContext()->setContextProperty("controllStaticImg2",&c_imgCentro2);
   self_engine->rootContext()->setContextProperty("controllPonteiro",&c_imgPonteiro);
   self_engine->rootContext()->setContextProperty("controllCanvas", &c_canvas);
   self_engine->rootContext()->setContextProperty("controllCanvas2", &c_canvas2);
   self_engine->rootContext()->setContextProperty("controllCanvas3", &c_canvas3);
   self_engine->rootContext()->setContextProperty("controllCanvas0", &c_canvas0);

   self_engine->rootContext()->setContextProperty("controllMarcadores", &c_mark);

   for(int z= 1; z< 18;  z++){

       QPointer<ControllerSubItemDinamico>  item = new ControllerSubItemDinamico("m"+QString::number(z), QString::number(z), "");
       qDebug() <<" VALOR ITEM[TEXTO]: "<< item->getC_txt().getText();
       c_mark.addMarcador(item);
                //qDebug() << "Valor id objsDinamic" << cont->getId();
       self_engine->rootContext()->setContextProperty("controllMarcadoresm"+QString::number(z), &item->getC_rt());
       self_engine->rootContext()->setContextProperty("controllSubtxttxtm"+QString::number(z), &item->getC_txt());
        self_engine->rootContext()->setContextProperty("controllSubimgimgm"+QString::number(z), &item->getC_img());

}

    //this->setClearColor("BLACK");
    //this->setResizeMode(QQuickWidget::SizeRootObjectToView);

   this->setSource(QUrl("qrc:/biblioteca/obj/Medidor/main.qml"));

    //this->start();


    //BIND VALES TO Q_PROPERTYS ATRIBUTES:




}

ControllVelocimetro::~ControllVelocimetro()
{
    return;
}

ControllRetanguloQml &ControllVelocimetro::getControladorRetanguloPai()
{
    return this->c_ret;
}

ControllerImagem &ControllVelocimetro::getControlladorImagemFundo()
{
    return this->c_img;
}

ControllerImagem &ControllVelocimetro::getControlladorImgCentro()
{
    return this->c_imgCentro;
}

ControllerImagem &ControllVelocimetro::getControlladorImgCentro2()
{
    return this->c_imgCentro2;
}

ControllerImagem &ControllVelocimetro::getControlladorImgPonteiroHora()
{
    return this->c_imgPonteiro;
}


ControllerKeys &ControllVelocimetro::getControlladorKeysPress()
{
    return this->kyes;
}

ControllerArc &ControllVelocimetro::getControlladorArc0()
{
    return this->c_canvas0;
}

ControllerArc &ControllVelocimetro::getControlladorArc1()
{   return this->c_canvas;

}

ControllerArc &ControllVelocimetro::getControlladorArc2()
{
    return this->c_canvas2;
}

ControllerArc &ControllVelocimetro::getControlladorArc3()
{return this->c_canvas3;

}

ControllMarcadores &ControllVelocimetro::getControladorMarcadores()
{
    return this->c_mark;
}

void ControllVelocimetro::start()
{
    c_imgCentro.setSource("qrc:/biblioteca/base/svg/Agula1/parteC.svg");
    c_imgCentro2.setSource("qrc:/biblioteca/base/svg/Agula1/parteb.svg");


    c_imgPonteiro.setSource("qrc:/biblioteca/base/svg/Agula1/parteA.svg");

    c_imgPonteiro.setAngulo(1);
    c_ret.setOpacity(1);
    c_ret.setCor("transparent");




    c_canvas0.setCor("green");
    c_canvas0.setPosicaoInicialByPorcentagem(50);
    c_canvas0.setPosicaoFinalByPorcentagem(62.5);

    c_canvas0.setBuraco(true);
    c_canvas0.setSizeModificador(4); // respossavel por modificar  comportamento de  arredondamento de borda, divide a largura pelo numero do mod

    c_canvas.setCor("lightgreen");
    c_canvas.setPosicaoInicialByPorcentagem(62.5);
    c_canvas.setPosicaoFinalByPorcentagem(75);

    c_canvas.setSizeModificador(4); // respossavel por modificar  comportamento de  arredondamento de borda, divide a largura pelo numero do mod
    c_canvas.setBuraco(true);

    c_canvas2.setCor("#e8b75d");
    c_canvas2.setPosicaoInicialByPorcentagem(75);
    c_canvas2.setPosicaoFinalByPorcentagem(90);

    c_canvas2.setSizeModificador(4); // respossavel por modificar  comportamento de  arredondamento de borda, divide a largura pelo numero do mod
    c_canvas2.setBuraco(true);

    c_canvas3.setCor("red");
    c_canvas3.setPosicaoInicialByPorcentagem(90);
    c_canvas3.setPosicaoFinalByPorcentagem(100);

    c_canvas3.setSizeModificador(4); // respossavel por modificar  comportamento de  arredondamento de borda, divide a largura pelo numero do mod
    c_canvas3.setBuraco(true);


    int lm = 1;
   for (ControllerSubItemDinamico * c_SubItm : c_mark.getListaSubItensDinamicos()){
        c_SubItm->getC_rt().setAngulo(lm * 10);
        ControllerImagem  &imss = c_SubItm->getC_img();
        imss.setSource("qrc:biblioteca/base/svg/medidor2.svg");
        lm++;
   }
}

void ControllVelocimetro::test(bool v)
{
    qDebug() << "Deu trigger ON test() ";
    QString blue = QString("Blue");
    this->c_canvas.setCor(blue);
    //this->c_imgPonteiro.setSource("");
    //this->c_mark.changAllAngles(3);
    //this->c_mark.changAllAnglesWhileDoSpacing(3);
    //this->c_mark.setSpecificAngle(0, 90);
    //this->c_canvas0.setPosicaoInicialByPorcentagem(60);
    //this->c_canvas0.setPosicaoFinalByPorcentagem(130);
    //this->c_canvas0.setCor("pink");
    //this->c_canvas.setPosicaoInicialByPorcentagem(0);
    //this->c_canvas.setPosicaoFinalByPorcentagem(0);
    //this->c_canvas2.setPosicaoInicialByPorcentagem(0);
    //this->c_canvas2.setPosicaoFinalByPorcentagem(0);
    //this->c_canvas3.setPosicaoInicialByPorcentagem(0);
    //this->c_canvas3.setPosicaoFinalByPorcentagem(0);
    //qDebug()<<"VALOR POSIçao ANGLUO"<< this->c_imgPonteiro.getAngulo();
    //this->c_imgPonteiro.setAngulo(90);
    //this->c_mark.changAllTextLabelMarcadores("i");
    //this->c_mark.changAlturaTodosMarcadores(500);
    qDebug() << "valor get altura: "<< this->c_mark.getListaSubItensDinamicos()[0]->getC_rt().getAltura();
    this->c_canvas0.setBuraco(true);
    this->c_canvas.setBuraco(false);
    this->c_canvas2.setBuraco(true);
    this->c_canvas3.setBuraco(false);
    //this->c_canvas2.setCor("transparent");
    //this->c_canvas3.setCor("transparent");
    //this->c_canvas.setCor("transparent");
    //this->c_canvas0.setCor("transparent");
    this->c_mark.changPositionOfAllMarks();
    this->c_mark.changPositionOfSpecifcItem(0, true);
    this->c_img.setSource("qrc:/biblioteca/base/svg/cleiton.jfif");
    this->c_img.setAltura(this->size().height());
    this->c_img.setLargura(this->size().width());

    return;
}








