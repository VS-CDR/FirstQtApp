#include "addworkerwin.h"
#include "ui_addworkerwin.h"
#include "buffer.h"

AddWorkerWin::AddWorkerWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWorkerWin){
    ui->setupUi(this);
}

AddWorkerWin::~AddWorkerWin(){
    delete ui;
}

void AddWorkerWin::on_ADDworker_clicked(){
    bf.age=ui->Year->text();
    bf.full_name=ui->FIO->text();
    bf.salary=ui->ZP->text();
    this->close();
}

