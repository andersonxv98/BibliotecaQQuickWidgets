#include "conecctionsql.h"
#include "qdebug.h"

ConnectionSQL::ConnectionSQL()
{
    this->db =  QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("admin");
    db.setDatabaseName("dragndrop");
    if(db.open()){
         qDebug() << "CONEXAO ACEITA";
     }
     else{
         qDebug() << "CONEXAO recusada";
         qDebug() << db.lastError();
     }

}

void ConnectionSQL::closeConnection()
{
    if(db.isOpen()){
        db.close();
    }
}

QList<QStringList> ConnectionSQL::select(QString query)
{   qDebug() << "QUERY: " << query;
    QList<QStringList> retorno = {};
    if(db.open()){
       QSqlQuery  qr =  QSqlQuery(db);
      qr.prepare(query);
       qr.exec(query);
       while (qr.next()) {
           ///qDebug() << "Entrou no while: ";
           QStringList line = {};
           //qDebug() << "enunciado: "<< qr.value("enunciado");
           for(int i =0 ; i < qr.record().count(); i++){
                QString value = qr.value(i).toString();
               qDebug() << "entrou no for> " << value;
               line.append(value);
       }
           //QString result = qr.value(1).toString();
            // qDebug() << "Rtorno: " << result;
           retorno.append(line);
         }
       closeConnection();
    }
    closeConnection();
    return retorno;
}

void ConnectionSQL::insert(QString query, QStringList values)
{
    // query.prepare("INSERT INTO person (id, forename, surname)  VALUES (:id, :forename, :surname)");
    // query.prepare("INSERT INTO person (id, forename, surname) VALUES (?, ?, ?)");
    QSqlQuery qr;
    if(db.open()){
       qr.prepare(query);
       int i = 0;
       for(QString value: values){
            qr.bindValue(i, value);
            i++;
       }
       qr.exec();
    }
    qDebug() << "error : " << qr.lastError();
    qDebug() << "return tesd : ♪♦" << qr.result();
    db.close();
    return;
}

void ConnectionSQL::update(QString query, QStringList fields, QStringList values)
{

    QSqlQuery qr;
    if(db.open()){
       qr.prepare(query);
       int i = 0;
       for(QString value: values){
            qr.bindValue(fields[i], value);
            i++;
       }
       qr.exec();
    }
    qDebug() << "error : " << qr.lastError();
    qDebug() << "return tesd : ♪♦" << qr.result();
    db.close();
    return;
}
