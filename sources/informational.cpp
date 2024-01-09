#include "../headers/informational.h"
#include "ui_informational.h"
#include "../headers/buffer.h"

Informational::Informational(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Informational)
{
    ui->setupUi(this);
}

Informational::~Informational(){
    delete ui;
}

void Informational::on_full_info_clicked(){
    ui->FIO->setText(bf.full_name);
    ui->Year->setText(bf.age);
    ui->ZP->setText(bf.salary);
    ui->numberofworker->setText(QString::number(bf.n));
}

