QT       += core gui\
    quick\
    widgets \
    qml \
    quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core gui\
quick\
widgets \
qml \
quickwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp\
    biblioteca/base/cplus/controlleranimation.cpp \
    biblioteca/base/cplus/controllerarc.cpp \
    biblioteca/base/cplus/controllercustomtext.cpp \
    biblioteca/base/cplus/controllerimagem.cpp \
    biblioteca/base/cplus/controlleritem.cpp \
    biblioteca/base/cplus/controllerkeys.cpp \
    biblioteca/base/cplus/controllerrotation.cpp \
    biblioteca/base/cplus/controllersubitemdinamico.cpp \
    biblioteca/base/cplus/controllmarcadores.cpp \
    biblioteca/base/cplus/controllretanguloqml.cpp \
    biblioteca/base/cplus/models/marcadores.cpp \
    biblioteca/obj/Medidor/controllvelocimetro.cpp \



HEADERS += \
    mainwindow.h\
    biblioteca/base/cplus/controlleranimation.h \
    biblioteca/base/cplus/controllerarc.h \
    biblioteca/base/cplus/controllercustomtext.h \
    biblioteca/base/cplus/controllerimagem.h \
    biblioteca/base/cplus/controlleritem.h \
    biblioteca/base/cplus/controllerkeys.h \
    biblioteca/base/cplus/controllerrotation.h \
    biblioteca/base/cplus/controllersubitemdinamico.h \
    biblioteca/base/cplus/controllmarcadores.h \
    biblioteca/base/cplus/controllretanguloqml.h \
    biblioteca/base/cplus/models/marcadores.h \
    biblioteca/obj/Medidor/controllvelocimetro.h \

FORMS += \
    mainwindow.ui

RESOURCES += biblioteca/base/qml/retangulo.qml\
    biblioteca/base/qml/imagem.qml\
    biblioteca/base/qml/ponteiro.qml\
    biblioteca/base/qml/component1.qml \
    biblioteca/base/qml/component2.qml \
    biblioteca/base/qml/Arc.qml\
    biblioteca/base/qml/arc2.qml\
    biblioteca/base/qml/arc3.qml \
    biblioteca/base/qml/arc0.qml \
    biblioteca/base/qml/customlabel.qml\
    biblioteca/base/qml/marcadores.qml\
    biblioteca/obj/Medidor/main.qml\
    biblioteca/base/svg/olv/green.svg \
    biblioteca/base/svg/olv/lightgreen.svg \
    biblioteca/base/svg/olv/red.svg \
    biblioteca/base/svg/olv/yellow.svg\
    biblioteca/base/svg/VUmeter2.svg \
    biblioteca/base/svg/VUmeter.svg \
    biblioteca/base/svg/agulha1.svg \
    biblioteca/base/svg/agulha2.svg \
    biblioteca/base/svg/colors.svg \
    biblioteca/base/svg/medidor.svg \
    biblioteca/base/svg/medidor2.svg \
    biblioteca/base/svg/fundo.svg\
    biblioteca/base/svg/agulhacortado.svg\
    biblioteca/base/svg/agulhacortado2.svg\
    biblioteca/base/svg/Agula1/parteA.svg \
    biblioteca/base/svg/Agula1/parteC.svg \
    biblioteca/base/svg/Agula1/parteb.svg\
    biblioteca/base/svg/cleiton.jfif
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    biblioteca/base/svg/cleiton.jfif
