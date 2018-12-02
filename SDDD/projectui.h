#ifndef PROJECTUI_H
#define PROJECTUI_H

#include <QWidget>
#include "confirmdialog.h"

namespace Ui {
class ProjectUI;
}

class ProjectUI : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectUI(QWidget *parent = 0);
    ~ProjectUI();

    /**
     * @brief setUp sets up the page
     * @param i is the index of the Project
     * @param date is the date of the Project
     * @param t is the title of the Project
     * @param con is the contactInfo of the Project
     * @param url is the url of the Project
     * @param f is the dfeatures list of the Project
     * @param com is the comment of the Project
     * @param d is the description of the Project
     * @param is is true if the user is an instructor, false otherwise
     */
    void setUp(int i, int date, QString t, QString con, QString url
               , QString f, QString com, QString d ,bool is);

    /**
     * @brief setAccess sets the access
     * @param b is true if the user is an instructor, false otherwise
     */
    void setAccess(bool b);

    /**
     * @brief setId sets the id
     * @param i is the id
     */
    void setId(int i);

signals:
    /**
     * @brief modify emits the id, index of attribute, and new attribute content
     * @param id is the index of the Project
     * @param item indicates the attribute to modify
     * @param s is the new attribute
     */
    void modify(int id, int item, QString s);

    /**
     * @brief deleteProject emits the index of the project ot delete
     * @param id is the index of the project to delete
     */
    void deleteProject(int id);

public slots:

    /**
     * @brief toConfirm opens the confirm dialog
     */
    void toConfirm();

    /**
     * @brief modifyDescription modifies the description
     */
    void modifyDescription();

    /**
     * @brief modifyComment modifies the comment
     */
    void modifyComment();

    /**
     * @brief modifyUrl modifies the url
     */
    void modifyUrl();

    /**
     * @brief modifyContact modifies the contactInfo
     */
    void modifyContact();

    /**
     * @brief modifyFeatures  modifies the features
     */
    void modifyFeatures();

    /**
     * @brief toDelete emits the deleteProject signal
     */
    void toDelete();

private:
    Ui::ProjectUI *ui;
    int id;
};

#endif // PROJECTUI_H
