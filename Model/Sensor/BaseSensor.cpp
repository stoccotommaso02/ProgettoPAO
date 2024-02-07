#include"BaseSensor.h"

BaseSensor::BaseSensor(const QString& n, int i): name(n), id(i){
  counter = counter>i? counter : id;
};

QString BaseSensor::getName() const{
  return name;
}

void BaseSensor::setName(QString s){
  name = s;
}

int BaseSensor::getId() const{
  return id;
}