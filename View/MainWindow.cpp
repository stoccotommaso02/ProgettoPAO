#include"MainWindow.h"
#include<QApplication>
#include<QSplitter>
#include<QVBoxLayout>

MainWindow::MainWindow(Environment* e, QWidget* parent): QMainWindow(parent), environment(e){
  QSplitter* splitter = new QSplitter(this);
  setCentralWidget(splitter);
  QSplitter* leftsplit = new QSplitter();
  leftsplit->setOrientation(Qt::Vertical);
  nodes_view = new NodesWidget(environment->tree());
  readinglist_widget = new ReadingListWidget(environment->readinglist());
  sensor_show = new SensorShow();

  leftsplit->addWidget(nodes_view);
  leftsplit->addWidget(readinglist_widget);
  splitter->addWidget(leftsplit);
  splitter->addWidget(sensor_show);

  connect(nodes_view, &NodesWidget::leafSelected, sensor_show, &SensorShow::addSensor);
  connect(nodes_view, &NodesWidget::leafDeselected, sensor_show, &SensorShow::removeSensor);
  connect(sensor_show, &SensorShow::simulated, readinglist_widget, &ReadingListWidget::addReading);
};