#include "homepage.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);

    ui->lsearch->setVisible(false);
    ui->bcancelSearch->setVisible(false);

    Pitch p1(20181104, "pitch1", "This is pitch1");
    Pitch p2(20181105, "pitch2", "This is pitch2");

    pitches.append(p1);
    pitches.append(p2);

    std::vector<std::string> f1;
    f1.push_back("feature1");
    f1.push_back("feature2");

    std::vector<std::string> f2;
    f2.push_back("feature3");
    f2.push_back("feature4");

    Project pr1("project1", "website1.com", "This is description1", "owner1@rpi.edu", "comment1", 20181111, f1);
    Project pr2("project2", "", "This is description2", "owner2@rpi.edu", "", 20181212, f2);

    projects.append(pr1);
    projects.append(pr2);

    display();

}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::display()
{
    if(instructor)
    {
        ui->baddPitch->setVisible(true);
        ui->baddProject->setVisible(true);
    }

    ui->lsearch->setVisible(false);
    ui->bcancelSearch->setVisible(false);
    ui->lineEdit->setText("");

    pitchesCur=pitches;
    projectsCur=projects;

    displayPitches(pitches);
    displayProjects(projects);

}

void HomePage::closeEvent(QCloseEvent *event)
{
    emit isClosed();
    QMainWindow::closeEvent(event);
}

void HomePage::displayPitches(QList<Pitch> p)
{
    ui->pitchList->clear();
    for(int i=0;i<p.count();i++)
    {
        ui->pitchList->addItem(p[i].get_title());
    }
}

void HomePage::displayProjects(QList<Project> pr)
{
    ui->projectList->clear();
    for(int i=0;i<pr.count();i++)
    {
        ui->projectList->addItem(QString::fromStdString( pr[i].getTitle()));
    }
}



void HomePage::openPitch()
{
    PitchUI* p=new PitchUI();
    p->setAccess(instructor);
    Pitch cur=pitchesCur[ui->pitchList->currentRow()];
    p->setUp(ui->pitchList->currentRow(), cur.get_date(),cur.get_title(), cur.get_content());

    connect(p,SIGNAL(modify(int,int,QString)),this,SLOT(modifyPitch(int,int,QString)));
    connect(p,SIGNAL(deletePitch(int)),this,SLOT(deletePitch(int)));
    p->show();

}

void HomePage::openProject()
{
    ProjectUI* pr= new ProjectUI();
    connect(pr,SIGNAL(deleteProject(int)),this,SLOT(deleteProject(int)));
    connect(pr,SIGNAL(modify(int,int,QString)),this,SLOT(modifyProject(int,int,QString)));

    pr->setAccess(instructor);
    Project cur=projectsCur[ui->projectList->currentRow()];

    QString t,con,u,com,f,d;

    t=QString::fromStdString(cur.getTitle());
    u=QString::fromStdString(cur.getUrl());
    con=QString::fromStdString(cur.getContactInfo());
    com=QString::fromStdString(cur.getComment());
    d=QString::fromStdString(cur.getDescription());
    f=QString::fromStdString(cur.getFeatures()[0]);
    std::vector<std::string> v=cur.getFeatures();


    for(unsigned int i=1;i<v.size();i++)
    {
        f+="\n";
        f+=QString::fromStdString(v[i]);
    }

    pr->setUp(ui->projectList->currentRow(), cur.getAddDate(), t, con, u, f, com, d,instructor);


    pr->show();
}

void HomePage::search()
{


    QString key=ui->lineEdit->text();
    if(key!="")
    {
        ui->baddPitch->setVisible(false);
        ui->baddProject->setVisible(false);

        QList<Pitch> pitchR;
        QList<Project> projectsR;

        for(int i=0;i<pitches.size();i++)
        {
            if(pitches[i].search(key.toStdString()))
                pitchR.append(pitches[i]);
        }

        for(int i=0;i<projects.size();i++)
        {
            if(projects[i].search(key.toStdString()))
                projectsR.append(projects[i]);
        }

        ui->lsearch->setText("search results for: "+key);

        ui->lsearch->setVisible(true);
        ui->bcancelSearch->setVisible(true);

        pitchesCur=pitchR;
        projectsCur=projectsR;

        displayPitches(pitchR);
        displayProjects(projectsR);
    }
    else
    {
        display();
    }



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

    ui->baddPitch->setVisible(instructor);
    ui->baddProject->setVisible(instructor);
}

