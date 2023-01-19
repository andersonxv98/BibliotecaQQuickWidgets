#ifndef CARTA_H
#define CARTA_H

#include <QObject>
#include <QString>



class Carta : public QObject
{
public:
    Carta(    QString nome,
    QString cor,
    QString url_img);

    QString getNome();
    QString getCor();
    QString getImg();

private:
    QString nome;
    QString cor;
    QString url_img;
};

#endif // CARTA_H
