#include "changecode.h"
#include "ui_changecode.h"

ChangeCode::ChangeCode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeCode)
{
    ui->setupUi(this);
    ui->error->setVisible(false);
}

ChangeCode::~ChangeCode()
{
    delete ui;
}
void ChangeCode::accept()
{
    //check if the code is new
    if(ui->first->text()==ui->second->text())
        emit changeCode(ui->first->text());

    //update the code
    else
    {
        ui->error->setVisible(true);
        ui->first->setText("");
        ui->second->setText("");
    }
}
