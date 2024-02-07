#include<QApplication>
#include<QIcon>
#include"Model/Environment.h"
#include"View/MainWindow.h"

//NB atm FilteredList sucks. Consider improving, or disarcing it

int main(int argc, char* argv[]){
  static TypeRegistrar registrar;
  QApplication a(argc, argv);
  Environment* e = Environment::environment();
  MainWindow* v = new MainWindow(e->tree());
  v->setWindowTitle("SensorSim");
  v->updateModel();
  v->show();
  return a.exec();
}