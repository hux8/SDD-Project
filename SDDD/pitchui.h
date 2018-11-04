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

public slots:
    void toConfirm();
    void modifyDescription();
    void modifyComment();

private:
    Ui::PitchUI *ui;
};

#endif // PITCHUI_H
