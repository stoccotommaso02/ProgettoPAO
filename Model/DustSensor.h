#ifndef D_SENSOR_H
#define D_SENSOR_H
#include"BaseSensor.h"


class DustSensor : public BaseSensor{
public:
DustSensor(QString n): BaseSensor(n) {};
virtual Reading* simulate(const Settings& setting) const;
virtual QString getType() const;
virtual DustSensor* clone() const;
};


#endif