#include"RemoveButtonWidget.h"
#include<QHBoxLayout>

RemoveButtonWidget::RemoveButtonWidget(QWidget* parent): QWidget(parent){
  hbox = new QHBoxLayout(this);
  hbox->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  label = new QLabel("ciao");
  hbox->addWidget(label);
};

void RemoveButtonWidget::addButton(Reading* r){
  RemovalButton* button = new RemovalButton(r);
  connect(button, &RemovalButton::deleteclicked, this, &RemoveButtonWidget::buttonclicked);
  buttons.append(button);
  hbox->addWidget(button);
  show();
}

void RemoveButtonWidget::removeButton(Reading* r){
  auto it=buttons.begin();
  for(;it!=buttons.end();it++){
    if(r==(*it)->reading)
      break;
  }
  if(it!=buttons.end()){
    hbox->removeWidget(*it);
    delete(*it);
    buttons.erase(it);
  }
  show();
}

void RemoveButtonWidget::buttonclicked(Reading* r){
  emit toRemove(r);
}