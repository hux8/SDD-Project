#ifndef PITCHUI_H
#define PITCHUI_H

#include <QWidget>
#include "confirmdialog.h"

namespace Ui {
class PitchUI;
}

class PitchUI : public QWidget
{
    Q_OBJECT

public:
    explicit PitchUI(QWidget *parent = 0);
    ~PitchUI();
    void setAccess(bool b);
    void setUp(int i, int date, QString t, QString d);

signals:
    void modify(int id, int item, QString s);
    void deletePitch(int id);


public slots:
    void toConfirm();
    void modifyDescription();
    void toDelete();

private:
    Ui::PitchUI *ui;
    int id;
};

#endif // PITCHUI_H
