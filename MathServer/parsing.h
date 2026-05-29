#ifndef PARSING_H
#define PARSING_H

#include <QObject>
#include "database.h"
#include "mathsolver.h"

class CommandParsing : public QObject
{
    Q_OBJECT
private:
    Database* my_database;
    QString currentLogin; // To keep track of who is solving (simplified for this assignment)
    
public:
    explicit CommandParsing(QObject *parent = nullptr);
    QString Command(const QString &command);
};

#endif // PARSING_H
