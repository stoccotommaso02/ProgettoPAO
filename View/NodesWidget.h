#ifndef NODESWIDGET_H
#define NODESWIDGET_H
#include<QStackedWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLineEdit>
#include<QPushButton>
#include"../Model/Observer.h"
#include"TreeWidget.h"
#include"ResultsWidget.h"
#include"../Model/Tree/NodeList.h"

class NodesWidget : public QWidget, public Observer{
  Q_OBJECT
private:
  Tree* tree;
  QStackedWidget* stack;
  TreeWidget* tree_widget;
  QLineEdit* search_query;
  QPushButton* search_button;
  ResultsWidget* results_widget;

public:
  NodesWidget(Tree* t, QWidget* parent =nullptr);
  virtual void update() override;
  void refresh();

signals:
void selectTreeNode(TreeNode* node);

public slots:
  void displaySearch();
  void closeResultsWidget();
  void searchResultSelected(TreeNode* node);
};

#endif