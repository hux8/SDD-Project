#include "pitchui.h"
#include "ui_pitchui.h"

PitchUI::PitchUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PitchUI)
{
    ui->setupUi(this);
    ui->description->setReadOnly(true);
}

PitchUI::~PitchUI()
{
    delete ui;
}

void PitchUI::setAccess(bool b)
{
    ui->bdelete->setVisible(b);
    ui->bmodifyDescription->setVisible(b);
}

void PitchUI::setUp(int i, int date, QString t, QString d)
{
    id=i;
    ui->description->setText(d);
    ui->title->setText(t);
    setWindowTitle(t);
    QString da=QString::number(date);
    ui->date->setText(da.left(4)+"/"+da.mid(4,2)+"/"+da.right(2));
}

void PitchUI::toConfirm()
{
    ConfirmDialog* c=new ConfirmDialog();
    connect(c,SIGNAL(confirmed()),this,SLOT(toDelete()));
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
        emit modify(id, 0,ui->description->toPlainText());
    }
}

void PitchUI::toDelete()
{
    emit deletePitch(id);
    close();
}

