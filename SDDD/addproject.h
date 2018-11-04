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

public slots:
    void createProject();

private:
    Ui::AddProject *ui;
};

#endif // ADDPROJECT_H
