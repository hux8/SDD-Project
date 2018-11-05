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
    void setUp(int i, int date, QString t, QString con, QString url
               , QString f, QString com, QString d ,bool is);
    void setAccess(bool b);
    void setId(int i);

signals:
    void modify(int id, int item, QString s);
    void deleteProject(int id);

public slots:
    void toConfirm();
    void modifyDescription();
    void modifyComment();
    void modifyUrl();
    void modifyContact();
    void modifyFeatures();
    void toDelete();

private:
    Ui::ProjectUI *ui;
    int id;
};

#endif // PROJECTUI_H
