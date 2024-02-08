#include"Reading.h"

Reading::~Reading(){
  delete reading;
}

void Reading::setName(QString n){
  this->name = n;
};

QString Reading::getName() const{
  return this->name;
};

int Reading::getSize() const{
  return reading->count();
}

const QVariant Reading::getValue(int index) const{
  if(index < 0 || index >= reading->count())
    return QVariant();
  return reading->at(index);
}