#include<random>
#include"RainSensor.h"
#include"../Reading/RainReading.h"

const unsigned int RainSensor::absolute_max = 40;
const unsigned int RainSensor::absolute_min = 0;

RainSensor* RainSensor::clone() const {
	return new RainSensor(*this);
};

void RainSensor::accept(SensorVisitor& v){
  v.visit(*this);
}

Reading* RainSensor::simulate(const QString& name, int numEntries) const{
  QList<double>* result = new QList<double>();
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_int_distribution<unsigned int> dis(min, max);
  for(int i=0; i < numEntries; i++){
    result->append(dis(gen));
  }
  return new RainReading(name, result);
}

bool RainSensor::setMax(double d){
  if(d < 0)
    return false;
  unsigned int i =(unsigned int) d;
  if(i >= min && i <= absolute_max){
    max = i;
    return true;
  }
  return false;
}

bool RainSensor::setMin(double d){
  if(d < 0)
    return false;
  unsigned int i = (unsigned int)d;
  if(i <= max && i >= absolute_min){
    min = i;
    return true;
  }
  return false;
}

bool RainSensor::setMinMax(double low, double high){
  if(low < 0 || high < 0)
    return false;
  unsigned int newmin =(unsigned int) low;
  unsigned int newmax =(unsigned int) high;
  if(newmin <= newmax && newmin >= absolute_min && newmax <= absolute_max){
    min = newmin;
    max = newmax;
    return true;
  }
  return false;
}

double RainSensor::getMin() const{
  return min;
}

double RainSensor::getMax() const{
  return max;
}