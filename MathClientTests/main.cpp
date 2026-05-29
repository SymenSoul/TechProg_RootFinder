#include <QtTest>
#include "../MathClient/clientcontroller.h"

class ClientTests : public QObject
{
    Q_OBJECT

private slots:
    void testMakeLoginCommand();
    void testMakeRegisterCommand();
    void testMakeSolveTaskCommand();
    void testParseServerResponse();
};

void ClientTests::testMakeLoginCommand()
{
    QString cmd = ClientController::getInstance()->makeLoginCommand("test_user", "password123");
    QCOMPARE(cmd, QString("auth test_user password123"));
}

void ClientTests::testMakeRegisterCommand()
{
    QString cmd = ClientController::getInstance()->makeRegisterCommand("new_user", "secure_pass");
    QCOMPARE(cmd, QString("reg new_user secure_pass"));
}

void ClientTests::testMakeSolveTaskCommand()
{
    QString cmd = ClientController::getInstance()->makeSolveTaskCommand(1, -2.5, 2.5, 0.0001);
    QCOMPARE(cmd, QString("solve 1 -2.5 2.5 0.0001"));
}

void ClientTests::testParseServerResponse()
{
    QCOMPARE(ClientController::getInstance()->parseServerResponse("success"), QString("SUCCESS"));
    QCOMPARE(ClientController::getInstance()->parseServerResponse("failed"), QString("FAILED"));
    QCOMPARE(ClientController::getInstance()->parseServerResponse("ALREADY_EXISTS"), QString("ALREADY_EXISTS"));
}

QTEST_APPLESS_MAIN(ClientTests)
#include "main.moc"
