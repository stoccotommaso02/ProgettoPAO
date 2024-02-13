#include"TableContainer.h"
#include"ReadingTable.h"
#include"DustReading.h"
#include"HumidityReading.h"
#include"TemperatureReading.h"
#include"WindReading.h"
#include"RainReading.h"

TableContainer* TableContainer::instance = nullptr;

TableContainer::TableContainer(){
  tables.resize(5, new ReadingTable());
}

void TableContainer::Sorter::visit(TemperatureReading& r){
  tablecontainer()->tables.at(0)->append(&r);
}

void TableContainer::Sorter::visit(RainReading& r){
  tablecontainer()->tables.at(1)->append(&r);
}

void TableContainer::Sorter::visit(HumidityReading& r){
  tablecontainer()->tables.at(2)->append(&r);
}

void TableContainer::Sorter::visit(WindReading& r){
  tablecontainer()->tables.at(3)->append(&r);
}

void TableContainer::Sorter::visit(DustReading& r){
  tablecontainer()->tables.at(4)->append(&r);
}

void TableContainer::insertReading(Reading* r){
  Sorter s;
  r->accept(s);
}

void TableContainer::removeReading(Reading* r){
  for(ReadingTable* table : tables){
    table->remove(r);
  }
}

TableContainer* TableContainer::tablecontainer(){
  if(instance == nullptr)
    instance = new TableContainer();
  return instance;
}

ReadingTable* TableContainer::getTable(int index) const{
  if(index < 0 || index >= tables.size())
    return nullptr;
  return tables.at(index);
}