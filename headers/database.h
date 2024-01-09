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

class DataBase : public QMainWindow {
 Q_OBJECT

 public:
  DataBase(QWidget *parent = nullptr);
  ~DataBase();

 private slots:
  void AddWorkerClicked();
  void SearchClicked();
  void CountClicked();
  static void AddWinClicked();

 private:
  Ui::DataBase *ui;
};
#endif // DATABASE_H
