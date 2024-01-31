#ifndef TREENODE_H
#define TREENODE_H
#include<QVariant>
#include<QString>

class Tree;

class TreeNode{
  friend class Tree;
protected:
  TreeNode* parent;
  QList<TreeNode*> children;
  QString name;
  TreeNode(QString n, TreeNode* p =nullptr): name(n), parent(p) {};
  virtual ~TreeNode();
  int row() const;
  virtual bool isLeaf() const;
  virtual int childCount() const;
  TreeNode* getParent();
  TreeNode* getChild(int row);
  virtual QVariant getData(int column) const;
  virtual bool setName(QString n);
  bool appendChild(TreeNode* child);
  bool removeChildren(int pos, int count);
};
#endif