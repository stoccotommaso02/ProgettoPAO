#include"ReadingDisplayWidget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>

ReadingDisplayWidget::ReadingDisplayWidget(ReadingTable* table, QWidget* parent): QWidget(parent){
  chart = new ReadingChart();
  chart_view = new ChartView(chart);
  buttons = new RemoveButtonWidget();
  reading_table = table;
  reading_table->attach(this);
  QWidget* buttons= new QWidget();
  QVBoxLayout* vbox = new QVBoxLayout(this);
  QScrollArea* scroll_area = new QScrollArea;
  scroll_area->setWidget(buttons);
  vbox->addWidget(chart_view);
  vbox->addWidget(scroll_area);
  vbox->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

ReadingTable* ReadingDisplayWidget::getReadingTable() const{
  return reading_table;
}

void ReadingDisplayWidget::observerUpdate(){
  for(Reading* r : reading_table->getTable()){
    if(!chart->QMap::contains(r)){
      chart->addReading(r);
      buttons->addButton(r);
    }
  }
  for(Reading* r : chart->keys()){
    if(!reading_table->contains(r)){
      chart->removeReading(r);
      buttons->removeButton(r);
    }
  }
  show();
}

void ReadingDisplayWidget::removeReading(Reading* r){
  chart->removeReading(r);
  buttons->removeButton(r);
}

void ReadingDisplayWidget::highlightReading(Reading* r){
  if(reading_table->contains(r))
    emit readingcontained(this);
}