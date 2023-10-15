#include "database.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    DataBase w;
    w.setWindowTitle("База данных рабочих");
    w.show();
    return a.exec();
}
