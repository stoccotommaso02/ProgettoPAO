#ifndef READINGSERIS_H
#define READINGSERIES_H
#include<QLineSeries>
#include"../Observer.h"
#include"../Subject.h"

class Reading;

class ReadingSeries : public QLineSeries, public Observer, public Subject{
private:
 Reading* const reading;
public:
  ReadingSeries(Reading* const r);
  virtual ~ReadingSeries();
  virtual void update() override;
};

#endif