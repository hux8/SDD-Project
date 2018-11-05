#ifndef VERIFICATION_H
#define VERIFICATION_H

#include <QDialog>

namespace Ui {
class Verification;
}

class Verification : public QDialog
{
    Q_OBJECT

signals:
    void isChecked();
    void asStudent();
    void isClosed();
public:
    explicit Verification(QWidget *parent = 0);
    ~Verification();


public slots:
    void checkCode();
    void showMain();



private:
    Ui::Verification *ui;
    QString code;
    bool checked;
};

#endif // VERIFICATION_H
