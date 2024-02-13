#include"FilteredList.h"
#include"ReadingList.h"

FilteredList::FilteredList(int i, QList<Reading*>* l): id(i), list(l){};

FilteredList::~FilteredList(){
  delete list;
}

int FilteredList::rowCount(const QModelIndex& parent) const{
  Q_UNUSED(parent);
  return list->count();
}

int FilteredList::columnCount(const QModelIndex& parent) const{
  Q_UNUSED(parent);
  return 3;
}

QVariant FilteredList::data(const QModelIndex& index, int role) const{
  if(!index.isValid())
    return QVariant();
  if(role != Qt::DisplayRole || role != Qt::EditRole)
    return QVariant();
  switch(index.column()){
    case 0:
      return list->at(index.row())->getName();
      break;
    case 1:
      return id;
      break;
    case 2:
      return list->at(index.row())->getSize();
      break;
    default:
      return QVariant();
  }
}

QVariant FilteredList::headerData(int section, Qt::Orientation orientation, int role) const{
  if(orientation != Qt::Horizontal || role != Qt::DisplayRole)
    return QVariant();
  switch(section){
    case 0:
      return QString("Name");
      break;
    case 1:
      return QString("Sensor ID");
      break;
    case 2:
      return QString("# of Entries");
      break;
    default:
      return QVariant();
      break;
  }
}

bool FilteredList::setData(const QModelIndex& index, const QVariant& value, int role){
  if(role != Qt::EditRole || index.column() != 0)
    return false;
  list->at(index.row())->setName(value.toString());
  emit dataChanged(index, index);
  return true;
}

Qt::ItemFlags FilteredList::flags(const QModelIndex& index) const{
  if(!index.isValid())
    return Qt::NoItemFlags;
  Qt::ItemFlags result;
  if(index.column() ==0)
    result.setFlag(Qt::ItemIsEditable);
  result.setFlag(Qt::ItemIsSelectable);
  result.setFlag(Qt::ItemIsEnabled);
  return result;
}
