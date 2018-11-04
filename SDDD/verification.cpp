#include "verification.h"
#include "ui_verification.h"

Verification::Verification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Verification)
{
    checked=false;
    ui->setupUi(this);
    ui->lerror->setVisible(false);
    code="instructor";
}

Verification::~Verification()
{
    delete ui;
}



void Verification::checkCode()
{
    checked=(ui->lineEdit->text()==code);
    if(checked)
    {
        emit isChecked();
    }

    if(!checked)
    {
        ui->lerror->setVisible(true);
        ui->lineEdit->setText("");
    }
}

void Verification::showMain()
{
    emit asStudent();
}
