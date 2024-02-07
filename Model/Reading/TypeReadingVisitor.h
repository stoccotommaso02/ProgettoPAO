#ifndef TYPEREADINGVISITOR_H
#define TYPEREADINGVISITOR_H
#include<QString>
#include"ReadingVisitor.h"

class TypeReadingVisitor: public ReadingVisitor{
private:
  QString type_name;
public:
  virtual ~TypeReadingVisitor(){};
  virtual void visit(const DustReading&);
  virtual void visit(const RainReading&);
  virtual void visit(const TemperatureReading&);
  virtual void visit(const WindReading&);
  virtual void visit(const HumidityReading&);
  QString getType() const;
};

#endif