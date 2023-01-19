#ifndef CONECCTIONSQL_H
#define CONECCTIONSQL_H


#include <QSqlDataBase>
#include <QtSql>


class ConnectionSQL: public QObject
{Q_OBJECT
public:
    ConnectionSQL();

   void closeConnection();

    QList<QStringList> select(QString query);
    void insert(QString query, QStringList values);
    void update(QString query, QStringList fields,QStringList values);
private:
    bool status;
    QSqlDatabase  db;
};

#endif // CONECCTIONSQL_H
