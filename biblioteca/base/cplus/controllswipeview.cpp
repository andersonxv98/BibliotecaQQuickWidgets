#include "controllswipeview.h"

ControllSwipeView::ControllSwipeView()
{
     this->indice = 0;
}

ControllSwipeView::~ControllSwipeView()
{

}

void ControllSwipeView::appendItem(QPointer<Carta> l)
{
    if(!this->l.contains(l))
    {
        this->l.push_back(l);
    }
    return;
}

void ControllSwipeView::rmv_item(QStringList l)
{
   /* if(this->l.contains(l)){
        this->l.removeAll(l);
        emit rmvItem(l[0]);
    }*/
    return;
}

bool ControllSwipeView::getHorizontal()
{
    return this->horizontal;
}

bool ControllSwipeView::getVertical()
{
    return this->vertical;
}

QString ControllSwipeView::getOrientation()
{return this->orientation;

}

bool ControllSwipeView::getInteractive()
{
    return this->interactive;
}

void ControllSwipeView::setNext()
{

 emit nextChanged(this->getNext());
    return;
}



QStringList ControllSwipeView::getNext()
{
    if(this->indice < (this->l.count()-1)){
        this->indice++;
    }
    else{
        this->indice = 0;
    }
    qDebug() << "indice atual: "<< this->indice;
    QPointer<Carta> card1 = l[this->indice];
    QStringList list = {card1->getNome(), card1->getCor(), card1->getImg()};
     qDebug() << "lista: "<< list;


     return list;
}

QStringList ControllSwipeView::getPrev()
{   int prev = this->indice - 2;
    /*if(this->indice > 0){
        this->indice--;
    }
    else{
        this->indice = this->l.count()-1;
    }*/
    if(prev < 0){
        prev= this->l.count()-1;
        this->indice = prev;
    }
    else{
        this->indice = prev;
    }
    QPointer<Carta> card1 = l[this->indice];
    QStringList list = {card1->getNome(), card1->getCor(), card1->getImg()};
     qDebug() << "lista: "<< list;


     return list;

}


void ControllSwipeView::setHorizontal(bool h)
{
    if(this->horizontal != h){
        this->horizontal = h;
        emit horizontalChanged(this->horizontal);
    }
    return;
}

void ControllSwipeView::setInteractive(bool i)
{
    if(this->interactive != i){
        this->interactive = i;
        emit interactiveChanged(this->interactive);
    }
    return;
}

void ControllSwipeView::setOrientation(QString ori)
{
    if(this->orientation != ori){
        this->orientation = ori;
        emit orientationChanged(this->orientation);
    }
    return;
}

void ControllSwipeView::setVertical(bool v)
{
    if(this->vertical != v){
        this->vertical = v;
        emit verticalChanged(this->vertical);
    }
    return;
}





