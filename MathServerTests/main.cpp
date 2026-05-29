#include <QtTest>
#include "../MathServer/mathsolver.h"
#include <cmath>

class ServerTests : public QObject
{
    Q_OBJECT

private slots:
    void testGetFunctionName();
    void testBisectionSuccess();
    void testBisectionFailure();
    void testNewtonSuccess();
    void testNewtonFailure();
};

void ServerTests::testGetFunctionName()
{
    QCOMPARE(MathSolver::getFunctionName(0), QString("f(x) = x^2 - 4"));
    QCOMPARE(MathSolver::getFunctionName(1), QString("f(x) = sin(x) - x/2"));
}

void ServerTests::testBisectionSuccess()
{
    auto f = MathSolver::getFunction(0); // f(x) = x^2 - 4
    bool success = false;
    double root = MathSolver::solveBisection(f, 0.0, 5.0, 0.001, success);
    
    QVERIFY(success);
    QVERIFY(std::abs(root - 2.0) <= 0.001);
}

void ServerTests::testBisectionFailure()
{
    auto f = MathSolver::getFunction(0); // f(x) = x^2 - 4
    bool success = true;
    // Interval [3, 5] does not contain a root (both f(3)=5 and f(5)=21 are positive)
    MathSolver::solveBisection(f, 3.0, 5.0, 0.001, success);
    
    QVERIFY(!success);
}

void ServerTests::testNewtonSuccess()
{
    auto f = MathSolver::getFunction(0); // f(x) = x^2 - 4
    auto df = MathSolver::getDerivative(0); // f'(x) = 2x
    bool success = false;
    double root = MathSolver::solveNewton(f, df, 2.5, 0.001, success);
    
    QVERIFY(success);
    QVERIFY(std::abs(root - 2.0) <= 0.001);
}

void ServerTests::testNewtonFailure()
{
    auto f = MathSolver::getFunction(0); // f(x) = x^2 - 4
    auto df = MathSolver::getDerivative(0); // f'(x) = 2x
    bool success = true;
    // Initial guess 0.0 leads to derivative = 0 (division by zero)
    MathSolver::solveNewton(f, df, 0.0, 0.001, success);
    
    QVERIFY(!success);
}

QTEST_APPLESS_MAIN(ServerTests)
#include "main.moc"
