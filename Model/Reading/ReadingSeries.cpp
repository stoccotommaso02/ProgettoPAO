#include"ReadingSeries.h"
#include"Reading.h"

ReadingSeries::ReadingSeries(Reading* const r): reading(r){
  reading->attach(this);
}

ReadingSeries::~ReadingSeries(){
  reading->detach(this);
}

void ReadingSeries::update(){
  setName(reading->getName());
  notify();
}