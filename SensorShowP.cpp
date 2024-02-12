#include "View/SensorShow.h"

SensorShow::SensorShow(BaseSensor* s, QWidget* parent): QWidget(parent){
  QHBoxLayout* box= new QHBoxLayout(this);
	QVBoxLayout* b1= new QVBoxLayout();
	QVBoxLayout* b2= new QVBoxLayout();
	QHBoxLayout* b2_2= new QHBoxLayout();
	QVBoxLayout* b3= new QVBoxLayout();
	type_image = new QLabel();
	sensor_name=new QLabel();
	sensor_id=new QLabel();
	sensor_type=new QLabel();
	range_id=new QLabel();
	min_range= new QDoubleSpinBox();
	max_range= new QDoubleSpinBox();
	change= new QPushButton("Change Name");
	simulate = new QPushButton("Gather Data");
	box->setAlignment(Qt::AlignCenter);
	box->insertWidget(0,type_image);

	b1->setAlignment(Qt::AlignLeft | Qt:: AlignTop);
	b1->addWidget(sensor_name);
	b1->addWidget(sensor_id);
	b1->addWidget(sensor_type);

	b2_2->setAlignment(Qt::AlignCenter);
	b2_2->addWidget(min_range);
	b2_2->addWidget(max_range);

	b2->setAlignment(Qt::AlignLeft | Qt::AlignBottom);
	b2->addWidget(range_id);
	b2->addLayout(b2_2);

	b3->setAlignment(Qt::AlignCenter);
	b3->addWidget(change);
	b3->addWidget(simulate);
	box->addLayout(b1);
	box->addLayout(b2);
	box->addLayout(b3);

	connect(change, &QPushButton::clicked, this, &SensorShow::ChangeName);
	connect(simulate, &QPushButton::clicked, this, &SensorShow::GatherData);
	connect(min_range, &QDoubleSpinBox::valueChanged, this, &SensorShow::setMin);
	connect(max_range, &QDoubleSpinBox::valueChanged, this, &SensorShow::setMax);
};

void SensorShow:: refresh(){
	SensorShowVisitor visitor;
	sensor->accept(visitor);
	type_image->setPixmap(visitor.getIcon());
	sensor_name->setText("Name:" + sensor->getName());
	sensor_id->setText( "Id:" + QString::number(sensor->getId()));
	sensor_type->setText("Type:" + sensor->getType());
	range_id->setText("Choose the values range:");
	min_range->setValue(sensor->getCurrMin());
	max_range->setValue(sensor->getCurrMax());
	change->setEnabled(true);
	simulate->setEnabled(true);
	(*this).show();
};

void SensorShow::ChangeName(){
	bool ok;
	QString name = QInputDialog::getText(this, "Change Name", "Write the desired name:", QLineEdit::Normal,"",&ok);
	if (!ok) return;
	sensor->setName(name);
	refresh();
}

Reading* SensorShow::GatherData(){
  bool ok;
  QString name = QInputDialog::getText(this, "Gather Data", "Choose a name for the reading:", QLineEdit::Normal,"",&ok);
  if(!ok) return;
  unsigned int entry= QInputDialog::getInt(this, "Gather Data", "Select the desired amount of data gathered:", 0,0,31,1,&ok);
  if(!ok) return;
  sensor->simulate(name, entry);
	refresh();
};

void SensorShow::setMin(){
	sensor->setMin(min_range->value());
	min_range->textFromValue(sensor->getCurrMin());
};

void SensorShow::setMax(){
	sensor->setMax(max_range->value());
	max_range->textFromValue(sensor->getCurrMax());
};