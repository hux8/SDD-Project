#ifndef ADDPITCH_H
#define ADDPITCH_H

#include <QWidget>

namespace Ui {
class AddPitch;
}

class AddPitch : public QWidget
{
    Q_OBJECT

public:
    explicit AddPitch(QWidget *parent = 0);
    ~AddPitch();

signals:

    /**
     * @brief newPitch emits the attributes of the new Pitch
     * @param date is the date of the created Pitch
     * @param t is the title of the created Pitch
     * @param d is the description of the created Pitch
     */
    void newPitch(int date, QString t, QString d);

public slots:
    /**
     * @brief createPitch createsa new Pitch
     */
    void createPitch();

private:
    Ui::AddPitch *ui;
};

#endif // ADDPITCH_H
