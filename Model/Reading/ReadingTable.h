#ifndef READINGTABLE_H
#define READINGTABLE_H
#include<QVariant>
#include<QList>
#include<QAbstractTableModel>
#include"../Observer.h"
#include"../Subject.h"
#include"Reading.h"
#include"ReadingSeries.h"

class ReadingTable : public QAbstractTableModel, public Observer, public Subject{
private:
  QList<Reading*> table;
  int max_entries;
public:
  ReadingTable(): max_entries(0){};
  virtual ~ReadingTable();
  virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
  virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
  virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
  virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
  virtual bool setHeaderData(int section, Qt::Orientation orientation, const QVariant& value, int role = Qt::EditRole);
  Qt::ItemFlags flags(const QModelIndex& index) const;
  Reading* getReading(const QModelIndex& index) const;
  void append(Reading* reading);
  void remove(Reading* reading);
  void remove(const QModelIndex& index);
  bool contains(Reading*) const;
  int row(Reading*) const;
  virtual void observerUpdate() override;
  const QList<Reading*> getTable() const;
};

#endif