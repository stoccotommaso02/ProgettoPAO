#ifndef R_SENSOR_H
#define R_SENSOR_H
#include"BaseSensor.h"

class RainSensor: public BaseSensor{
public:
  RainSensor(const QString& n): BaseSensor(n) {};
  RainSensor(const QString& n, int i): BaseSensor(n,i) {};
  virtual Reading* simulate(const QString& name, int entries) const override;
  virtual RainSensor* clone() const override;
  virtual void accept(SensorVisitor& visitor) override;
};
#endif