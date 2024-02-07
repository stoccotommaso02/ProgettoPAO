#include"TypeReadingVisitor.h"

void TypeReadingVisitor::visit(const TemperatureReading& sensor){
  type_name = "Temperature";
}

void TypeReadingVisitor::visit(const WindReading& sensor){
  type_name = "Wind";
}

void TypeReadingVisitor::visit(const DustReading& sensor){
  type_name = "Dust";
}

void TypeReadingVisitor::visit(const HumidityReading& sensor){
  type_name = "Humidity";
}

void TypeReadingVisitor::visit(const RainReading& sensor){
  type_name = "Rain";
}

QString TypeReadingVisitor::getType() const{
  return type_name;
}