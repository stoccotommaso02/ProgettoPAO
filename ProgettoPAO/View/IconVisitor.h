#ifndef ICONVISITOR_H
#define ICONVISITOR_H
#include<QPixmap>
#include<QSizePolicy>
#include"Model/Sensor/SensorVisitor.h"
#include"Model/Reading/ReadingVisitor.h"

class IconVisitor : public SensorVisitor, public ReadingVisitor{
private:
  QPixmap icon;
public:
  QPixmap getIcon() const;
  virtual void visit(const DustSensor&) override;
  virtual void visit(const RainSensor&) override;
  virtual void visit(const TemperatureSensor&) override;
  virtual void visit(const WindSensor&) override;
  virtual void visit(const HumiditySensor&) override;
  virtual void visit(const DustReading&) override;
  virtual void visit(const RainReading&) override;
  virtual void visit(const TemperatureReading&) override;
  virtual void visit(const WindReading&) override;
  virtual void visit(const HumidityReading&) override;
};

#endif