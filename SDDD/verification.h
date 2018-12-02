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
    /**
     * @brief isChecked is emitted when the user passes
     */
    void isChecked();

    /**
     * @brief asStudent is emitted when the user choses to continue as student/visitor
     */
    void asStudent();

    /**
     * @brief isClosed is emitted when the window is closed
     */
    void isClosed();
public:
    explicit Verification(QWidget *parent = 0);
    ~Verification();


public slots:

    /**
     * @brief checkCode checks the code entered by the user
     */
    void checkCode();

    /**
     * @brief showMain opens the homepage
     */
    void showMain();



private:
    Ui::Verification *ui;
    QString code;
    bool checked;
};

#endif // VERIFICATION_H
