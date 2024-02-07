#ifndef T_SENSOR_H
#define T_SENSOR_H
#include"BaseSensor.h"

class TemperatureSensor: public BaseSensor{
public:
  TemperatureSensor(const QString& n): BaseSensor(n) {};
  TemperatureSensor(const QString& n, int i): BaseSensor(n,i) {};
  virtual Reading* simulate(const QString& name, int entries) const override;
  virtual TemperatureSensor* clone() const override;
  virtual void accept(SensorVisitor&) override;
};
#endif