#include"WindSensor.h"

WindSensor* WindSensor::clone() const {
	return new WindSensor(*this);
}

void WindSensor::accept(SensorVisitor& v){
  v.visit(*this);
}