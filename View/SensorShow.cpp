#include "SensorShow.h"

SensorShow::SensorShow(BaseSensor* s, QWidget* parent):QWidget(parent), sensor(s){
	sensor
  QHBoxLayout* box= new QHBoxLayout(this);
	QVBoxLayout* b1= new QVBoxLayout();
	QVBoxLayout* b2= new QVBoxLayout();
	QHBoxLayout* b2_2= new QHBoxLayout();
	type_image = new QLabel("on");
	sensor_name=new QLabel();
	sensor_id=new QLabel();
	sensor_type=new QLabel();
	range_id=new QLabel();
	min_range= new QDoubleSpinBox();
	max_range= new QDoubleSpinBox();
	simulate = new QPushButton("Gather Data");
	box->setAlignment(Qt::AlignCenter);
	box->insertWidget(0,type_image);
	b1->setAlignment(Qt::AlignLeft | Qt:: AlignTop);
	b1->addWidget(sensor_name);
	b1->addStretch();
	b1->addWidget(sensor_id);
	b1->addWidget(sensor_type);
	b2_2->setAlignment(Qt::AlignCenter);
	b2_2->addWidget(min_range);
	b2_2->addWidget(max_range);
	b2->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
	b2->addWidget(range_id);
	b2->addLayout(b2_2);
	box->addLayout(b1);
	box->addLayout(b2);
	box->addWidget(simulate);
};

void SensorShow::refresh(){
	sensor_name->setText("Name:" + sensor->getName());
	sensor_id->setText( "Id:" + QString::number(sensor->getId()));
	TypeSensorVisitor v;
	sensor->accept(v);
	sensor_type->setText("Type:" + v.getType());
	range_id->setText("Choose the values range:");
	min_range->value();
	max_range->value();
};

void SensorShow::update(){
	refresh();
	QWidget::update();
}