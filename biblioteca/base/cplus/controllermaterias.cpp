#include "controllermaterias.h"

ControllerMaterias::ControllerMaterias(QPointer<ConnectionSQL> conn, ControllerExercicio *c_enun, MarcaraRandomizada *m)
{
    this->mask = m;
    this->conection = conn;
    this->c_enun = c_enun;
   this->ctrl_aluno =  new ControllerLogin(this->conection);
}

QList<QPointer<Materia> > ControllerMaterias::getMaterias()
{
    return this->materias;
}

QStringList ControllerMaterias::getMateriasToFront()
{
   // qDebug() << "ENTROU EM GET MATERIAS TO FRONT";
    QStringList lista = {};
   /* for(const QPointer<Materia> &materia :  this->materias){
        lista.append(materia->getNome());
    }*/
    return lista;
}

void ControllerMaterias::showExercicios(QString materia_titulo)
{
    for(const QPointer<Materia> &materia :  this->materias){
        if(materia->getNome() == materia_titulo){
            this->current_exer = materia->getExercicios();
            for(QPointer<Exercicio> ex:  materia->getExercicios()){
                emit materiaExercicios(ex->getId());
            }
            break;
        }
    }
    return;
}

void ControllerMaterias::showExercicioResolucao(QString idExercicio)
{
    //mask = ;
    for(QPointer<Exercicio> ex: this->current_exer){
        if(ex->getId() == idExercicio){

            QString texto = ex->getEnunciado(); //"teste 3, eqweqwqwqw 5";//result[0][1];
            QStringList text_enun = texto.split(" ");
            QList<QStringList> lista_enviada;
            for(QString palavra: text_enun){
                QString tipo = "false";
                if(palavra.contains(",")){
                    palavra = palavra.split(",")[0];
                }
                if(palavra.toDouble()){
                    //qDebug() << "CONVERTE: " << palavra;
                    double resultRandom = mask->appendVarOriginal(palavra.toDouble());
                    palavra = QString::number(resultRandom);
                    tipo = palavra;
                }
                lista_enviada.append({palavra+" ", tipo});
            }
            //c_enun.addOnArrastable(){})
            qDebug() << "come has you are: " << lista_enviada;
            c_enun->setEnunciadoOnFront(lista_enviada);
            c_enun->setResultadoCorreto(ex->getResultado());
             this->idEx = idExercicio;
            break;

        }
    }
    return;
}

QPointer<ControllerLogin> ControllerMaterias::getCtrl_aluno()
{
    return this->ctrl_aluno;
}

void ControllerMaterias::doRequest()
{   qDebug() << "Entrou em do Resquest";
    QString Idserie =this->ctrl_aluno->getAluno()->getIdSerie();
    QString query= "SELECT * FROM materia;";
   QList<QStringList> n_list = this->conection->select(query);
   for(QStringList l : n_list){
       qDebug() << "valores: " << l[0] << " " << l[1];
       QPointer<Materia> m = new Materia(l[0].toInt(),l[1], this->conection, Idserie);
       this->addMaterias(m);
   }
   return;
}

void ControllerMaterias::registLog(QString mov)
{   qDebug() << "dentro do registerlog: Valor idEx: " << this->idEx;
    QString query = "insert into log (registro, fk_aluno, fk_exercicio)"
            "VALUES (?, ?, ?)";

    QStringList vet_values = {mov, this->ctrl_aluno->getAluno()->getRa(), this->idEx};

    this->conection->insert(query, vet_values);
}

void ControllerMaterias::registResult(QString result)
{     QString Ra= this->ctrl_aluno->getAluno()->getRa();

      //qDebug() << "Entrou em registResult, resultado: ", result;
    QString verifQuery= "SELECT * FROM aluno_exercicio"
            " where fk_aluno ="+Ra+" and fk_exercicio ="+this->idEx ;
       QList<QStringList> l = this->conection->select(verifQuery);
        if(!(l.length() > 0)){
            QString query = "insert into aluno_exercicio (fk_aluno, fk_exercicio, resultado, status)"
                    "VALUES (?, ?, ?, ?)";
            QStringList vet_values = {Ra, this->idEx, result, "1"};
                   //" VALUES("+mov+","+this->ctrl_aluno->getAluno()->getRa()+","+this->idEx+")";
            this->conection->insert(query, vet_values);
        }
         else{
            qDebug() << "Entrou else do regist Result: ";
            QString query = "UPDATE aluno_exercicio"
                    " SET resultado =:result WHERE fk_aluno = :fk_aluno and fk_exercicio =:fk_exercicio" ;

            QStringList fields = {":id",":fk_aluno", ":fk_exercicio", ":result"};
            QStringList vet_values = {"", Ra, this->idEx, result};
                   //" VALUES("+mov+","+this->ctrl_aluno->getAluno()->getRa()+","+this->idEx+")";
            this->conection->update(query, fields,vet_values);


          QString query_status = "UPDATE aluno_exercicio"
            " SET status =:status WHERE fk_aluno = :fk_aluno and fk_exercicio =:fk_exercicio";

              QStringList fields_status = {":id",":fk_aluno", ":fk_exercicio", ":status"};
              QStringList vet_values_status = {"", Ra, this->idEx, "1"};
                     //" VALUES("+mov+","+this->ctrl_aluno->getAluno()->getRa()+","+this->idEx+")";
              this->conection->update(query_status, fields_status,vet_values_status);
          }

          /*for(QPointer<Exercicio> ex: this->current_exer){
              if(ex->getId() == this->idEx){
                this->current_exer.removeAll(ex);
                  emit exercicioResolved(this->idEx);
                  this->idEx = NULL;
                  break;
              }

          }*/

}

void ControllerMaterias::addMaterias(QPointer<Materia> m)
{
    if(!this->materias.contains(m)){
        this->materias.append(m);
        emit materiaAppended(m->getNome(), m->getExercicios().count());
    }
    return;
}

MarcaraRandomizada *ControllerMaterias::getMask() const
{
    return mask;
}
