#include"ReadingTable.h"

ReadingTable::~ReadingTable(){
  for(Reading* r : table){
    r->detach(this);
  }
};

Reading* ReadingTable::getReading(const QModelIndex& index) const{
  if(!index.isValid())
    return nullptr;
  return table.at(index.row());
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
  if(role != Qt::DisplayRole || !index.isValid())
    return QVariant();
  if(index.row() < 0 || index.row() > table.count())
    return QVariant();
  Reading* r = table.at(index.row());
  if(index.column() >= r->getSize())
    return QVariant();
  return r->getValue(index.column());
}

QVariant ReadingTable::headerData(int section, Qt::Orientation orientation, int role) const{
  if(role != Qt::DisplayRole)
    return QVariant();
  if(orientation == Qt::Horizontal && section >= 0)
    return QVariant(QString::number(section));
  if(orientation == Qt::Vertical && section >= 0)
    return QVariant(table.at(section)->getName());
  return QVariant();
}

bool ReadingTable::setData(const QModelIndex& index, const QVariant& value, int role){
  Q_UNUSED(value); Q_UNUSED(role);
  emit dataChanged(index, index);
  return false;
}

bool ReadingTable::setHeaderData(int section, Qt::Orientation orientation, const QVariant& value, int role){
  if(orientation == Qt::Horizontal || role != Qt::EditRole)
    return false;
  if(section < table.count()){
    table.at(section)->setName(value.toString());
    emit headerDataChanged(orientation, section, section);
    return true;
  }
  return false;
}

Qt::ItemFlags ReadingTable::flags(const QModelIndex& index) const{
  Q_UNUSED(index);
  return (Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}

void ReadingTable::append(Reading* reading){
  if(table.contains(reading) || reading == nullptr)
    return;
  reading->attach(this);
  beginInsertRows(QModelIndex(), table.size(), table.size());
  int size = reading->getSize();
  if(size > max_entries){
    beginInsertColumns(QModelIndex(), max_entries, size-1);
    table.append(reading);
    endInsertColumns();
  }
  else{
    table.append(reading);
  }
  endInsertRows();
  notify();
}

void ReadingTable::remove(Reading* reading){
  beginRemoveRows(QModelIndex(), table.indexOf(reading), table.indexOf(reading));
  table.removeAll(reading);
  endRemoveRows();
  reading->detach(this);
  notify();
}

void ReadingTable::remove(const QModelIndex& index){
  remove(getReading(index));
}

bool ReadingTable::contains(Reading* reading) const{
  return table.contains(reading);
}

int ReadingTable::row(Reading* r) const{
  if(contains(r))
    return table.indexOf(r);
  return table.size();
}

void ReadingTable::observerUpdate(){
  notify();
}


const QList<Reading*> ReadingTable::getTable() const{
  return table;
}