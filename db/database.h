#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <vector>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class DataBase; }
QT_END_NAMESPACE

class DataBase : public QMainWindow
{
    Q_OBJECT

public:
    DataBase(QWidget *parent = nullptr);
    ~DataBase();

private slots:
    void on_ADDworker_clicked();
    void on_Search_clicked();
    void on_count_clicked();
    void on_ADDWin_clicked();

private:
    Ui::DataBase *ui;
};
#endif // DATABASE_H
