#ifndef T_SENSOR_H
#define T_SENSOR_H
#include"BaseSensor.h"

class TemperatureSensor: public BaseSensor{
private:
  static const double absolute_min;
  static const double absolute_max;
  double min;
  double max;
public:
  TemperatureSensor(const QString& n): BaseSensor(n), min(-5), max(40) {};
  TemperatureSensor(const QString& n, int i): BaseSensor(n,i), min(-5), max(40) {};
  virtual Reading* simulate(const QString& name, int entries) const override;
  virtual TemperatureSensor* clone() const override;
  virtual void accept(SensorVisitor&) override;
  virtual bool setMax(double d) override;
  virtual bool setMin(double d) override;
  virtual bool setMinMax(double low, double high) override;
  virtual double getMin() const override;
  virtual double getMax() const override;
  virtual double getAbsMin() const override;
  virtual double getAbsMax() const override;
};
#endif
