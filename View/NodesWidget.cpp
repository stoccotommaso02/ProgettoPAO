#include"NodesWidget.h"

NodesWidget::NodesWidget(Tree* t, QWidget* parent): QWidget(parent), tree(t){
  stack = new QStackedWidget();
  tree_widget = new TreeWidget(tree);
  search_query = new QLineEdit();
  search_button = new QPushButton("Search");
  results_widget = nullptr;
  QVBoxLayout* vbox = new QVBoxLayout(this);
  QHBoxLayout* searchbar = new QHBoxLayout();
  vbox->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  searchbar->setAlignment(Qt::AlignTop | Qt::AlignHCenter);

  searchbar->addWidget(search_query);
  searchbar->addStretch();
  searchbar->addWidget(search_button);
  searchbar->addStretch();
  vbox->addLayout(searchbar);

  stack->addWidget(tree_widget);
  vbox->addWidget(stack);

  connect(search_button, &QPushButton::clicked, this, &NodesWidget::displaySearch);
  connect(results_widget, &ResultsWidget::selectedNode, this, &NodesWidget::searchResultSelected);
  connect(this, &NodesWidget::selectTreeNode, tree_widget, &TreeWidget::selectNode);
}

void NodesWidget::closeResultsWidget(){
  stack->removeWidget(results_widget);

}

void NodesWidget::searchResultSelected(TreeNode* node){
  closeResultsWidget();
  emit selectTreeNode(node);
}