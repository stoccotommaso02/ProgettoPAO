#ifndef SAMPLEREADING_H
#define SAMPLEREADING_H
#include"Reading.h"

class SampleReading : public Reading{
public:
  SampleReading() : Reading(QString("sample"), std::array<double, 24>()){};
  ~SampleReading() {};
};

#endif