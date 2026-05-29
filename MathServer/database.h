#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class Database;

class DatabaseDestroyer
{
private:
    Database* instance;
public:
    ~DatabaseDestroyer();
    void initialize(Database* p) { instance = p; }
};

class Database : public QObject
{
    Q_OBJECT
private:
    static Database* instance;
    static DatabaseDestroyer destroyer;
    QSqlDatabase db;

protected:
    Database() : QObject(nullptr) {}
    Database(const Database&);
    Database& operator=(Database&);
    ~Database();
    friend class DatabaseDestroyer;

public:
    static Database* getInstance() {
        if (!instance) {
            instance = new Database();
            destroyer.initialize(instance);
        }
        return instance;
    }

    void openDatabase(const QString& path);
    void createTables();
    
    bool registerUser(const QString& login, const QString& password);
    bool authoUser(const QString& login, const QString& password);
    void saveTaskResult(const QString& login, int functionId, double a, double b, double eps, double bisectionResult, double newtonResult);
};

#endif // DATABASE_H
