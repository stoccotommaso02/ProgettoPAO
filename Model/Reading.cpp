#include"Reading.h"

void Reading::setName(QString n){
  this->name = n;
};

QString Reading::getName() const{
  return this->name;
};

std::array<double, 24> Reading::getValues() const{
  return this->reading;
};
