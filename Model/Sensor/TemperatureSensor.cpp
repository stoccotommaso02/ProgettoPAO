#include "TemperatureSensor.h"

Reading* TemperatureSensor::simulate(const QString& name, int entries) const {};

TemperatureSensor* TemperatureSensor:: clone() const {
	return new TemperatureSensor(*this);
}

void TemperatureSensor::accept(SensorVisitor& v){
  v.visit(*this);
}