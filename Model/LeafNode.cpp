#include"LeafNode.h"

LeafNode::~LeafNode(){
  delete sensor;
}

bool LeafNode::isLeaf() const{
  return true;
}

int LeafNode::childCount() const{
  return 0;
}

QVariant LeafNode::getData(int column) const{
  switch(column){
    case 0:
      return name;
      break;
    case 1:
      return sensor->getId();
      break;
    case 2:
      return sensor->getType();
      break;
    default:
      return QVariant();
      break;
  }
}

bool LeafNode::setName(QString n){
  sensor->setName(n);
  name = n;
  return true;
}