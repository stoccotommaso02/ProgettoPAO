#ifndef H_SENSOR_H
#define H_SENSOR_H
#include"BaseSensor.h"

class HumiditySensor: public BaseSensor{
public:
  HumiditySensor(QString n): BaseSensor(n) {};
  HumiditySensor(const QString& n, int i): BaseSensor(n,i) {};
  virtual Reading* simulate(const QString& name, int entries) const override;
  virtual HumiditySensor* clone() const;
  virtual void accept(SensorVisitor& visitor);
};
#endif