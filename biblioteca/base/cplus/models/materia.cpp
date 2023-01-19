#include "materia.h"

Materia::Materia(int id, QString nome,  QPointer<ConnectionSQL> con, QString serieId)
{
    this->setId(id);
    this->setNome(nome);
    this->setSerieId(serieId);
    this->conection = con;
    this->doRequest();

}

QString Materia::getNome() const
{
    return nome;
}

void Materia::setNome(const QString &newNome)
{
    nome = newNome;
}

void Materia::setId(int id)
{
    this->id = id;
}

void Materia::doRequest()
{
    QString query = "SELECT exercicios.idexercicios,  professor.nome, exercicios.enunciado, exercicios.resultado, serie.nome FROM exercicios"
            " inner join professor ON exercicios.fk_professor = professor.idprofessor"
            " inner join serie ON exercicios.fk_serie= serie.idserie"
            " where fk_materia ="+ QString::number(this->id)+ " and" //// filtro de exercicio por materia
            " fk_serie ="+ this->serieId+ ""  //filtro de exercicio por serie
            " and idexercicios Not in(SELECT fk_exercicio FROM dragndrop.aluno_exercicio)"; //verificar se o exercicio ta ativo
    //qDebug() << "QUERY MATERIAIS: " << query;
    QList<QStringList> r = this->conection->select(query);
    for(QStringList row : r){
        //qDebug() << "result: " << row[0] << "  " << row[1] << "  " << row[2] << "  " << row[3];
        QPointer<Exercicio> e = new Exercicio(row[0], row[1],row[2],row[3]);
        this->addExercicio(e);
    }
    return;
}

QString Materia::getSerieId() const
{
    return serieId;
}

void Materia::setSerieId(const QString &newSerieId)
{
    serieId = newSerieId;
}

QList<QPointer<Exercicio> > Materia::getExercicios() const
{
    return exercicios;
}

void Materia::addExercicio(QPointer<Exercicio> ex)
{   qDebug() << "entrou em add exercidios : < > " ;
    this->exercicios.append(ex);
}
