#include "systemdeveloper.h"
#include "ui_systemdeveloper.h"
#include"login.h"
systemDeveloper::systemDeveloper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::systemDeveloper)
{
    ui->setupUi(this);
    this->setWindowTitle("SYSTEM DEVELOPER CONTROL");
    this->setMinimumSize(1280,768);

    ui->stackedWidget->setCurrentIndex(0);

}

systemDeveloper::~systemDeveloper()
{
    delete ui;
}

void systemDeveloper::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void systemDeveloper::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void systemDeveloper::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void systemDeveloper::on_pushButton_17_clicked()
{
    emit logoutClicked();
}

void systemDeveloper::on_pushButtonRegisterEmployee_clicked()
{
     logIn _login;

     QString userID;
     QString surname;
     QString nationalID;
     QString otherNames;
     QString phoneNumber;
     QString gender;
     QString salary;
     QString passportImage;
     QString idImage;
     QString nextOfKin;
     QString nextOfKinPhone;
     QString userType;
     QString userName;
     QString userPassword;
     QString userPassword2;
     userID = ui->lineEditEmployeeIdentificationNumber->text();
     nationalID = ui->lineEditNationalIdentification->text();
     surname = ui->lineEditSurname->text();
     otherNames = ui->lineEditOtherNames->text();
     phoneNumber = ui->lineEditPhoneNumber->text();
     gender = ui->comboBoxGender->currentText();
     salary = ui->lineEditSalary->text();
     passportImage = ui->lineEditPassportPhotoImage->text();
     idImage = ui->lineEditSalary->text();
     nextOfKin = ui->lineEditNextofKinNames->text();
     nextOfKinPhone = ui->lineEditNextofKinPhone->text();
     userType = ui->comboBoxEmployeeType->currentText();
     userName = ui->lineEditUsername->text();
     userPassword = ui->lineEditPassword->text();
     userPassword2 = ui->lineEditPasswordConfirm->text();

     if(!_login.connOpen()){
         LOGx("[ERROR SYSDEV]: Database failed to connect");
         return;
     }
     _login.connOpen();
     QSqlQuery qry;
     qry.prepare("insert into users (userID, nationalID, surname, otherNames, phoneNumber, gender, salary, passportImage, idImage, nextOfKin, nextOfKinPhone, userType, userName, userPassword) values('"+userID+"', '"+nationalID+"','"+surname+"','"+otherNames+"','"+phoneNumber+"','"+gender+"','"+salary+"','"+passportImage+"', '"+idImage+"','"+nextOfKin+"','"+nextOfKinPhone+"','"+userType+"','"+userName+"','"+userPassword+"')");
     if(qry.exec()){
        QMessageBox::critical(this, tr("Database Success"), tr("Database Updated!"));
        _login.connClose();
     }else{
          QMessageBox::critical(this, tr("Database Error"), qry.lastError().text());
         LOGx("SYSDEV QUERY NOT COMPLETED");
     }
}
