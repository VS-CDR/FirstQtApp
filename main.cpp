#include "headers/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  DataBase main_window;
  main_window.setWindowTitle("База данных рабочих");
  main_window.show();
  return QApplication::exec();
}
