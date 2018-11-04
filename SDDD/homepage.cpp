#include "homepage.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);


    pitches.append("pitch1");
    pitches.append("pitch2");

    projects.append("project1");
    projects.append("peoject2");

    initialise(ui->pitchList, pitches);
    initialise(ui->projectList, projects);

}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::initialise(QListWidget *w, QList<QString> p)
{
    for(int i=0;i<p.count();i++)
    {
        w->addItem(p[i]);
    }
}



void HomePage::openPitch()
{
    PitchUI* p=new PitchUI();
    p->setAccess(instructor);
    p->show();
}

void HomePage::openProject()
{
    ProjectUI* pr= new ProjectUI();
    pr->setAccess(instructor);
    pr->show();
}

void HomePage::search()
{
    SearchResult* r=new SearchResult();

    r->setWindowTitle("Search Results For:"+ui->lineEdit->text());
    r->show();




}

void HomePage::setInstructor(bool i)
{
    instructor = i;
    setAccess();

}

void HomePage::setAccess()
{
    if(instructor)
        ui->ltitle->setText("Welcome to SDDD, instructor");



}

void HomePage::createPitch()
{
    AddPitch* a=new AddPitch();
    a->show();
}

void HomePage::createProject()
{
    AddProject* ad=new AddProject();
    ad->show();
}
