#ifndef READINGTABLE_H
#define READINGTABLE_H
#include<QVariant>
#include<QList>
#include"../Observer.h"
#include"../Subject.h"
#include"Reading.h"
#include"ReadingSeries.h"

class ReadingTable : public Observer, public Subject{
private:
  QList<Reading*> table;
public:
  ReadingTable(){};
  virtual ~ReadingTable();
  Reading* getReading(const QModelIndex& index) const;
  void append(Reading* reading);
  void remove(Reading* reading);
  void remove(const QModelIndex& index);
  bool contains(Reading*) const;
  int row(Reading*) const;
  virtual void observerUpdate() override;
  QList<Reading*> getTable() const;
};

#endif