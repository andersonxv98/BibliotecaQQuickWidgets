#include "controllergame.h"





ControllerGame::ControllerGame(QQmlContext *rootContext)
{
    this->rootContext = rootContext;
    this->setDificulty(2); // 1, 2 OR 3 // EASY, MEDIUM AND HARD
    this->score = new Score(getDificulty());
    this->player_control = new PlayerHideGame();
    this->rootContext->setContextProperty("playerControl", player_control);
    this->rootContext->setContextProperty("scoreControl", score);

    //this->player_control->setMaxHealt(100);
    //this->player_control->setHealt(90);

}

void ControllerGame::shoot(int bulletId)
{
    player_control->setType("double");
    double player_dmg = player_control->getDmg();
    int bulletVelocity = player_control->getBulletVelocity();
    QString shootType= player_control->getType();
    if(player_control->shoot()){
    QString bulletContext = "bullet"+QString::number(bulletId);

        if(shootType == "triple"){
             emit tripleShooting( bulletVelocity, player_dmg, shootType, bulletContext);
        }
        else if(shootType == "double"){

             emit doubleShooting( bulletVelocity, player_dmg, shootType, bulletContext);
        }
        else if(shootType == "flame"){
            qDebug() << "entrou em flame type shooting";
            emit flameShooting(bulletVelocity, player_dmg, shootType, bulletContext);
        }
        else{
             emit singleShooting(bulletVelocity, player_dmg, shootType, bulletContext);
        }

    //velocidade, dano e posição;
    }
    return;
}

void ControllerGame::appendEnemy(QObject *enemy, int idEnemy)
{

    EnemyHideGame * e = new EnemyHideGame(enemy);
    QString context = "enemy"+QString::number(idEnemy);
    this->rootContext->setContextProperty(context,e);
    this->l.append(e);
    qDebug() << "appendedEnemy contex" ;
    return;
}

void ControllerGame::removeEnemy(QObject* enemy)
{
    for(EnemyHideGame * e : this->l){
        if(e->getEnemyObj() == enemy){
            this->l.removeAll(e);
        }
    }
    return;
}

void ControllerGame::appendBullet(QObject *bullet, int idBullet, QString hierarchy)
{
    qDebug()  << "entrou em appendBullet";
    Bullet * b = new Bullet(bullet);
    QString context = "bullet"+hierarchy+QString::number(idBullet);//"bulletSecond" or "bulletTriple"+QString::number(b->getId());
    this->rootContext->setContextProperty(context,b);
    this->l_bullet.append(b);
    qDebug() << "final appendBullet";
    return;
}

void ControllerGame::removeBullet(QObject *bullet)
{
    for(Bullet * b : this->l_bullet){
        if(b->getBulletObj() == bullet){
            this->l_bullet.removeAll(b);
        }
    }
    return;
}

QList<QObject*> ControllerGame::bulletEnemyColision()
{
    qDebug() <<" BulletEnemyCOlision";

    QList<QObject*> lista = {};
       for(EnemyHideGame * e: this->l){
            lista.append(e->getEnemyObj());
        }


       return lista;
}

QList<int> ControllerGame::playerPosition()
{
    int x =this->player_control->getPositionX();
    int y =this->player_control->getPositionY();

    QList<int> l_int = {x, y};
    return l_int;

}

void ControllerGame::playerShootAndEnemyColison(Bullet *b, EnemyHideGame *e)
{
    //b->
}

double ControllerGame::getDificulty() const
{
    return dificulty;
}

void ControllerGame::setDificulty(int newDificulty)
{
    qDebug() << "dentro SET DIFICULTY";

        dificulty = newDificulty;
        emit difChanged(dificulty);
        qDebug () << "EMITIU WITCH";

    return;
}

int ControllerGame::getEnemies_qtd() const
{
    return enemies_qtd;
}

void ControllerGame::setEnemies_qtd(int newEnemies_qtd)
{
    enemies_qtd = newEnemies_qtd;
}
