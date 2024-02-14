#include"TableContainerWidget.h"

TableContainerWidget::TableContainerWidget(TableContainer* tc, QWidget* parent): QWidget(parent), tablecontainer(tc){
  tablecontainer->attach(this);
  tabs = new QTabWidget();

}

void TableContainerWidget::highlightReading(Reading* r){
  emit searchReading(r);
}

void TableContainerWidget::changeTab(ReadingDisplayWidget* const widget){
  tabs->setCurrentWidget(widget);
}

void TableContainerWidget::update(){
  int count = tablecontainer->count();
  for(int i=0; i < count; i++){
    bool found = false;
    for(ReadingDisplayWidget* display : displays){
      if(display->getReadingTable() == tablecontainer->getTable(i)){
        found = true;
        break;
      };
    }
    if(!found){
      ReadingTable* newtable = tablecontainer->getTable(i);
      addNewTable(tablecontainer->getKey(newtable), newtable);
    }
  }
  QWidget::update();
}

void TableContainerWidget::addNewTable(const QString& type, ReadingTable* table){
  displays.append(new ReadingDisplayWidget(table));
  displays.last(); // SLOT & CONNECT & SHIET
  tabs->addTab(displays.last(), type);
}