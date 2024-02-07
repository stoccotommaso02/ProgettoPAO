#include "TemperatureSensor.h"

TemperatureSensor* TemperatureSensor:: clone() const {
	return new TemperatureSensor(*this);
}

void TemperatureSensor::accept(SensorVisitor& v){
  v.visit(*this);
}

Reading* TemperatureSensor::simulate(const QString& name, int numEntries) const{
  return nullptr;
}