#ifndef B_SENSOR_H
#define B_SENSOR_H
#include<QString>
#include"Reading.h"
#include"Settings.h"

class BaseSensor{
private:
  static unsigned int counter;
  QString name;
  const unsigned int id;
protected:
  BaseSensor(QString n): name(n), id(++counter) {};
public:
  QString getName() const;
  void setName(QString s);
  unsigned int getId() const;
  virtual Reading* simulate(const Settings& setting) const =0;
  virtual QString getType() const =0;
  virtual BaseSensor* clone() const =0;
};

#endif