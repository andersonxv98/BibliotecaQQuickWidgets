#include "controllmarcadores.h"

ControllMarcadores::ControllMarcadores()
{

}

QStringList ControllMarcadores::getLista()
{
    QStringList l = this->bringQlist();
    return l;
}

void ControllMarcadores::addMarcador(QPointer<ControllerSubItemDinamico> val)
{
    if(!this->lista.contains(val)){
        this->lista.append(val);
       this->update();
    }
    return;
}



QList<QPointer<ControllerSubItemDinamico> > ControllMarcadores::getListaSubItensDinamicos()
{
    return this->lista;
}

void ControllMarcadores::update()
{
    QStringList l  =this->bringQlist();
    emit marcadorCreated(l[l.length()-1]);
    return;
}

void ControllMarcadores::hideMarcadores()
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_txt().setCor("transparent");
        //subitem->getC_rt().setCor("transparent");
        subitem->getC_img().setSource("");
    }
}

void ControllMarcadores::showMarcadores()
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_txt().setCor("black");
    }
    return;
}

void ControllMarcadores::changAlturaTodosMarcadores(double val)
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_rt().setAltura(val);
    }
    return;
}

void ControllMarcadores::changAlturaMarcadorEspecifico(int index, double val)
{
    this->lista[index]->getC_rt().setAltura(val);
    return;
}

void ControllMarcadores::changImgTodosMarcadores(QString url)
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_img().setSource(url);
    }
    return;
}

void ControllMarcadores::changImgMarcadorEspecifico(int index, QString url)
{
    qDebug() << "VAlor URL DA IGM: " <<this->lista[index]->getC_img().getSource();
            this->lista[index]->getC_img().setSource(url);
    return;
}

void ControllMarcadores::changTamanhoLabelTodosMarcadores(int tm)
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_txt().setFontSize(tm);
    }
    return;
}

void ControllMarcadores::changTamanhoLabelMarcadorEspecifico(int index, int tm)
{
    this->lista[index]->getC_txt().setFontSize(tm);
    return;
}

void ControllMarcadores::changAllTextLabelMarcadores(QString txt)
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_txt().setText(txt);
    }
    return;
}

void ControllMarcadores::changTextLabelMarcadorEspecifico(int index, QString txt)
{
    this->lista[index]->getC_txt().setText(txt);
    return;
}

void ControllMarcadores::changAllWeigthImgMarcadores(int w)
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_img().setLargura(w);
    }
    return;
}

void ControllMarcadores::changWeigthImgMarcadorEspecifico(int index, int w)
{
    this->lista[index]->getC_img().setLargura(w);
    return;
}

void ControllMarcadores::changAllHeigthImgMarcadores(int h)
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_img().setAltura(h);
    }
    return;
}

void ControllMarcadores::changHeigthImgMarcadorEspecifico(int index, int h)
{
    this->lista[index]->getC_img().setAltura(h);
    return;
}

void ControllMarcadores::changAllAngles(double a)
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_rt().setAngulo(a);
    }
    return;
}

void ControllMarcadores::changAllAnglesWhileDoSpacing(double a)
{
    double val = a;
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_rt().setAngulo(val);
        val+= a;
    }
    return;
}

void ControllMarcadores::setSpecificAngle(int index, double a)
{
    this->lista[index]->getC_rt().setAngulo(a);
    return;
}

void ControllMarcadores::changPositionOfSpecifcItem(int index, bool v)
{
    this->lista[index]->getC_rt().setAnchor(v);
    return;
}



void ControllMarcadores::changPositionOfAllMarks()
{
    this->default_bool = !this->default_bool;
     for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_rt().setAnchor(this->default_bool);
    }
    return;
}

void ControllMarcadores::clearMarcadores()
{
    for(ControllerSubItemDinamico * subitem: this->lista){
        subitem->getC_txt().setText("");
        //subitem->getC_rt().setCor("transparent");
        subitem->getC_img().setSource("");
    }
    this->lista.clear();

    return;
    //emit clearMarcadoreSignal();
}

int ControllMarcadores::getMarcadoresLength()
{
    return this->lista.length();
}



QStringList ControllMarcadores::bringQlist()
{
    QStringList l = {};

    for(ControllerSubItemDinamico * subitem: this->lista){
        QString sb_l = subitem->getC_rt().getId_objQStr();
        l.append(sb_l);
    }
    return l;
}


