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
    void verify();
    void enterMain();
    void setInstructor();

private:
    Ui::MainWindow *ui;
    bool isInstructor;
};

#endif // MAINWINDOW_H
