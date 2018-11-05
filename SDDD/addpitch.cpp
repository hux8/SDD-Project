#include "addpitch.h"
#include "ui_addpitch.h"

AddPitch::AddPitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPitch)
{
    ui->setupUi(this);
    ui->error->setVisible(false);
    ui->errord->setVisible(false);
}

AddPitch::~AddPitch()
{
    delete ui;
}


void AddPitch::createPitch()
{
    ui->error->setVisible(false);
    ui->errord->setVisible(false);

    QString d=ui->date->text();
    if(ui->title->text()==""||ui->description->toPlainText()==""||d=="")
        ui->error->setVisible(true);
    else if(d.length()!=10||d.at(4)!='/'||d.at(7)!='/'||!d.at(0).isDigit()||!d.at(1).isDigit()||!d.at(2).isDigit()
            ||!d.at(3).isDigit()||!d.at(5).isDigit()||!d.at(6).isDigit()||!d.at(8).isDigit()||!d.at(9).isDigit())
    {

        ui->errord->setVisible(true);
    }
    else
    {
        ui->errord->setVisible(false);
        ui->error->setVisible(false);
        emit newPitch((d.left(4)+d.mid(5,2)+d.right(2)).toInt(), ui->title->text(), ui->description->toPlainText());
        ui->title->setText("");
        ui->description->setText("");
        ui->date->setText("");
    }
}
