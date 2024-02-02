#include<QApplication>
#include<QIcon>
#include"Model/Tree.h"
#include"Model/SensorFactory.h"
#include"View/MainWindow.h"
#include"Model/sampletree.h"

int main(int argc, char* argv[]){
  static TypeRegistrar registrar;
  QApplication a(argc, argv);
  Tree* t = new Tree();
  MainWindow* v = new MainWindow(t);
  populateSampleTree(t);
  v->setWindowTitle("SensorSim");
  v->updateModel();
  v->show();
  return a.exec();
}