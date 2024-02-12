#ifndef SENSOR_SHOW_VISTOR_H
#define SENSOR_SHOW_VISTOR_H
#include "../Visitors/SensorVisitor.h"
#include "SensorShow.h"

class SensorShowVisitor: public SensorVisitor {
private: 
  QPixmap icon;
public: 
  QPixmap getIcon(); 
  virtual void visitSensorShow(SensorShow& s);
  virtual void visit(const DustSensor&) override;
  virtual void visit(const RainSensor&) override;
  virtual void visit(const TemperatureSensor&) override;
  virtual void visit(const WindSensor&) override;
  virtual void visit(const HumiditySensor&) override;
};

#endif