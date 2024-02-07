#include "HumiditySensor.h"

Reading* HumiditySensor::simulate(const QString& name, int entries) const{

};

HumiditySensor* HumiditySensor:: clone() const {
	return new HumiditySensor(*this);
};

void HumiditySensor::accept(SensorVisitor& v){
  v.visit(*this);
}