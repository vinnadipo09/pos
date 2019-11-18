#include "login.h"
#include "ui_login.h"

logIn::logIn(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::logIn)
{
    ui->setupUi(this);
    this->setMinimumSize(1280, 768);
    this->setWindowTitle("CENTRAL SYSTEM LOGIN");

    if(connOpen()==false){
        LOGx("[ERROR]: Database failed to connect");
    }else{
        LOGx("[SUCCESS]: Database successfully connected");
    }

    _systemDev = new systemDeveloper;
     ui->stackedWidget->insertWidget(1, _systemDev);
 connect(_systemDev, SIGNAL(logoutClicked()), this, SLOT(onLogOutClickedFrmSystemDeveloper()));
}

logIn::~logIn()
{
    delete ui;
}


void logIn::on_pushButtonLogin_clicked()
{
    QString username;
    QString password;
    username = ui->lineEditUsername->text();
    password = ui->lineEditPassword->text();

    if(!connOpen()){
        LOGx("[ERROR]: Database failed to connect");
        return;
    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM users WHERE userName='"+username+"' and userPassword='"+password+"'");
    if(qry.exec()){

        std::string usertype;
        int count = 0;
        while(qry.next()){
            count ++;
        }
        if (count == 1){
            LOGx("[SUCCESS]: Successfully logged in");
            ui->stackedWidget->setCurrentIndex(1);
            connClose();
        }
        if (count > 1){
            LOGx("[WARNING]: Duplicate Entries");
        }
        if (count < 1){
            LOGx("[ERROR]: Wrong logged in credentials");
            ui->lineEditUsername->clear();
            ui->lineEditPassword->clear();
            QMessageBox::critical(this, tr("Login Error"), tr("Wrong Login Credentials!"));
        }
    }else{
        LOGx("QUERY NOT COMPLETED");

    }
}

void logIn::on_pushButtonCancel_clicked()
{
    ui->lineEditUsername->clear();
    ui->lineEditPassword->clear();
}

void logIn::onLogOutClickedFrmSystemDeveloper()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEditUsername->clear();
    ui->lineEditPassword->clear();
//    ui->stackedWidget->setCurrentIndex(0);
//    _systemDev->hide();
//    this->setWindowModality(Qt::ApplicationModal);
//    this->show();

}
