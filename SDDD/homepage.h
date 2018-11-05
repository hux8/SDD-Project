#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QListWidget>
#include "pitchui.h"
#include "projectui.h"
#include "changecode.h"
#include "addpitch.h"
#include "addproject.h"
#include "pitch.h"
#include "project.h"

namespace Ui {
class HomePage;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();
    void setInstructor(bool i);
    void displayPitches(QList<Pitch> p);
    void displayProjects(QList<Project> pr);

protected:
        void closeEvent(QCloseEvent *event);

signals:
    void isClosed();


public slots:
    void search();

    void openPitch();
    void openProject();

    void createPitch();
    void createProject();

    void modifyPitch(int id, int item, QString s);
    void modifyProject(int id, int item, QString s);

    void newPitch(int date, QString t, QString d);
    void newProject(int date, QString t, QString d, QString con, QString u, QString com, QString f);

    void deletePitch(int index);
    void deleteProject(int index);

    void display();


private:
    Ui::HomePage *ui;

    bool instructor;
    void setAccess();

    QList<Pitch> pitches;
    QList<Project> projects;

    QList<Pitch> pitchesCur;
    QList<Project> projectsCur;

};

#endif // HOMEPAGE_H
