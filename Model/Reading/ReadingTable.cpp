#include"ReadingTable.h"
/*class ReadingTable : public QAbstractTableModel{
private:
  ReadingTable(): max_entries(0){};
  QList<Reading*> table;
  int max_entries;
public:
  static ReadingTable* addTable();
  virtual ~ReadingTable();
  virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;
  virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;
  virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
  virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
  void append(Reading* reading);
  void remove(Reading* reading);
  void remove(int position);
};*/
ReadingTable::~ReadingTable(){};

Reading* ReadingTable::getReading(const QModelIndex& index) const{
  if(!index.isValid())
    return nullptr;
  return table.at(index.row());
}

ReadingTable* ReadingTable::addTable(){
  return new ReadingTable();
}

int ReadingTable::rowCount(const QModelIndex& parent) const{
  Q_UNUSED(parent);
  return table.count();  
}

int ReadingTable::columnCount(const QModelIndex& parent) const{
  Q_UNUSED(parent);
  return max_entries;
}

QVariant ReadingTable::data(const QModelIndex& index, int role) const{
  if(!index.isValid() || role != Qt::DisplayRole)
    return QVariant();
  Reading* r = getReading(index);
  if(index.column() > r->getSize())
    return QVariant();
  return r->getValue(index.column());
}

QVariant ReadingTable::headerData(int section, Qt::Orientation orientation, int role) const{
  if(role != Qt::DisplayRole)
    return QVariant();
  if(orientation == Qt::Horizontal && section > 0 && section < columnCount())
    return section;
  if(orientation == Qt::Vertical && section > 0 && section < rowCount())
    return table.at(section)->getName();
  return QVariant();
}

void ReadingTable::append(Reading* reading){
  beginInsertRows(QModelIndex(), rowCount(), rowCount());
  int size = reading->getSize();
  if(size > max_entries){
    beginInsertColumns(QModelIndex(), max_entries, size-1);
    table.append(reading);
    endInsertColumns;
  }
  else{
    table.append(reading);
  }
  endInsertRows();
}