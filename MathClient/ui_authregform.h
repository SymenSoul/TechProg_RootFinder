/********************************************************************************
** Form generated from reading UI file 'authregform.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHREGFORM_H
#define UI_AUTHREGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthRegForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *loginEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *registerButton;

    void setupUi(QWidget *AuthRegForm)
    {
        if (AuthRegForm->objectName().isEmpty())
            AuthRegForm->setObjectName("AuthRegForm");
        AuthRegForm->resize(300, 200);
        verticalLayout = new QVBoxLayout(AuthRegForm);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AuthRegForm);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        loginEdit = new QLineEdit(AuthRegForm);
        loginEdit->setObjectName("loginEdit");

        verticalLayout->addWidget(loginEdit);

        label_2 = new QLabel(AuthRegForm);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        passwordEdit = new QLineEdit(AuthRegForm);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordEdit);

        loginButton = new QPushButton(AuthRegForm);
        loginButton->setObjectName("loginButton");

        verticalLayout->addWidget(loginButton);

        registerButton = new QPushButton(AuthRegForm);
        registerButton->setObjectName("registerButton");

        verticalLayout->addWidget(registerButton);


        retranslateUi(AuthRegForm);

        QMetaObject::connectSlotsByName(AuthRegForm);
    } // setupUi

    void retranslateUi(QWidget *AuthRegForm)
    {
        AuthRegForm->setWindowTitle(QCoreApplication::translate("AuthRegForm", "Authorization", nullptr));
        label->setText(QCoreApplication::translate("AuthRegForm", "Login:", nullptr));
        label_2->setText(QCoreApplication::translate("AuthRegForm", "Password:", nullptr));
        loginButton->setText(QCoreApplication::translate("AuthRegForm", "Login", nullptr));
        registerButton->setText(QCoreApplication::translate("AuthRegForm", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthRegForm: public Ui_AuthRegForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHREGFORM_H
