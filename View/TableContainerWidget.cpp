#include"TableContainerWidget.h"

TableContainerWidget::TableContainerWidget(TableContainer* tc, QWidget* parent): QWidget(parent), tablecontainer(tc){
  tabs = new QTabWidget();
  for(int i=0; i < 5; i++){
    displays.append(new ReadingDisplayWidget(tablecontainer->getTable(i)));
  }
  tabs->addTab(displays.at(0), "Temperature");
  tabs->addTab(displays.at(1), "Rain");
  tabs->addTab(displays.at(2), "Humidity");
  tabs->addTab(displays.at(3), "Wind");
  tabs->addTab(displays.at(4), "Dust");

  for(ReadingDisplayWidget* displaywidget : displays){
    connect(this, &TableContainerWidget::searchReading, displaywidget, &ReadingDisplayWidget::highlightReading);
    connect(displaywidget, &ReadingDisplayWidget::readingcontained, this, &TableContainerWidget::changeTab);
  }
}

void TableContainerWidget::highlightReading(Reading* r){
  emit searchReading(r);
}

void TableContainerWidget::changeTab(ReadingDisplayWidget* const widget){
  tabs->setCurrentWidget(widget);
}