#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<iostream>
#include<QLabel>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include<QSqlQuery>
#include<QMessageBox>
#include"systemdeveloper.h"

#define LOGx(x) std::cout<< x << std::endl
#define LOGxy(x,y) std::cout<< x << y << std::endl
#define Debug(x) qDebug()<<(x)
QT_BEGIN_NAMESPACE
namespace Ui { class logIn; }
QT_END_NAMESPACE

class logIn : public QMainWindow
{
    Q_OBJECT
public:
    void connClose(){
        myDatabase.close();
        myDatabase.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        myDatabase=QSqlDatabase::addDatabase("QSQLITE");
        myDatabase.setDatabaseName("/home/viadtech/pointOfSale/databases/pos");
        if(!myDatabase.open()){
            Debug("[ERROR]: Failed to connect to the database ...");
            return false;
        }else{
            Debug("[SUCCESS]: Connection to the database successful!");
            return true;
        }
    }
    QSqlDatabase myDatabase;

public:
    logIn(QWidget *parent = nullptr);
    ~logIn();

private slots:
    void on_pushButtonLogin_clicked();
    void on_pushButtonCancel_clicked();
    void onLogOutClickedFrmSystemDeveloper();

private:
    Ui::logIn *ui;   
private:
    systemDeveloper *_systemDev;
};
#endif // LOGIN_H
