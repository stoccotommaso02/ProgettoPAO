#include"IconVisitor.h"

QPixmap IconVisitor::getIcon() const{
  return icon;
}

void IconVisitor::visit(const TemperatureSensor& sensor){
  Q_UNUSED(sensor);
  QPixmap image(":/Images/temperature.svg");
  icon.swap(image);
};

void IconVisitor::visit(const WindSensor& sensor){
  Q_UNUSED(sensor);
  QPixmap image(":/Images/wind.svg");
  icon.swap(image);
};

void IconVisitor::visit(const DustSensor& sensor){
  Q_UNUSED(sensor);
  QPixmap image(":/Images/dust.svg");
  icon.swap(image);
};

void IconVisitor::visit(const HumiditySensor& sensor){
  Q_UNUSED(sensor);
  QPixmap image(":/Images/humidity.svg");
  icon.swap(image);
};

void IconVisitor::visit(const RainSensor& sensor){
  Q_UNUSED(sensor);
  QPixmap image(":/Images/rain.svg");
  icon.swap(image);
};

void IconVisitor::visit(const TemperatureReading& reading){
  Q_UNUSED(reading);
  QPixmap image(":/Images/temperature.svg");
  icon.swap(image);
};

void IconVisitor::visit(const WindReading& reading){
  Q_UNUSED(reading);
  QPixmap image(":/Images/wind.svg");
  icon.swap(image);
};

void IconVisitor::visit(const DustReading& reading){
  Q_UNUSED(reading);
  QPixmap image(":/Images/dust.svg");
  icon.swap(image);
};

void IconVisitor::visit(const HumidityReading& reading){
  Q_UNUSED(reading);
  QPixmap image(":/Images/humidity.svg");
  icon.swap(image);
};

void IconVisitor::visit(const RainReading& reading){
  Q_UNUSED(reading);
  QPixmap image(":/Images/rain.svg");
  icon.swap(image);
};