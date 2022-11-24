#include "controllercustomtext.h"
#include "qdebug.h"

ControllerCustomText::ControllerCustomText(ControllerItem *parent) : ControllerItem(parent)
{

}

void ControllerCustomText::setText(QString s)
{
    if(this->text != s){
        this->text = s;
        emit textChanged(this->text);
    }
    return;
}

void ControllerCustomText::setFontFamily(QString s)
{
    if (this->fontFamily != s){
        this->fontFamily = s;
        emit fontFamilyChanged(this->fontFamily);

    }
}

void ControllerCustomText::setFontSize(int s)
{
     if(this->fontSize != s){
         this->fontSize = s;
         emit fontSizeChanged(this->fontSize);

     }
     return;
}

void ControllerCustomText::setCor(QString s)
{
    if(this->cor != s){
        this->cor = s;
        emit corChanged(this->cor);

    }
    return;
}

QString ControllerCustomText::getFontFamily()
{
    return this->fontFamily;
}

QString ControllerCustomText::getText()
{   qDebug() << "retorno customText" << this->text;
    return this->text;

}

QString ControllerCustomText::getCor()
{
    return this->cor;
}

int ControllerCustomText::getFontSize()
{return this->fontSize;

}
