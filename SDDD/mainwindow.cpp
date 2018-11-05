#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    isInstructor=false;
    ui->setupUi(this);
    v=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInstructor()
{
    isInstructor=true;
    enterMain();
}
void MainWindow::verify()
{
    v=new Verification();
    v->show();
    connect(v, SIGNAL(isChecked()), this, SLOT(setInstructor()));
    connect(v, SIGNAL(asStudent()), this, SLOT(enterMain()));
}

void MainWindow::enterMain()
{
    HomePage* h=new HomePage();
    h->setInstructor(isInstructor);
    h->show();
    connect(h,SIGNAL(isClosed()),this,SLOT(quit()) );

    setVisible(false);
    if(v!=NULL)
    {
        v->setVisible(false);
    }

}

void MainWindow::quit()
{
    if(v!=NULL)
    {
        v->close();
    }
    close();
    destroy();

}
