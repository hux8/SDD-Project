#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QListWidget>
#include "searchresult.h"
#include "pitchui.h"
#include "projectui.h"
#include "changecode.h"
#include "addpitch.h"
#include "addproject.h"

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
    void initialise(QListWidget* w, QList<QString> p);


public slots:
    void search();
    void openPitch();
    void openProject();
    void createPitch();
    void createProject();


private:
    Ui::HomePage *ui;

    bool instructor;
    void setAccess();

    QList<QString> pitches;
    QList<QString> projects;
};

#endif // HOMEPAGE_H
