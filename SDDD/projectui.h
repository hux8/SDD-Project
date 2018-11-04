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
    void setFeatures();
    void setAccess(bool b);

public slots:
    void toConfirm();
    void modifyDescription();
    void modifyComment();
    void modifyUrl();
    void modifyContact();
    void modifyFeatures();

private:
    Ui::ProjectUI *ui;
};

#endif // PROJECTUI_H
