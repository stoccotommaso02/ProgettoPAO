#ifndef TREENODE_H
#define TREENODE_H
#include<QVariant>
#include<QString>

class Tree;

class TreeNode{
  friend class Tree;
  friend class JsonTreeParser;
protected:
  TreeNode* parent;
  QList<TreeNode*> children;
  QString name;
  TreeNode(const QString& n, TreeNode* p =nullptr): name(n), parent(p) {};
  virtual ~TreeNode();
  int row() const;
  virtual bool isLeaf() const;
  virtual int childCount() const;
  TreeNode* getParent();
  TreeNode* getChild(int row);
  virtual QVariant getData(int column) const;
  virtual bool setName(const QString& n);
  TreeNode* appendChild(TreeNode* child);
  bool removeChildren(int pos, int count);
public:
  QString getName() const;
};

#endif