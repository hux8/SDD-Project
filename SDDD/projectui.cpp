#include "projectui.h"
#include "ui_projectui.h"

ProjectUI::ProjectUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectUI)
{
    ui->setupUi(this);
    ui->description->setReadOnly(true);
    ui->comment->setReadOnly(true);
    ui->url->setReadOnly(true);
    ui->contact->setReadOnly(true);
    ui->features->setReadOnly(true);
}

ProjectUI::~ProjectUI()
{
    delete ui;
}

void ProjectUI::setId(int i)
{
    id=i;
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

void ProjectUI::setUp(int i, int date, QString t, QString con, QString url, QString f
                      , QString com, QString d, bool is)
{
    if(url==""&&!is)
    {
        ui->lurl->setVisible(false);
        ui->bmodifyUrl->setVisible(false);
        ui->url->setVisible(false);
    }
    if(com==""&&!is)
    {
        ui->lcomment->setVisible(false);
        ui->bmodifyComment->setVisible(false);
        ui->comment->setVisible(false);
    }
    if(con==""&&!is)
    {
        ui->lcontact->setVisible(false);
        ui->bmodifyContact->setVisible(false);
        ui->contact->setVisible(false);
    }
    id=i;
    ui->description->setText(d);
    ui->title->setText(t);
    setWindowTitle(t);
    QString da=QString::number(date);
    ui->date->setText(da.left(4)+"/"+da.mid(4,2)+"/"+da.right(2));
    ui->contact->setText(con);
    ui->url->setText(url);
    ui->features->setText(f);
    ui->comment->setText(com);
}

void ProjectUI::toConfirm()
{
    ConfirmDialog* c=new ConfirmDialog();
    connect(c,SIGNAL(confirmed()),this,SLOT(toDelete()));
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
        emit modify(id,0,ui->comment->toPlainText());
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
        emit modify(id,1,ui->description->toPlainText());
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
        emit modify(id,2,ui->url->toPlainText());
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
        emit modify(id,3,ui->contact->toPlainText());
    }
}

void ProjectUI::modifyFeatures()
{
    if(ui->features->isReadOnly())
    {
        ui->features->setReadOnly(false);
        ui->bmodifyFeatures->setText("Confirm");
    }
    else
    {
        ui->features->setReadOnly(true);
        ui->bmodifyFeatures->setText("Modify");
        emit modify(id,4,ui->features->toPlainText());
    }
}

void ProjectUI::toDelete()
{
    emit deleteProject(id);
    close();
}

