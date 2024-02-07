#ifndef D_SENSOR_H
#define D_SENSOR_H
#include"BaseSensor.h"

class DustSensor: public BaseSensor{
public:
  DustSensor(const QString& n): BaseSensor(n) {};
  DustSensor(const QString& n, int i): BaseSensor(n,i) {};
  virtual Reading* simulate(const QString& name, int entries) const override;
  virtual DustSensor* clone() const override;
  virtual void accept(SensorVisitor& visitor) override;
};

#endif