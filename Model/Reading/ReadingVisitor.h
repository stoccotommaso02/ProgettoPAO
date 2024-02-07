#ifndef READINGVISITOR_H
#define READINGVISITOR_H

class DustReading;
class TemperatureReading;
class RainReading;
class HumidityReading;
class WindReading;

class ReadingVisitor{
public:
  virtual ~ReadingVisitor(){};
  virtual void visit(const DustReading&) =0;
  virtual void visit(const RainReading&) =0;
  virtual void visit(const TemperatureReading&) =0;
  virtual void visit(const WindReading&) =0;
  virtual void visit(const HumidityReading&) =0;
};

#endif