#ifndef FILTEREDLIST_H
#define FILTEREDLIST_H
#include<QList>
#include<QAbstractTableModel>
#include"Reading.h"

class FilteredList : public QAbstractTableModel{
  Q_OBJECT
private:
  const int id;
  QList<Reading*>* list;
public:
  FilteredList(int i, QList<Reading*>* l);
  ~FilteredList();
  virtual int rowCount(const QModelIndex& parent =QModelIndex()) const override;
  virtual int columnCount(const QModelIndex& parent =QModelIndex()) const override;
  virtual QVariant data(const QModelIndex& index, int role =Qt::DisplayRole) const override;
  virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
  virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
  virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
};

#endif