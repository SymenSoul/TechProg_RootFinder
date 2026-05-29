#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

signals:
    void logout();

private slots:
    void on_solveButton_clicked();
    void on_logoutButton_clicked();

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
