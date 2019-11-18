#ifndef SYSTEMDEVELOPER_H
#define SYSTEMDEVELOPER_H

#include <QMainWindow>
#include<QMessageBox>

namespace Ui {
class systemDeveloper;
}

class systemDeveloper : public QMainWindow
{
    Q_OBJECT

public:
    explicit systemDeveloper(QWidget *parent = nullptr);
    ~systemDeveloper();
public:


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_17_clicked();

    void on_pushButtonRegisterEmployee_clicked();

private:
    Ui::systemDeveloper *ui;
signals:
    void logoutClicked();
};

#endif // SYSTEMDEVELOPER_H
