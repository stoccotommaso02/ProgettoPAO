#include"SensorFactory.h"

/*class SensorCreator{
  typedef BaseSensor* (*constructSensor)(QString);
private:
  static QMap<QString, constructSensor> type_map;
public:
  static const QStringList concrete_sensor_types;
  static BaseSensor* createSensor(QString name, QString type);
};*/

QMap<QString, SensorFactory::constructSensor> SensorFactory::type_map;
QStringList SensorFactory::concrete_sensor_types;

void SensorFactory::registerType(const QString& typekey, constructSensor constructor){
  type_map.insert(typekey, constructor);
  concrete_sensor_types.append(typekey);
}

BaseSensor* SensorFactory::createSensor(const QString& name, const QString& type){
  QMap<QString, constructSensor>::iterator it =type_map.find(type);
  if(it == type_map.end())
    return nullptr;
  return (it.value())(name);
};

TypeRegistrar::TypeRegistrar(){
  SensorFactory::registerType("Sample", [](const QString& name)->BaseSensor*{return new SampleSensor(name);});
}