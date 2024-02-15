#include"ReadingDisplayWidget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
ReadingDisplayWidget::ReadingDisplayWidget(ReadingTable* table, QWidget* parent): QWidget(parent){
  tabs = new QTabWidget();
  QHBoxLayout* hbox = new QHBoxLayout(this);
  hbox->addWidget(tabs);
  reading_table = table;
  reading_table->attach(this);
  chart = new ReadingChart();
  QWidget* table_button = new QWidget();
  QVBoxLayout* vbox = new QVBoxLayout(table_button);
  table_view = new QTableView();
  table_view->setModel(table);
  chart_view = new ChartView(chart);
  remove_reading = new QPushButton("Remove Reading");
  vbox->addWidget(table_view);
  vbox->addWidget(remove_reading);
  vbox->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  tabs->addTab(table_button, "Table");
  tabs->addTab(chart_view, "Chart");

  connect(remove_reading, &QPushButton::clicked, this, &ReadingDisplayWidget::removeReading);
}

ReadingTable* ReadingDisplayWidget::getReadingTable() const{
  return reading_table;
}

void ReadingDisplayWidget::removeReading(){
  QModelIndex index = table_view->selectionModel()->currentIndex();
  if(!index.isValid())
    return;
  Reading* removed = reading_table->getReading(index);
  chart->removeReading(removed);
  reading_table->remove(removed);
}

void ReadingDisplayWidget::highlightReading(Reading* r){
  if(reading_table->contains(r)){
    int row = reading_table->row(r);
    tabs->setCurrentWidget(table_view);
    table_view->selectionModel()->select((row == reading_table->rowCount())? QModelIndex() : reading_table->index(row, 0, QModelIndex()), QItemSelectionModel::ClearAndSelect);
    emit readingcontained(this);
  }
}

void ReadingDisplayWidget::observerUpdate(){
  QWidget::update();
  for(Reading* r : reading_table->getTable()){
    if(!chart->QMap::contains(r)){
      chart->addReading(r);
    }
  }
  for(Reading* r : chart->keys()){
    if(!reading_table->contains(r))
      chart->removeReading(r);
  }
}