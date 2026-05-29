#ifndef MYTCPCLIENT_H
#define MYTCPCLIENT_H

#include <QTcpSocket>
#include <QObject>

class MyTcpClient;

class MyTcpClientDestroyer
{
private:
    MyTcpClient* instance;
public:
    ~MyTcpClientDestroyer();
    void initialize(MyTcpClient * p) { instance = p; }
};

class MyTcpClient : public QObject
{
    Q_OBJECT
private:
    QTcpSocket* msocket;
    static MyTcpClient* instance;
    static MyTcpClientDestroyer destroyer;

protected:
    MyTcpClient() : QObject(nullptr) {
        msocket = new QTcpSocket(this);
        msocket->connectToHost("127.0.0.1", 33333);
        connect(msocket, &QTcpSocket::connected, this, &MyTcpClient::connected);
        connect(msocket, &QTcpSocket::disconnected, this, &MyTcpClient::disconnected);
    }
    MyTcpClient(const MyTcpClient&);
    MyTcpClient& operator=(MyTcpClient&);
    ~MyTcpClient() {}
    friend class MyTcpClientDestroyer;

public:
    static MyTcpClient* getInstance() {
        if (!instance) {
            instance = new MyTcpClient();
            destroyer.initialize(instance);
        }
        return instance;
    }

    void sendMessage(QString msg);
    QString getMsg(); // Synchronous read (from example)

signals:
    void connected();
    void disconnected();
    void messageReceived(QString msg);

private slots:
    void slotReadyRead();
};

#endif // MYTCPCLIENT_H
