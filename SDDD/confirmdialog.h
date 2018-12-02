#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>

namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialog(QWidget *parent = 0);
    ~ConfirmDialog();

private slots:
    /**
     * @brief confirm confirms the change and emits confirmed
     */
    void confirm();

signals:

    /**
     * @brief confirmed is signals that the user confirmed the change
     */
    void confirmed();

private:
    Ui::ConfirmDialog *ui;
};

#endif // CONFIRMDIALOG_H
