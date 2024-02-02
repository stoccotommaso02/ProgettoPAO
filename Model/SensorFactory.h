#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H
#include<QString>
#include<QMap>
#include"SampleSensor.h"

class SensorFactory{
  typedef BaseSensor* (*constructSensor)(const QString&);
private:
  static QMap<QString, constructSensor> type_map;
public:
  static QStringList concrete_sensor_types;
  static void registerType(const QString& typekey, constructSensor constructor);
  static BaseSensor* createSensor(const QString& name, const QString& type);
};


struct TypeRegistrar{
  TypeRegistrar();
};

#endif