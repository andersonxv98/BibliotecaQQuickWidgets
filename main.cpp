
//#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QQuickWindow>
#include <QVBoxLayout>
#include "biblioteca/obj/Medidor/controllvelocimetro.h"
#include <iostream>
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("UZUMAKI0");
   // QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
    ControllVelocimetro * engine = new ControllVelocimetro();


   // engine->setSource(QUrl("qrc:VelocimetroQmls/main.qml"));
    //engine.setMinimumSize(100, 100); // colocar  as dimensões minimas do objeto

    //engine->setMaximumSize(1061, 800);
            //engine()->setFocusPolicy(Qt::TabFocus);


    QPushButton *  test = new   QPushButton("teste");
    QObject::connect(test, &QPushButton::clicked, engine, &ControllVelocimetro::test);


    QVBoxLayout  slayout  =  QVBoxLayout();
    slayout.addWidget(engine);
    slayout.addWidget(test);
    QWidget  central =  QWidget();
    central.setLayout(&slayout);
    //view.r




    mainWindow.setCentralWidget(&central);//(engine.focusWidget());


    //
    /*const QUrl url(u"qrc:/CompsRegular/main.qml"_qs);
    QObject::connect(&engine, &RelogioApp::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
*/
    //engine->startApp();
    mainWindow.show();
    engine->showFullScreen();
    engine->start();
    //engine->getControladorRetanguloPai().setCor("transparent");

   engine->getControladorMarcadores().changTextLabelMarcadorEspecifico(2, "casadas");
    engine->getControladorMarcadores().changImgMarcadorEspecifico(0, "qrc:/biblioteca/base/svg/cleiton.jfif");
    //engine.getControladorMarcadores().an("");
    return app.exec();
}
