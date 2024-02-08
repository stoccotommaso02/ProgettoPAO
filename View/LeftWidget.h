#ifndef NODESWIDGET_H
#define NODESWIDGET_H
#include<QStackedWidget>
#include<QVBoxLayout>
#include"TreeWidget.h"
#include"../Model/Tree/NodeList.h"

class NodesWidget : public QWidget{
  Q_OBJECT
private:
  TreeWidget* tree_widget;
  
public:
  NodesWidget(Tree* t, QWidget* parent);

signals:
  void searchResultSelected(BaseSensor*);
};

#endif