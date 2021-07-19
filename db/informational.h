#ifndef INFORMATIONAL_H
#define INFORMATIONAL_H

#include <QDialog>

namespace Ui {
class Informational;
}

class Informational : public QDialog
{
    Q_OBJECT

public:
    explicit Informational(QWidget *parent = nullptr);
    ~Informational();

private slots:
    void on_full_info_clicked();

private:
    Ui::Informational *ui;
};

#endif // INFORMATIONAL_H
