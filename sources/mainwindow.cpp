#include "../headers/mainwindow.h"
#include "ui_database.h"
#include "../headers/add_worker_win.h"
#include "../headers/buffer.h"
#include "../headers/informational.h"

DataBase::DataBase(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::DataBase) {
  ui->setupUi(this);
  //ui->FIO->setDisabled(true);
  ui->Year->setDisabled(true);
  ui->ZP->setDisabled(true);
}

DataBase::~DataBase() {
  delete ui;
}

long long cntSalary = 0;
std::vector<QString> workers;
std::vector<QPair<int, int>> workers_properties;

void DataBase::AddWorkerClicked() {
  if (bf.full_name.isEmpty()) {
    return;
  }
  auto* data = new QStandardItemModel;
  QStringList name_columns;
  name_columns.append("ФИО сотрудника");
  name_columns.append("Год рождения");
  name_columns.append("Заработная плата");
  data->setHorizontalHeaderLabels(name_columns);

  workers.push_back(bf.full_name);
  workers_properties.push_back(qMakePair(bf.age.toInt(), bf.salary.toInt()));

  for (unsigned cnt = 0; cnt < workers.size(); ++cnt) {
    auto* workerFIO = new QStandardItem(workers[cnt]);
    auto* workerBY =
        new QStandardItem(QString::number(workers_properties[cnt].first, 10));
    auto* workerSalary =
        new QStandardItem(QString::number(workers_properties[cnt].second, 10));
    data->setItem(cnt, 0, workerFIO);
    data->setItem(cnt, 1, workerBY);
    data->setItem(cnt, 2, workerSalary);
  }

  ui->Base->setModel(data);
  ui->Base->resizeColumnsToContents();

  cntSalary += bf.salary.toLongLong();
  ui->TotalZP->setText(QString::number(cntSalary, 10));
}

void DataBase::SearchClicked() {
  bool found = false;
  if (ui->Find->isChecked()) {
    for (unsigned i = 0; i < workers.size(); ++i) {
      if (workers[i] == ui->FIO->text()) {
        bf.full_name = workers[i];
        bf.age = QString::number(workers_properties[i].first);
        bf.salary = QString::number(workers_properties[i].second);
        ui->Num->setText(QString::number(++i, 10));
        auto* unit = new Informational;
        bf.n = i;
        unit->show();
        found = true;
        break;
      }
    }
    if (!found) {
      ui->Num->setText("Работник не найден.");
    }
  } else if (ui->Remove->isChecked()) {
    for (unsigned i = 0; i < workers.size(); ++i) {
      if (workers[i] == ui->FIO->text()
          && workers_properties[i].first == ui->Year->text().toInt()) {
        cntSalary -= workers_properties[i].second;

        workers.erase(workers.begin() + i);
        workers_properties.erase(workers_properties.begin() + i);
        ui->Num->setText("Работник удалён");

        auto* data = new QStandardItemModel;
        QStringList name_columns;
        name_columns.append("ФИО сотрудника");
        name_columns.append("Год рождения");
        name_columns.append("Заработная плата");
        data->setHorizontalHeaderLabels(name_columns);

        for (unsigned cnt = 0; cnt < workers.size(); ++cnt) {
          auto* workerFIO = new QStandardItem(workers[cnt]);
          auto* workerBY = new QStandardItem(QString::number(
              workers_properties[cnt].first,
              10));
          auto* workerSalary = new QStandardItem(QString::number(
              workers_properties[cnt].second,
              10));
          data->setItem(cnt, 0, workerFIO);
          data->setItem(cnt, 1, workerBY);
          data->setItem(cnt, 2, workerSalary);
        }

        ui->Base->setModel(data);
        ui->Base->resizeColumnsToContents();

        ui->TotalZP->setText(QString::number(cntSalary, 10));

        found = true;
        break;
      }
    }
    if (!found) {
      ui->Num->setText("Работник не найден.");
    }
  }
}

void DataBase::CountClicked() {
  ui->countInfo->setText(QString::number(workers.size(), 10));
}

void DataBase::AddWinClicked() {
  auto* form = new AddWorkerWin;
  form->show();
}

