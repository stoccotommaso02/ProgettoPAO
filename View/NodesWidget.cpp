#include"NodesWidget.h"

NodesWidget::NodesWidget(Tree* t, QWidget* parent): QWidget(parent), tree(t){
  stack = new QStackedWidget();
  tree_widget = new TreeWidget(tree);
  search_query = new QLineEdit();
  search_button = new QPushButton("Search");
  results_widget = new ResultsWidget();
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
  stack->setCurrentIndex(0);

}

void NodesWidget::searchResultSelected(TreeNode* node){
  closeResultsWidget();
  emit selectTreeNode(node);
}

void NodesWidget::displaySearch(){
  results_widget->addList(tree->search(search_query->text()));
  stack->setCurrentIndex(1);
}