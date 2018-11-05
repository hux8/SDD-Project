#ifndef ADDPROJECT_H
#define ADDPROJECT_H

#include <QWidget>

namespace Ui {
class AddProject;
}

class AddProject : public QWidget
{
    Q_OBJECT

public:
    explicit AddProject(QWidget *parent = 0);
    ~AddProject();

signals:
    void newProject(int date, QString t, QString d, QString con, QString u, QString com, QString f);

public slots:
    void createProject();

private:
    Ui::AddProject *ui;
};

#endif // ADDPROJECT_H
