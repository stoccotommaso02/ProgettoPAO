#ifndef READINGTABLE_h
#define READINGTABLE_H
#include<QVariant>
#include<QList>
#include<QAbstractTableModel>
#include"Reading.h"

class ReadingTable : public QAbstractTableModel{
private:
  ReadingTable(): max_entries(0){};
  QList<Reading*> table;
  int max_entries;
  Reading* getReading(const QModelIndex& index) const;
public:
  static ReadingTable* addTable();
  virtual ~ReadingTable();
  virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
  virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
  virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
  void append(Reading* reading);
  void remove(Reading* reading);
  void remove(const QModelIndex& index);
};

#endif