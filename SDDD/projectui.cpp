#include "projectui.h"
#include "ui_projectui.h"

ProjectUI::ProjectUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectUI)
{
    ui->setupUi(this);
    setFeatures();
    ui->description->setReadOnly(true);
    ui->comment->setReadOnly(true);
    ui->url->setReadOnly(true);
    ui->contact->setReadOnly(true);
}

ProjectUI::~ProjectUI()
{
    delete ui;
}

void ProjectUI::setAccess(bool b)
{
    ui->bdelete->setVisible(b);
    ui->bmodifyComment->setVisible(b);
    ui->bmodifyContact->setVisible(b);
    ui->bmodifyDescription->setVisible(b);
    ui->bmodifyFeatures->setVisible(b);
    ui->bmodifyUrl->setVisible(b);
}

void ProjectUI::setFeatures()
{
    QVBoxLayout* v=new QVBoxLayout();
    QLabel* l=new QLabel("hi");
    v->addWidget(l);
    ui->features->setLayout(v);
}

void ProjectUI::toConfirm()
{
    ConfirmDialog* c=new ConfirmDialog();
    c->show();
}

void ProjectUI::modifyComment()
{
    if(ui->comment->isReadOnly())
    {
        ui->comment->setReadOnly(false);
        ui->bmodifyComment->setText("Confirm");
    }
    else
    {
        ui->comment->setReadOnly(true);
        ui->bmodifyComment->setText("Modify");
    }
}

void ProjectUI::modifyDescription()
{
    if(ui->description->isReadOnly())
    {
        ui->description->setReadOnly(false);
        ui->bmodifyDescription->setText("Confirm");
    }
    else
    {
        ui->description->setReadOnly(true);
        ui->bmodifyDescription->setText("Modify");
    }
}

void ProjectUI::modifyUrl()
{
    if(ui->url->isReadOnly())
    {
        ui->url->setReadOnly(false);
        ui->bmodifyUrl->setText("Confirm");
    }
    else
    {
        ui->url->setReadOnly(true);
        ui->bmodifyUrl->setText("Modify");
    }
}

void ProjectUI::modifyContact()
{
    if(ui->contact->isReadOnly())
    {
        ui->contact->setReadOnly(false);
        ui->bmodifyContact->setText("Confirm");
    }
    else
    {
        ui->contact->setReadOnly(true);
        ui->bmodifyContact->setText("Modify");
    }
}

void ProjectUI::modifyFeatures()
{

}

