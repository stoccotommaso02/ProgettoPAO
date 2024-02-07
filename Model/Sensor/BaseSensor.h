#ifndef B_SENSOR_H
#define B_SENSOR_H
#include<QString>
#include"SensorVisitor.h"
#include"../Reading/Reading.h"

class BaseSensor{
private:
  static int counter;
  QString name;
  const int id;
protected:
  BaseSensor(const QString& n): name(n), id(++counter) {};
  BaseSensor(const BaseSensor& b): name(b.name), id(++counter) {};
  BaseSensor(const QString& n, int i);
public:
  QString getName() const;
  void setName(QString s);
  int getId() const;
  virtual Reading* simulate(const QString& name, int entries) const =0;
  virtual BaseSensor* clone() const =0;
  virtual ~BaseSensor() =default;
  virtual void accept(SensorVisitor& visitor) =0;
};

#endif