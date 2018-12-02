#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
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

    /**
     * @brief setInstructor sets the access of the user
     * @param i is true if the user is an instructor
     */
    void setInstructor(bool i);

    /**
     * @brief displayPitches displays the pitches on the homepage
     * @param p is the list of Pitches
     */
    void displayPitches(QList<Pitch> p);

    /**
     * @brief displayProjects displays the projects on the homepage
     * @param pr is the list of Projects
     */
    void displayProjects(QList<Project> pr);

protected:

    /**
     * @brief closeEvent emits the isClosed signal
     * @param event
     */
    void closeEvent(QCloseEvent *event);

signals:

    /**
     * @brief isClosed signals that the homepage is closed
     */
    void isClosed();


public slots:

    /**
     * @brief search is called when the user clicks the search button and initiates the seach
     */
    void search();

    /**
     * @brief openPitch opens the detail page of a pitch
     */
    void openPitch();

    /**
     * @brief openProject opens the detail page of a project
     */
    void openProject();

    /**
     * @brief createPitch opens the page to create a new Pitch
     */
    void createPitch();

    /**
     * @brief createProject opens the page to create a new Project
     */
    void createProject();

    /**
     * @brief modifyPitch modifies a Pitch
     * @param id is the index of the Pitch in the Pitch list
     * @param item indicates the attribute changed
     * @param s is the new attribute
     */
    void modifyPitch(int id, int item, QString s);

    /**
     * @brief modifyProject modifies a Project
     * @param id is the index of the Project in the Project list
     * @param item indicates the attribute changed
     * @param s is the new attribute
     */
    void modifyProject(int id, int item, QString s);

    /**
     * @brief newPitch creates a new Pitch
     * @param date is the date of the new Pitch
     * @param t is the title of the new Pitch
     * @param d is description of the Pitch
     */
    void newPitch(int date, QString t, QString d);

    /**
     * @brief newProject creates a new Project
     * @param date is the date of the new Project
     * @param t is the title of the new Project
     * @param d is the description of the new Project
     * @param con is the contactInfo of the new Project
     * @param u is the url of the new Project
     * @param com is the comment of the new Project
     * @param f is the features of the new Project
     */
    void newProject(int date, QString t, QString d, QString con, QString u, QString com, QString f);

    /**
     * @brief deletePitch deletes a Pitch
     * @param index is the index of the Pitch to delete
     */
    void deletePitch(int index);

    /**
     * @brief deleteProject deletes a Project
     * @param index is the index of the Project to delete
     */
    void deleteProject(int index);

    /**
     * @brief display updates the display
     */
    void display();


private:
    Ui::HomePage *ui;

    bool instructor;

    /**
     * @brief setAccess sets the access
     */
    void setAccess();

    /**
     * @brief writeData update the data file
     */
    void writeData();

    /**
     * @brief readData reads the data file
     */
    void readData();

    QList<Pitch> pitches;
    QList<Project> projects;

    QList<Pitch> pitchesCur;
    QList<Project> projectsCur;

};

#endif // HOMEPAGE_H
