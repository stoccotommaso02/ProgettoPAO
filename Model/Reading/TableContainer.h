#ifndef TABLECONTAINER_H
#define TABLECONTAINER_H
#include<QList>
#include"../Observer.h"
#include"ReadingVisitor.h"
#include"ReadingTable.h"

class TableContainer{
private:
  static TableContainer* instance;
  TableContainer();
  QList<ReadingTable*> tables;

  class Sorter : public ReadingVisitor{
  public:
  virtual void visit(RainReading&) override;
  virtual void visit(HumidityReading&) override;
  virtual void visit(WindReading&) override;
  virtual void visit(TemperatureReading&) override;
  virtual void visit(DustReading&) override;
  };
  friend class Sorter;
public:
  static TableContainer* tablecontainer();
  void insertReading(Reading* reading);
  void removeReading(Reading* reading);
  ReadingTable* getTable(int index) const;
};

#endif