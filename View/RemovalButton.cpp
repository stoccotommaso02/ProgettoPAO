#include"RemovalButton.h"

RemovalButton::RemovalButton(Reading* r, QWidget* parent):QPushButton(parent){
  reading=r;
  reading->attach(this);
  setText("Delete" + reading->getName());
  connect(this,&QPushButton::clicked,this,&RemovalButton::remove);
}

RemovalButton::~RemovalButton(){
  reading->detach(this);
}

void RemovalButton::observerUpdate() {
  setText("Delete" + reading->getName());
}

void RemovalButton::remove(){
  emit deleteclicked(reading);
}