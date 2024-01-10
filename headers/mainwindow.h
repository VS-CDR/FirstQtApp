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
  explicit DataBase(QWidget *parent = nullptr);
  ~DataBase() override;

 private slots:
  void AddWorkerClicked();
  void SearchClicked();
  void CountClicked();
  static void AddWinClicked();

 private:
  constexpr static int kDec = 10;
  Ui::DataBase *ui_;
  void PrintWorkerEntry(QStandardItemModel* data) const;
  QStandardItemModel* NewWorkersModel() const;
};
#endif // DATABASE_H
