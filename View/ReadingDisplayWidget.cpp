#include"ReadingDisplayWidget.h"
#include<QVBoxLayout>

ReadingDisplayWidget::ReadingDisplayWidget(ReadingTable* table, QWidget* parent): QWidget(parent){
  tabs = new QTabWidget();
  reading_table = table;
  reading_table->attach(this);
  QWidget* table_button = new QWidget();
  QVBoxLayout* vbox = new QVBoxLayout(table_button);
  table_view = new QTableView();
  chart_view = new QChartView();
  remove_reading = new QPushButton("Remove Reading");
  vbox->addWidget(table_view);
  vbox->addWidget(remove_reading);
  vbox->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  tabs->addTab(table_button, "Table");
  tabs->addTab(chart_view, "Chart");

  connect(remove_reading, &QPushButton::clicked, this, &ReadingDisplayWidget::removeReading);
}

void ReadingDisplayWidget::removeReading(){
  reading_table->remove(table_view->selectionModel()->currentIndex());
}

void ReadingDisplayWidget::highlightReading(Reading* r){
  if(reading_table->contains(r)){
    int row = reading_table->row(r);
    tabs->setCurrentWidget(table_view);
    table_view->selectionModel()->select((row == reading_table->rowCount())? QModelIndex() : reading_table->index(row, 0, QModelIndex()), QItemSelectionModel::ClearAndSelect);
    emit readingcontained(this);
  }
}

void ReadingDisplayWidget::update(){
  QWidget::update();
}