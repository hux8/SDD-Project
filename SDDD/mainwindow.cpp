#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    isInstructor=false;
    ui->setupUi(this);
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
    Verification* v=new Verification();
    v->show();
    connect(v, SIGNAL(isChecked()), this, SLOT(setInstructor()));
    connect(v, SIGNAL(asStudent()), this, SLOT(enterMain()));
}

void MainWindow::enterMain()
{
    HomePage* h=new HomePage();
    h->setInstructor(isInstructor);
    h->show();


}
