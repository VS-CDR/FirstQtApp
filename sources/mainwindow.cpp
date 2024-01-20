#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../headers/add_worker_win.h"
#include "../headers/buffer.h"
#include "../headers/informational.h"

DataBase::DataBase(QWidget* parent)
    : QMainWindow(parent), ui_(new Ui::DataBase) {
  ui_->setupUi(this);
  //ui->FIO->setDisabled(true);
  ui_->Year->setDisabled(true);
  ui_->ZP->setDisabled(true);
}

DataBase::~DataBase() {
  delete ui_;
}

long long cntSalary = 0;
QVector<QString> workers;
QVector<QPair<int, int>> workers_properties;

QStandardItemModel* DataBase::NewWorkersModel() const {
  auto* data = new QStandardItemModel;
  QStringList name_columns;
  name_columns.append("ФИО сотрудника");
  name_columns.append("Год рождения");
  name_columns.append("Заработная плата");
  data->setHorizontalHeaderLabels(name_columns);
  return data;
}

void DataBase::AddWorkerClicked() {
  if (bf.full_name.isEmpty()) {
    return;
  }
  auto* data = NewWorkersModel();

  workers.push_back(bf.full_name);
  workers_properties.push_back(qMakePair(bf.age.toInt(), bf.salary.toInt()));

  PrintWorkerEntry(data);

  ui_->Base->setModel(data);
  ui_->Base->resizeColumnsToContents();

  cntSalary += bf.salary.toLongLong();
  ui_->TotalZP->setText(QString::number(cntSalary, kDec));
}

void DataBase::PrintWorkerEntry(QStandardItemModel* data) const {
  for (int cnt = 0; cnt < std::ssize(workers); ++cnt) {
    auto* worker_fio = new QStandardItem(workers[cnt]);
    auto* worker_by = new QStandardItem(
        QString::number(workers_properties[cnt].first, kDec));
    auto* worker_salary = new QStandardItem(
        QString::number(workers_properties[cnt].second, kDec));
    data->setItem(cnt, 0, worker_fio);
    data->setItem(cnt, 1, worker_by);
    data->setItem(cnt, 2, worker_salary);
  }
}

void DataBase::SearchClicked() {
  bool found = false;
  if (ui_->Find->isChecked()) {
    for (ssize_t i = 0; i < std::ssize(workers) && !found; ++i) {
      if (workers[i] == ui_->FIO->text()) {
        bf.full_name = workers[i];
        bf.age = QString::number(workers_properties[i].first);
        bf.salary = QString::number(workers_properties[i].second);
        ui_->Num->setText(QString::number(i, kDec));
        auto* unit = new Informational;
        bf.n = i + 1;
        unit->show();
        found = true;
      }
    }
  } else if (ui_->Remove->isChecked()) {
    for (ssize_t i = 0; i < std::ssize(workers) && !found; ++i) {
      if (workers[i] == ui_->FIO->text() &&
          workers_properties[i].first == ui_->Year->text().toInt()) {
        cntSalary -= workers_properties[i].second;

        workers.erase(workers.begin() + i);
        workers_properties.erase(workers_properties.begin() + i);
        ui_->Num->setText("Работник удалён");

        QStandardItemModel* data = NewWorkersModel();
        PrintWorkerEntry(data);

        ui_->Base->setModel(data);
        ui_->Base->resizeColumnsToContents();

        ui_->TotalZP->setText(QString::number(cntSalary, kDec));

        found = true;
      }
    }
  }
  if (!found) {
    ui_->Num->setText("Работник не найден.");
  }
}

void DataBase::CountClicked() {
  ui_->countInfo->setText(QString::number(workers.size(), kDec));
}

void DataBase::AddWinClicked() {
  auto* form = new AddWorkerWin;
  form->show();
}

