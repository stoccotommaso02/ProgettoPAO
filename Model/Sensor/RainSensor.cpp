#include "RainSensor.h"

RainSensor* RainSensor::clone() const {
	return new RainSensor(*this);
};

void RainSensor::accept(SensorVisitor& v){
  v.visit(*this);
}