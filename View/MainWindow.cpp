#include"MainWindow.h"
#include<QApplication>
#include<QMessageBox>
#include<QSplitter>

MainWindow::MainWindow(Tree* t, QWidget* parent): QMainWindow(parent), tree_model(t){
  QSplitter* splitter = new QSplitter(this);
  setCentralWidget(splitter);

  nodes_view = new NodesWidget(tree_model);
  sensor_show = new SensorShow();
  splitter->addWidget(nodes_view);
  splitter->addWidget(sensor_show);

  connect(nodes_view, &NodesWidget::leafSelected, sensor_show, &SensorShow::addSensor);
  connect(nodes_view, &NodesWidget::leafDeselected, sensor_show, &SensorShow::removeSensor);
};

void MainWindow::updateModel(){

}