#ifndef RESULTSWIDGET_H
#define RESULTSWIDGET_H
#include<QVBoxLayout>
#include<QListView>
#include<QLabel>
#include<QPushButton>
#include"../Model/Tree/NodeList.h"


class ResultsWidget : public QWidget{
  Q_OBJECT
private:
  NodeList* result_list;
  QListView* list_view;
  QLabel* no_results;
  QPushButton* close_widget;
public:
  ResultsWidget(NodeList* list, QWidget* parent = nullptr);
  virtual ~ResultsWidget() override;

public slots:
  void nodeSelected();
  void closeButtonPressed();

signals:
  void selectedNode(TreeNode* node);
  void closePressed();
};

#endif