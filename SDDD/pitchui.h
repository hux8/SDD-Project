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

    /**
     * @brief setAccess
     * @param b
     */
    void setAccess(bool b);

    /**
     * @brief setUp sets the attributes of the Pitch
     * @param i is the index of the added Pitch
     * @param date is the date of the added Pitch
     * @param t is the title of the added Pitch
     * @param d is the description of the added Pitch
     */
    void setUp(int i, int date, QString t, QString d);

signals:

    /**
     * @brief modify modifies a Pitch
     * @param id is the index of the Pitch to modify
     * @param item indicates the attribute to modify
     * @param s is the new attribute
     */
    void modify(int id, int item, QString s);

    /**
     * @brief deletePitch emits the index of the Pitch to delete
     * @param id is the index of that Pitch
     */
    void deletePitch(int id);


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
     * @brief toDelete emits the toDelete signal
     */
    void toDelete();

private:
    Ui::PitchUI *ui;
    int id;
};

#endif // PITCHUI_H
