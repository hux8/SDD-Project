#include "addproject.h"
#include "ui_addproject.h"

AddProject::AddProject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddProject)
{
    ui->setupUi(this);
    ui->error->setVisible(false);
    ui->errord->setVisible(false);
}

AddProject::~AddProject()
{
    delete ui;
}

void AddProject::createProject()
{
    ui->error->setVisible(false);
    ui->errord->setVisible(false);

    //check all required fields
    QString d=ui->date->text();
    if(ui->title->text()==""||ui->description->toPlainText()==""||d==""||ui->features->toPlainText()=="")
        ui->error->setVisible(true);

    //check date format
    else if(d.length()!=10||d.at(4)!='/'||d.at(7)!='/'||!d.at(0).isDigit()||!d.at(1).isDigit()||!d.at(2).isDigit()
            ||!d.at(3).isDigit()||!d.at(5).isDigit()||!d.at(6).isDigit()||!d.at(8).isDigit()||!d.at(9).isDigit())
    {

        ui->errord->setVisible(true);
    }

    //emit all attribute of the new Project
    else
    {
        ui->errord->setVisible(false);
        ui->error->setVisible(false);
        emit newProject((d.left(4)+d.mid(5,2)+d.right(2)).toInt(), ui->title->text(), ui->description->toPlainText()
                        , ui->contact->text(), ui->url->text(),ui->comment->toPlainText(),ui->features->toPlainText());
        ui->title->setText("");
        ui->description->setText("");
        ui->date->setText("");
        ui->contact->setText("");
        ui->comment->setText("");
        ui->features->setText("");
        ui->url->setText("");
    }
}
