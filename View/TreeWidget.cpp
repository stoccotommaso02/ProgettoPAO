#include"TreeWidget.h"

TreeWidget::TreeWidget(Tree* t, QWidget* parent): tree_model(t), QWidget(parent){
  QVBoxLayout* vbox = new QVBoxLayout(this);
  vbox->setAlignment(Qt::AlignTop | Qt::AlignCenter);
  QHBoxLayout* hbox = new QHBoxLayout();
  hbox->setAlignment(Qt::AlignTop | Qt::AlignCenter);
  vbox->addLayout(hbox);
  create_node = new QPushButton("Add node");
  create_sensor = new QPushButton("Add sensor");
  remove_node = new QPushButton("Delete node");
  
  tree_view = new DTreeView();
  tree_view->setModel(tree_model);

  //Layout of button commands
  hbox->addWidget(create_node);
  hbox->addStretch();
  hbox->addWidget(create_sensor);
  hbox->addStretch();
  hbox->addWidget(remove_node);
  hbox->addStretch();

  vbox->addWidget(tree_view);

  //connect signals
  connect(create_node, &QPushButton::clicked, this, &TreeWidget::createNode);
  connect(create_sensor, &QPushButton::clicked, this, &TreeWidget::createSensor);
  connect(remove_node, &QPushButton::clicked, this, &TreeWidget::removeNode);
}

void TreeWidget::createNode(){
  QModelIndex parent = tree_view->selectionModel()->currentIndex();

  if(tree_model->leaf(parent)){
    QMessageBox::StandardButton warn;
    warn = QMessageBox::warning(this, "Invalid operation", "Cannot add a child to a sensor node", QMessageBox::Ok);
    return;
  }
  
  bool ok;
  QString name = QInputDialog::getText(this, "Create node", "Node name:", QLineEdit::Normal, "", &ok);
  if(ok)
    tree_model->appendNode(name, parent);
  return;
}

void TreeWidget::createSensor(){
  QModelIndex parent = tree_view->selectionModel()->currentIndex();

    if(tree_model->leaf(parent)){
    QMessageBox::StandardButton warn;
    warn = QMessageBox::warning(this, "Invalid operation", "Cannot add a child to a sensor node", QMessageBox::Ok);
    return;
  }

  bool ok;
  QString name = QInputDialog::getText(this, "Create sensor", "Sensor name:", QLineEdit::Normal, "", &ok);
  if(!ok) return;
  QString type = QInputDialog::getItem(this, "Create sensor", "Select type:", SensorFactory::concrete_sensor_types, 0, false, &ok);
  if(!ok) return;
  tree_model->appendSensor(SensorFactory::createSensor(name, type), parent);
}

void TreeWidget::removeNode(){
  QModelIndex index = tree_view->selectionModel()->currentIndex();
  tree_model->removeNode(index);
}

/*
void TreeWidget::createNode(){
  QModelIndexList indexes = tree_view->selectionModel()->selectedIndexes();
  if(indexes.empty()){
      bool ok;
      QString name = QInputDialog::getText(this, "Insert name", "Name:", QLineEdit::Normal, "", &ok);
      if(ok)
        tree_model->appendNode(name);
      return;
  }
  if(indexes.count() == 1){
      bool ok;
      QString name = QInputDialog::getText(this, "Insert name", "Name:", QLineEdit::Normal, "", &ok);
      if(ok)
        tree_model->appendNode(name, indexes.at(0));
      return;
  }
  QMessageBox::StandardButton warn;
  warn = QMessageBox::warning(this, "Too many node selected", "Please select only one node.", QMessageBox::Ok);
  return;
}

void TreeWidget::createSensor(){
  QModelIndexList indexes = tree_view->selectionModel()->selectedIndexes();
  if(indexes.empty()){
    bool ok;
    
  }

}
*/