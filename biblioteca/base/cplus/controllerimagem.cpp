#include "controllerimagem.h"

ControllerImagem::ControllerImagem(QObject *parent, int largura, int altura) : ControllerItem(parent, altura, largura)
{

}

void ControllerImagem::setSource(QString caminho)
{
    qDebug() << "Entrou setSource cpp class" ;
    if(this->source != caminho){
        this->source = caminho;
        emit sourceChanged(this->source);
    }
    return;
}


QString ControllerImagem::getSource()
{
    return this->source;
}

void ControllerImagem::keyPressEvent(QKeyEvent *event)
{   if(event->key() == Qt::Key_Space){
        qDebug() << "Pressionou espaço c++";
    }

return;
}

/*void ControllerImagem::keyPressEvent(QKeyEvent *event)
{

}*/



