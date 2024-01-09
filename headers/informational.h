#ifndef INFORMATIONAL_H
#define INFORMATIONAL_H

#include <QDialog>

namespace Ui {
class Informational;
}

class Informational : public QDialog {
  Q_OBJECT

 public:
  explicit Informational(QWidget* parent = nullptr);
  ~Informational() override;

 private slots:
  void OnFullInfoClicked();

 private:
  Ui::Informational* ui;
};

#endif // INFORMATIONAL_H
