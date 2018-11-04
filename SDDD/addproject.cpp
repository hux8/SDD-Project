#include "addproject.h"
#include "ui_addproject.h"

AddProject::AddProject(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddProject)
{
    ui->setupUi(this);
}

AddProject::~AddProject()
{
    delete ui;
}


void AddProject::createProject()
{

}
