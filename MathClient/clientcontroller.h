#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

#include <QObject>
#include <QString>

class ClientController;

class ClientControllerDestroyer
{
private:
    ClientController* instance;
public:
    ~ClientControllerDestroyer();
    void initialize(ClientController * p) { instance = p; }
};

class ClientController : public QObject
{
    Q_OBJECT
private:
    static ClientController* instance;
    static ClientControllerDestroyer destroyer;

protected:
    ClientController() : QObject(nullptr) {}
    ClientController(const ClientController&);
    ClientController& operator=(ClientController&);
    ~ClientController() {}
    friend class ClientControllerDestroyer;

public:
    static ClientController* getInstance() {
        if (!instance) {
            instance = new ClientController();
            destroyer.initialize(instance);
        }
        return instance;
    }

    QString makeLoginCommand(QString login, QString password);
    QString makeRegisterCommand(QString login, QString password);
    
    // Command to ask server to solve the math task
    // Or we could send the answer computed locally. Let's provide a command to solve it.
    QString makeSolveTaskCommand(int functionId, double a, double b, double eps);

    QString parseServerResponse(QString response);
};

#endif // CLIENTCONTROLLER_H
