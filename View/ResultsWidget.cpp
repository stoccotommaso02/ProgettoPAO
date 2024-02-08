#include"ResultsWidget.h"

ResultsWidget::ResultsWidget(NodeList* list, QWidget* parent): QWidget(parent), result_list(list){
  list_view = new QListView();
  list_view->setStyleSheet("QListView::item:hover{background-color:#0000FF};");
  list_view->setModel(result_list);

  //slot connections
  connect(list_view->selectionModel(), &QItemSelectionModel::currentChanged, this, &nodeSelected);
}

ResultsWidget::~ResultsWidget(){
  delete result_list;
}

void ResultsWidget::nodeSelected(){
  emit selectedNode(result_list->getNode(list_view->selectionModel()->currentIndex()));
}