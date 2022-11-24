#ifndef CONTROLLERCUSTOMTEXT_H
#define CONTROLLERCUSTOMTEXT_H

#include "controlleritem.h"



class ControllerCustomText :public ControllerItem
{Q_OBJECT
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString fontFamily READ getFontFamily WRITE setFontFamily NOTIFY fontFamilyChanged)
    Q_PROPERTY(int fontSize READ getFontSize WRITE setFontSize NOTIFY fontSizeChanged)
    Q_PROPERTY(QString cor READ getCor WRITE setCor NOTIFY corChanged)
public:
    ControllerCustomText(ControllerItem * parent = nullptr);

    void setText(QString s);
    void setFontFamily(QString s);
    void setFontSize(int  s);
    void setCor(QString s);


    Q_INVOKABLE QString getFontFamily();
    Q_INVOKABLE QString getText();
    Q_INVOKABLE QString getCor();
    Q_INVOKABLE int getFontSize();

signals:
    void textChanged(QString s);
    void fontFamilyChanged(QString s);
    void corChanged(QString s);
    void fontSizeChanged(int s);

private:
    QString text;
    QString fontFamily;
    int fontSize;
    QString cor;


};

#endif // CONTROLLERCUSTOMTEXT_H
