#include"ReadingTable.h"

ReadingTable::~ReadingTable(){
  for(Reading* r : table){
    r->detach(this);
  }
};

void ReadingTable::append(Reading* reading){
  if(table.contains(reading) || reading == nullptr)
    return;
  reading->attach(this);
  table.append(reading);

  notify();
}

void ReadingTable::remove(Reading* reading){
  table.removeAll(reading);
  reading->detach(this);
  notify();
}

bool ReadingTable::contains(Reading* reading) const{
  return table.contains(reading);
}

int ReadingTable::row(Reading* r) const{
  if(contains(r))
    return table.indexOf(r);
  return table.size();
}

void ReadingTable::observerUpdate(){
  notify();
}

QList<Reading*> ReadingTable::getTable() const{
  return table;
}