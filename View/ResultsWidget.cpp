#include"ResultsWidget.h"

ResultsWidget::ResultsWidget(QWidget* parent): QWidget(parent){
  list_view = new QListView();
  list_view->setStyleSheet("QListView::item::hover{background-colo:#0000FF};");
  no_results = new QLabel("Search yielded no results.");
  no_results->setAlignment(Qt::AlignHCenter);
  close_widget = new QPushButton("Close");
  empty_list = new QWidget();
  widget_list = new QWidget();

  stack = new QStackedLayout(this);
  QVBoxLayout* vbox_list = new QVBoxLayout(widget_list);
  QVBoxLayout* vbox_empty = new QVBoxLayout(empty_list);
  vbox_list->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  vbox_empty->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

  vbox_empty->addWidget(no_results);
  vbox_empty->addWidget(close_widget);
  vbox_list->addWidget(list_view);

  stack->addWidget(empty_list);
  stack->addWidget(widget_list);

  //slot connections
  connect(list_view->selectionModel(), &QItemSelectionModel::currentChanged, this, &ResultsWidget::nodeSelected);
  connect(close_widget, &QPushButton::clicked, this, &ResultsWidget::closeButtonPressed);
}

void ResultsWidget::addList(NodeList* list){
  if(result_list != nullptr)
    delete result_list;
  result_list = list;
  list_view->setModel(result_list);
  if(result_list->rowCount() == 0){
    stack->setCurrentIndex(0);
  }
  else{
    stack->setCurrentIndex(1);
  }
}


void ResultsWidget::nodeSelected(){
  emit selectedNode(result_list->getNode(list_view->selectionModel()->currentIndex()));
}

void ResultsWidget::closeButtonPressed(){
  emit closePressed();
}

void ResultsWidget::removeList(){
  delete result_list;
}