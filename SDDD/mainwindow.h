#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "verification.h"
#include "homepage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    /**
     * @brief verify opens the verification page
     */
    void verify();

    /**
     * @brief enterMain opens the homepage
     */
    void enterMain();

    /**
     * @brief setInstructor sets the access
     */
    void setInstructor();

    /**
     * @brief quit closes the program
     */
    void quit();

private:
    Ui::MainWindow *ui;
    bool isInstructor;

    Verification* v;
};

#endif // MAINWINDOW_H
