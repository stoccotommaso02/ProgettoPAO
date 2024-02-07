#include "DustSensor.h"

Reading* DustSensor::simulate(const QString& name, int entries) const{

};

DustSensor* DustSensor:: clone() const {
	return new DustSensor(*this);
}

void DustSensor::accept(SensorVisitor& v){
  v.visit(*this);
}