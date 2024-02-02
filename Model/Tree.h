#ifndef TREE_H
#define TREE_H
#include<QList>
#include<QAbstractItemModel>
#include<QString>
#include"TreeNode.h"
#include"LeafNode.h"
#include"BaseSensor.h"

class Tree : public QAbstractItemModel{
  Q_OBJECT
private:
  TreeNode* root;
  TreeNode* getNode(const QModelIndex& index) const;
public:
  explicit Tree(): root(new TreeNode("root")){};
  ~Tree();
  QModelIndex index(int row, int column, const QModelIndex& parent =QModelIndex()) const override;
  QModelIndex parent(const QModelIndex& index) const override;
  bool leaf(const QModelIndex& index) const;
  int rowCount(const QModelIndex& parent =QModelIndex()) const override;
  int columnCount(const QModelIndex& parent =QModelIndex()) const override;
  QVariant data(const QModelIndex& index, int role) const override;
  QVariant headerData(int section, Qt::Orientation orientation, int role =Qt::DisplayRole) const override;
  Qt::ItemFlags flags(const QModelIndex& index) const override;
  bool setData(const QModelIndex& index, const QVariant& value, int role =Qt::EditRole) override;
  bool removeRows(int position, int rows, const QModelIndex& parent =QModelIndex()) override;
  bool appendNode(QString name, const QModelIndex& parent =QModelIndex());
  bool appendSensor(BaseSensor* sensor, const QModelIndex& parent =QModelIndex());
  bool removeNode(const QModelIndex& index =QModelIndex());
  void resetTree();
};

#endif