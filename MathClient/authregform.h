#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
#include "mainform.h"

namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();
    void onMainFormClosed();

private:
    Ui::AuthRegForm *ui;
    MainForm *mainForm;
};

#endif // AUTHREGFORM_H
