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
    /**
     * @brief newProject emits the attributes of the new Project
     * @param date is the date of the created Project
     * @param t is the title of the created Project
     * @param d is the description of the created Project
     * @param con is the contactInfo of the created Project
     * @param u is the url of the created Project
     * @param com is the comment of the created Project
     * @param f is the features of the created Project
     */
    void newProject(int date, QString t, QString d, QString con, QString u, QString com, QString f);

public slots:
    /**
     * @brief createProject creates a new Project
     */
    void createProject();

private:
    Ui::AddProject *ui;
};

#endif // ADDPROJECT_H
