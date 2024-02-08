#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H
#include<QListView>
#include"../Model/Tree/NodeList.h"


class ResultsWidget : public QWidget{
private:
  NodeList* const result_list;
  QListView* list_view;
public:
  ResultsWidget(NodeList* listt, QWidget* parent);
  virtual ~ResultsWidget() override;

signals:
  void selectedNode(TreeNode* node);

public slots:
  void nodeSelected();
};

#endif