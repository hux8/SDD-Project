#include "addpitch.h"
#include "ui_addpitch.h"

AddPitch::AddPitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPitch)
{
    ui->setupUi(this);
}

AddPitch::~AddPitch()
{
    delete ui;
}

void AddPitch::createPitch()
{

}
