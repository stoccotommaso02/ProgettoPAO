#include"TypeSensorVisitor.h"

void TypeSensorVisitor::visit(const TemperatureSensor& sensor){
  type_name = "Temperature";
}

void TypeSensorVisitor::visit(const WindSensor& sensor){
  type_name = "Wind";
}

void TypeSensorVisitor::visit(const DustSensor& sensor){
  type_name = "Dust";
}

void TypeSensorVisitor::visit(const HumiditySensor& sensor){
  type_name = "Humidity";
}

void TypeSensorVisitor::visit(const RainSensor& sensor){
  type_name = "Rain";
}

QString TypeSensorVisitor::getType() const{
  return type_name;
}