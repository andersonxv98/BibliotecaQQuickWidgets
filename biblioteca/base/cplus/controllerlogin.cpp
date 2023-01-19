#include "controllerlogin.h"

ControllerLogin::ControllerLogin(QPointer<ConnectionSQL> con)
{
    this->con = con;
}

bool ControllerLogin::login(QString ra, QString pass)
{
    bool r = false;
    QString query = "SELECT aluno.idaluno, aluno.nome, serie.idserie,serie.nome"
            " FROM aluno"
            " INNER JOIN serie ON aluno.fk_serie= serie.idserie"
            " where idaluno ="+ra+  " and aluno.pass = "+ pass;
   QList<QStringList> l = this->con->select(query);
   for(QStringList ql : l){
           this-> aluno = new Aluno(ql[0], ql[1], ql[2], ql[3]);
           r = true;
           qDebug() << "Logou e mamou";
   }
   return r;
}

QPointer<Aluno> ControllerLogin::getAluno() const
{
    return aluno;
}
