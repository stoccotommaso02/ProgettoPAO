#include "RainSensor.h"

RainSensor* RainSensor::clone() const {
	return new RainSensor(*this);
};

void RainSensor::accept(SensorVisitor& v){
  v.visit(*this);
}

Reading* RainSensor::simulate(const QString& name, int numEntries) const{
  return nullptr;
}