#include<QApplication>
#include"Model/Sensor/RainSensor.h"
#include"View/SensorShow.h"

int main(int argc, char* argv[]){
  QApplication a(argc, argv);
  RainSensor* r = new RainSensor("RainS");
  SensorShow* v = new SensorShow(r, nullptr);
  v->refresh();
  v->show();
  return a.exec();
}