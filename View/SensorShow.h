#ifndef SENSOR_SHOW_H
#define SENSOR_SHOW_H
#include<QWidget>
#include<QLabel>
#include<QPushButton>
#include<QDoubleSpinBox>
#include<QHBoxLayout>
#include"Model/Sensor/BaseSensor.h"
#include"Model/Sensor/TypeSensorVisitor.h"

class SensorShow: public QWidget {
  Q_OBJECT
private:
	BaseSensor* sensor;
	QLabel* sensor_name;
	QLabel* sensor_id;
	QLabel* sensor_type;
	QLabel* type_image;
	QLabel* range_id;
	QPushButton* simulate;
	QDoubleSpinBox* min_range;
	QDoubleSpinBox* max_range;
public:
	SensorShow(BaseSensor* s, QWidget* parent);
	void show();
	void refresh();
};

#endif