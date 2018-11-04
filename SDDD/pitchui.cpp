#include "pitchui.h"
#include "ui_pitchui.h"

PitchUI::PitchUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PitchUI)
{
    ui->setupUi(this);
    ui->description->setReadOnly(true);
    ui->comment->setReadOnly(true);
}

PitchUI::~PitchUI()
{
    delete ui;
}

void PitchUI::setAccess(bool b)
{
    ui->bdelete->setVisible(b);
    ui->bmodifyComment->setVisible(b);
    ui->bmodifyDescription->setVisible(b);
}

void PitchUI::toConfirm()
{
    ConfirmDialog* c=new ConfirmDialog();
    c->show();
}

void PitchUI::modifyDescription()
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

void PitchUI::modifyComment()
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
