#include"Tree.h"
#include<utility>

Tree::~Tree(){
  removeRows(0, root->childCount(), QModelIndex());
  removeColumns(0, 3, QModelIndex());
}

TreeNode* Tree::getNode(const QModelIndex& index) const{
  if(index.isValid()){
    TreeNode* indexNode = static_cast<TreeNode*>(index.internalPointer());
    if(indexNode)
      return indexNode;
  }
  return root;
}

QModelIndex Tree::index(int row, int column, const QModelIndex& parent) const{
  if(parent.isValid() && parent.column() != 0)
    return QModelIndex();
  TreeNode* parentNode = getNode(parent);
  if(!parentNode)
    return QModelIndex();
  TreeNode* childNode = parentNode->getChild(row);
  if(childNode)
    return createIndex(row, column, childNode);
  return QModelIndex();
}

QModelIndex Tree::parent(const QModelIndex& index) const{
  if(!index.isValid())
    return QModelIndex();
  TreeNode* indexNode = getNode(index);
  TreeNode* parentNode = nullptr;
  if(indexNode)
    parentNode = indexNode->getParent();
  if(parentNode == root || !parentNode)
    return QModelIndex();
  return createIndex(parentNode->row(), 0, parentNode);
}

int Tree::rowCount(const QModelIndex& parent) const{
  if(parent.isValid() && parent.column() > 0)
    return 0;
  const TreeNode* parentNode = getNode(parent);
  if(parentNode)
    return parentNode->childCount();
  return 0;
}

int Tree::columnCount(const QModelIndex& parent) const{
  Q_UNUSED(parent);
  return 3;
}

QVariant Tree::data(const QModelIndex& index, int role) const{
  if(!index.isValid())
    return QVariant();
  if(role != Qt::DisplayRole && role != Qt::EditRole)
    return QVariant();
  TreeNode* indexNode = getNode(index);
  return indexNode->getData(index.column());
}

QVariant Tree::headerData(int section, Qt::Orientation orientation, int role) const{
  if(orientation != Qt::Horizontal || role != Qt::DisplayRole)
    return QVariant();
  switch(section){
    case 0:
      return QString("Name");
      break;
    case 1:
      return QString("ID");
      break;
    case 2:
      return QString("Type");
      break;
    default:
      return QVariant();
      break;
  }
}

Qt::ItemFlags Tree::flags(const QModelIndex& index) const{
  if(!index.isValid())
    return Qt::NoItemFlags;
  Qt::ItemFlags result;
  if(index.column() == 0)
    result.setFlag(Qt::ItemIsEditable);
  if(getNode(index)->isLeaf())
    result.setFlag(Qt::ItemNeverHasChildren);
  result.setFlag(Qt::ItemIsEnabled);
  result.setFlag(Qt::ItemIsSelectable);
  return result;
}

bool Tree::setData(const QModelIndex& index, const QVariant& value, int role){
  if(role != Qt::EditRole || index.column() !=0)
    return false;
  TreeNode* indexNode = getNode(index);
  bool result = indexNode->setName(value.toString());
  if(result)
    emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});
  return result;
}

bool Tree::removeRows(int position, int count, const QModelIndex& parent){
  TreeNode* parentNode = getNode(parent);
  if(!parentNode)
    return false;
  beginRemoveRows(parent, position, position+count-1);
  const bool success = parentNode->removeChildren(position, count);
  endRemoveRows();
  return success;
}

bool Tree::appendNode(QString name, const QModelIndex& parent){
  TreeNode* parentNode = getNode(parent);
  if(!parentNode->isLeaf()){
    beginInsertRows(parent, parentNode->childCount(), parentNode->childCount());
    const bool success = parentNode->appendChild(new TreeNode(name, parentNode));
    endInsertRows();
    return success;
  }
  return false;
}

bool Tree::appendSensor(BaseSensor* sensor, const QModelIndex& parent){
  TreeNode* parentNode = getNode(parent);
  if(!parentNode->isLeaf()){
    beginInsertRows(parent, parentNode->childCount(), parentNode->childCount());
    const bool success = parentNode->appendChild(new LeafNode(sensor, parentNode));
    endInsertRows();
    return success;
  }
  return false;
}
