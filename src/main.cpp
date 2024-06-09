#include "dialogwindow.h"
#include "initapp.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  init_app();

  QApplication app(argc, argv);

  DialogWindow w;
  w.setWindowTitle("Drag & Drop Files");
  w.show();

  return app.exec();
}
