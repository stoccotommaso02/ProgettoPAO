#ifndef LEAFNODE_H
#define LEAFNODE_H
#include"TreeNode.h"
#include"BaseSensor.h"
#include"Tree.h"

class LeafNode : public TreeNode{
  friend class Tree;
private:
  BaseSensor* const sensor;
  LeafNode(BaseSensor* s, TreeNode* p): TreeNode(s->getName(), p), sensor(s){};
  virtual ~LeafNode();
  virtual bool isLeaf() const override;
  virtual int childCount() const override;
  QVariant getData(int column) const;
  virtual bool setName(QString n) override;
};

#endif