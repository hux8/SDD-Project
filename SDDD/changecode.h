#ifndef CHANGECODE_H
#define CHANGECODE_H

#include <QDialog>

namespace Ui {
class ChangeCode;
}

class ChangeCode : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeCode(QWidget *parent = 0);
    ~ChangeCode();

public slots:
    /**
     * @brief accept accepts the new code
     */
    void accept();

signals:
    /**
     * @brief changeCode emits the new code
     * @param s is the new code
     */
    void changeCode(QString s);

private:
    Ui::ChangeCode *ui;
};

#endif // CHANGECODE_H
