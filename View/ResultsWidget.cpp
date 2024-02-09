#include"ResultsWidget.h"

ResultsWidget::ResultsWidget(NodeList* list, QWidget* parent): QWidget(parent), result_list(list){
  list_view = new QListView();
  no_results = new QLabel("Search yielded no results.");
  no_results->setAlignment(Qt::AlignHCenter);
  close_widget = new QPushButton("Close");

  QVBoxLayout* vbox = new QVBoxLayout(this);
  if(result_list->rowCount() == 0){
    vbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    list_view->setStyleSheet("QListView::item::hover{background-colo:#0000FF};");
    list_view->setModel(result_list);
    vbox->addWidget(list_view);
  }
  else{
    vbox->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
    vbox->addWidget(no_results);
    vbox->addWidget(close_widget);
  }

  //slot connections
  connect(list_view->selectionModel(), &QItemSelectionModel::currentChanged, this, &nodeSelected);
  connect(close_widget, &QPushButton::clicked, this, &ResultsWidget::closeButtonPressed);
}

ResultsWidget::~ResultsWidget(){
  delete result_list;
}

void ResultsWidget::nodeSelected(){
  emit selectedNode(result_list->getNode(list_view->selectionModel()->currentIndex()));
}

void ResultsWidget::closeButtonPressed(){
  emit closePressed();
}