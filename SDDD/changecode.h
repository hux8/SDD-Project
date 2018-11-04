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
    void accept();

signals:
    void changeCode(QString s);

private:
    Ui::ChangeCode *ui;
};

#endif // CHANGECODE_H
