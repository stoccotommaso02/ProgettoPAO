#include"BaseSensor.h"

unsigned int BaseSensor::counter = 0;

QString BaseSensor::getName() const{
  return name;
}

void BaseSensor::setName(QString s){
  name = s;
}

unsigned int BaseSensor::getId() const{
  return id;
}