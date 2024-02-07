#ifndef W_SENSOR_H
#define W_SENSOR_H
#include "baseSensor.h"

class WindSensor: public BaseSensor{
public:
  WindSensor(const QString& n): BaseSensor(n) {};
  WindSensor(const QString& n, int i): BaseSensor(n,i) {};
  virtual Reading* simulate(const QString& name, int entries) const override;
  virtual WindSensor* clone() const override;
  virtual void accept(SensorVisitor& visitor) override;
};
#endif