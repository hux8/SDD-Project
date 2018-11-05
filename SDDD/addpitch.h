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
    void newPitch(int date, QString t, QString d);

public slots:
    void createPitch();

private:
    Ui::AddPitch *ui;
};

#endif // ADDPITCH_H
