QT += core widgets
CONFIG += debug

TARGET = SampleSensor

HEADERS +=  Model/Sensor/SensorFactory.h \
            Model/Sensor/BaseSensor.h \
            Model/Sensor/RainSensor.h \
            Model/Sensor/TemperatureSensor.h \
            Model/Sensor/HumiditySensor.h \
            Model/Sensor/DustSensor.h \
            Model/Sensor/WindSensor.h \
            Model/Sensor/SensorVisitor.h
            Model/Sensor/TypeSensorVisitor.h \
            Model/Reading/Reading.h \
            Model/Reading/HumidityReading.h \
            Model/Reading/TemperatureReading.h \
            Model/Reading/WindReading.h \
            Model/Reading/DustReading.h \
            Model/Reading/RainReading.h \
            Model/TypeRegistrar.h \
            View/SensorShow.h

SOURCES +=  Model/Sensor/SensorFactory.cpp \
            Model/Sensor/BaseSensor.cpp \
            Model/Sensor/HumiditySensor.cpp \
            Model/Sensor/TemperatureSensor.cpp \
            Model/Sensor/RainSensor.cpp \
            Model/Sensor/DustSensor.cpp \
            Model/Sensor/WindSensor.cpp \
            Model/Sensor/TypeSensorVisitor.cpp \
            Model/Reading/Reading.cpp \
            Model/Reading/HumidityReading.cpp \
            Model/Reading/TemperatureReading.cpp \
            Model/Reading/RainReading.cpp \
            Model/Reading/WindReading.cpp \
            Model/Reading/DustReading.cpp \
            Model/TypeRegistrar.cpp \
            View/SensorShow.cpp \
            newmain.cpp