void HomePage::modifyPitch(int id, int item, QString s)
{
    if(item==0)
    {
        pitchesCur[id].modify_content(s);
        for(int i=0;i<pitches.size();i++)
        {
            if(pitches[i].get_title()==pitchesCur[id].get_title())
            {
                pitches[i].modify_content(s);
            }
        }
    }

}

void HomePage::modifyProject(int id, int item, QString s)
{
    if(item==0)
    {
        projectsCur[id].modifyComment(s.toStdString());
        for(int i=0;i<projects.size();i++)
        {
            if(projects[i].getTitle()==projectsCur[id].getTitle())
            {
                projects[i].modifyComment(s.toStdString());
            }
        }
    }

    if(item==1)
    {
        projectsCur[id].modifyDescription(s.toStdString());
        for(int i=0;i<projects.size();i++)
        {
            if(projects[i].getTitle()==projectsCur[id].getTitle())
            {
                projects[i].modifyDescription(s.toStdString());
            }
        }
    }

    if(item==2)
    {
        projectsCur[id].modifyUrl(s.toStdString());
        for(int i=0;i<projects.size();i++)
        {
            if(projects[i].getTitle()==projectsCur[id].getTitle())
            {
                projects[i].modifyUrl(s.toStdString());
            }
        }
    }

    if(item==3)
    {
        projectsCur[id].modifyContactInfo(s.toStdString());
        for(int i=0;i<projects.size();i++)
        {
            if(projects[i].getTitle()==projectsCur[id].getTitle())
            {
                projects[i].modifyContactInfo(s.toStdString());
            }
        }
    }

    if(item==4)
    {
        std::vector<std::string> v;
        int n=0;
        while(!s.isEmpty()&&s.contains("\n"))
        {
            n=s.lastIndexOf("\n");
            v.push_back(s.left(n).toStdString());
            s=s.mid(n+1);
        }
        if(!s.isEmpty())
            v.push_back(s.toStdString());

        projectsCur[id].modifyFeatures(v);
        for(int i=0;i<projects.size();i++)
        {
            if(projects[i].getTitle()==projectsCur[id].getTitle())
            {
                projects[i].modifyFeatures(v);
            }
        }
    }
}

void HomePage::createPitch()
{
    AddPitch* a=new AddPitch();
    connect(a,SIGNAL(newPitch(int,QString,QString)),this,SLOT(newPitch(int,QString,QString)));
    a->show();
}

void HomePage::createProject()
{
    AddProject* ad=new AddProject();
    connect(ad,SIGNAL(newProject(int,QString,QString,QString,QString,QString,QString)),
            this,SLOT(newProject(int,QString,QString,QString,QString,QString,QString)));
    ad->show();

}

void HomePage::newPitch(int date, QString t, QString d)
{
    Pitch p(date,t,d);
    pitches.push_front(p);
    pitchesCur.push_front(p);
    ui->pitchList->insertItem(0, p.get_title());
}

void HomePage::newProject(int date, QString t, QString d, QString con, QString u, QString com, QString f)
{
    std::vector<std::string> v;
    int n=0;
    while(!f.isEmpty()&&f.contains("\n"))
    {
         n=f.lastIndexOf("\n");
         v.push_back(f.left(n).toStdString());
         f=f.mid(n+1);
    }
    if(!f.isEmpty())
        v.push_back(f.toStdString());

    Project p(t.toStdString(), u.toStdString(), d.toStdString(), con.toStdString(), com.toStdString(),
              date, v);
    projects.push_front(p);
    projectsCur.push_front(p);
    ui->projectList->insertItem(0,QString::fromStdString(p.getTitle()));
}

void HomePage::deletePitch(int index)
{
    QList<Pitch>::iterator itr,itr2;
    itr=pitchesCur.begin();
    for(int i=0;i<index;i++)
    {
        itr++;
    }



    itr2=pitches.begin();
    while(itr2!=pitches.end())
    {
        if(itr2->get_title()==itr->get_title())
        {
            pitches.erase(itr2);
            break;
        }
        itr2++;
    }

    pitchesCur.erase(itr);

    ui->pitchList->takeItem(index);
}

void HomePage::deleteProject(int index)
{
    QList<Project>::iterator itr, itr2;
    itr=projectsCur.begin();
    for(int i=0;i<index;i++)
    {
        itr++;

    }

    itr2=projects.begin();
    while(itr2!=projects.end())
    {
        if(itr2->getTitle()==itr->getTitle())
        {
            projects.erase(itr2);
            break;
        }
    }

    projectsCur.erase(itr);
    ui->projectList->takeItem(index);
}


