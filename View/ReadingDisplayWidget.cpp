#include"ReadingDisplayWidget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>

ReadingDisplayWidget::ReadingDisplayWidget(ReadingTable* table, QWidget* parent): QWidget(parent){
  chart = new ReadingChart();
  chart_view = new ChartView(chart);
  reading_table = table;
  reading_table->attach(this);
  QVBoxLayout* vbox = new QVBoxLayout(this);
  vbox->addWidget(chart_view);
  vbox->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

ReadingTable* ReadingDisplayWidget::getReadingTable() const{
  return reading_table;
}

void ReadingDisplayWidget::observerUpdate(){
  for(Reading* r : reading_table->getTable()){
    if(!chart->QMap::contains(r)){
      chart->addReading(r);
    }
  }
  for(Reading* r : chart->keys()){
    if(!reading_table->contains(r)){
      chart->removeReading(r);
    }
  }
  show();
}