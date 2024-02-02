#ifndef SAMPLESENSOR_H
#define SAMPLESENSOR_H
#include"BaseSensor.h"
#include"SampleReading.h"

class SampleSensor : public BaseSensor{
public:
  SampleSensor(const QString& name): BaseSensor(name){};

  virtual SampleReading* simulate(const Settings& setting) const override{
    return new SampleReading();
  };
  virtual QString getType() const override{
    return QString("SampleType");
  };
  virtual SampleSensor* clone() const override{
    return new SampleSensor(*this);
  };
};

#endif