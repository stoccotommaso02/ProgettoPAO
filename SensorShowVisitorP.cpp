#include "SensorShowVisitor.h"

QPixmap SensorShowVisitor::getIcon(){
    return icon;
};

void SensorShowVisitor::visit(const TemperatureSensor& sensor){
  QPixmap image(":icons/celsius.png");
  icon.swap(image);
};

void SensorShowVisitor::visit(const WindSensor& sensor){
  QPixmap image(":icons/wind.png");
  icon.swap(image);
};

void SensorShowVisitor::visit(const DustSensor& sensor){
  QPixmap image(":icons/dust.png");
  icon.swap(image);
};

void SensorShowVisitor::visit(const HumiditySensor& sensor){
  QPixmap image(":icons/humidity.png");
  icon.swap(image);
};

void SensorShowVisitor::visit(const RainSensor& sensor){
  QPixmap image(":icons/rainy.png");
  icon.swap(image);
};