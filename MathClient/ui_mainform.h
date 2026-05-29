/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_func;
    QComboBox *functionCombo;
    QHBoxLayout *horizontalLayout;
    QLabel *label_a;
    QLineEdit *aEdit;
    QLabel *label_b;
    QLineEdit *bEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_eps;
    QLineEdit *epsEdit;
    QPushButton *solveButton;
    QLabel *label_bisect;
    QLineEdit *bisectResult;
    QLabel *label_newton;
    QLineEdit *newtonResult;
    QSpacerItem *verticalSpacer;
    QPushButton *logoutButton;

    void setupUi(QWidget *MainForm)
    {
        if (MainForm->objectName().isEmpty())
            MainForm->setObjectName("MainForm");
        MainForm->resize(400, 350);
        verticalLayout = new QVBoxLayout(MainForm);
        verticalLayout->setObjectName("verticalLayout");
        label_func = new QLabel(MainForm);
        label_func->setObjectName("label_func");

        verticalLayout->addWidget(label_func);

        functionCombo = new QComboBox(MainForm);
        functionCombo->setObjectName("functionCombo");

        verticalLayout->addWidget(functionCombo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_a = new QLabel(MainForm);
        label_a->setObjectName("label_a");

        horizontalLayout->addWidget(label_a);

        aEdit = new QLineEdit(MainForm);
        aEdit->setObjectName("aEdit");

        horizontalLayout->addWidget(aEdit);

        label_b = new QLabel(MainForm);
        label_b->setObjectName("label_b");

        horizontalLayout->addWidget(label_b);

        bEdit = new QLineEdit(MainForm);
        bEdit->setObjectName("bEdit");

        horizontalLayout->addWidget(bEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_eps = new QLabel(MainForm);
        label_eps->setObjectName("label_eps");

        horizontalLayout_2->addWidget(label_eps);

        epsEdit = new QLineEdit(MainForm);
        epsEdit->setObjectName("epsEdit");

        horizontalLayout_2->addWidget(epsEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        solveButton = new QPushButton(MainForm);
        solveButton->setObjectName("solveButton");

        verticalLayout->addWidget(solveButton);

        label_bisect = new QLabel(MainForm);
        label_bisect->setObjectName("label_bisect");

        verticalLayout->addWidget(label_bisect);

        bisectResult = new QLineEdit(MainForm);
        bisectResult->setObjectName("bisectResult");
        bisectResult->setReadOnly(true);

        verticalLayout->addWidget(bisectResult);

        label_newton = new QLabel(MainForm);
        label_newton->setObjectName("label_newton");

        verticalLayout->addWidget(label_newton);

        newtonResult = new QLineEdit(MainForm);
        newtonResult->setObjectName("newtonResult");
        newtonResult->setReadOnly(true);

        verticalLayout->addWidget(newtonResult);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        logoutButton = new QPushButton(MainForm);
        logoutButton->setObjectName("logoutButton");

        verticalLayout->addWidget(logoutButton);


        retranslateUi(MainForm);

        QMetaObject::connectSlotsByName(MainForm);
    } // setupUi

    void retranslateUi(QWidget *MainForm)
    {
        MainForm->setWindowTitle(QCoreApplication::translate("MainForm", "Root Finder", nullptr));
        label_func->setText(QCoreApplication::translate("MainForm", "Function:", nullptr));
        label_a->setText(QCoreApplication::translate("MainForm", "a:", nullptr));
        aEdit->setText(QCoreApplication::translate("MainForm", "0.0", nullptr));
        label_b->setText(QCoreApplication::translate("MainForm", "b:", nullptr));
        bEdit->setText(QCoreApplication::translate("MainForm", "5.0", nullptr));
        label_eps->setText(QCoreApplication::translate("MainForm", "Epsilon (accuracy):", nullptr));
        epsEdit->setText(QCoreApplication::translate("MainForm", "0.001", nullptr));
        solveButton->setText(QCoreApplication::translate("MainForm", "Solve", nullptr));
        label_bisect->setText(QCoreApplication::translate("MainForm", "Bisection Result:", nullptr));
        label_newton->setText(QCoreApplication::translate("MainForm", "Newton's Result:", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainForm", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainForm: public Ui_MainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
