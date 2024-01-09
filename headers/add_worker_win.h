#ifndef ADDWORKERWIN_H
#define ADDWORKERWIN_H

#include <QDialog>

namespace Ui {
class AddWorkerWin;
}

class AddWorkerWin : public QDialog {
  Q_OBJECT

 public:
  explicit AddWorkerWin(QWidget* parent = nullptr);
  ~AddWorkerWin();

 private
  slots:
      void AddWorkerClicked();

 private:
  Ui::AddWorkerWin* ui;
};

#endif // ADDWORKERWIN_H
