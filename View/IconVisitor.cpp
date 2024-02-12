#include"IconVisitor.h"

QPixmap IconVisitor::getIcon() const{
  return icon;
}

void IconVisitor::visit(const TemperatureSensor& sensor){
  QPixmap image(":/Images/temperature.svg");
  icon.swap(image);
};

void IconVisitor::visit(const WindSensor& sensor){
  QPixmap image(":/Images/wind.svg");
  icon.swap(image);
};

void IconVisitor::visit(const DustSensor& sensor){
  QPixmap image(":/Images/dust.svg");
  icon.swap(image);
};

void IconVisitor::visit(const HumiditySensor& sensor){
  QPixmap image(":/Images/humidity.svg");
  icon.swap(image);
};

void IconVisitor::visit(const RainSensor& sensor){
  QPixmap image(":/Images/rain.svg");
  icon.swap(image);
};

void IconVisitor::visit(const TemperatureReading& sensor){
  QPixmap image(":/Images/temperature.svg");
  icon.swap(image);
};

void IconVisitor::visit(const WindReading& sensor){
  QPixmap image(":/Images/wind.svg");
  icon.swap(image);
};

void IconVisitor::visit(const DustReading& sensor){
  QPixmap image(":/Images/dust.svg");
  icon.swap(image);
};

void IconVisitor::visit(const HumidityReading& sensor){
  QPixmap image(":/Images/humidity.svg");
  icon.swap(image);
};

void IconVisitor::visit(const RainReading& sensor){
  QPixmap image(":/Images/rain.svg");
  icon.swap(image);
};