#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include"NodesWidget.h"
#include"SensorShow.h"

class MainWindow : public QMainWindow{
  Q_OBJECT
public:
  explicit MainWindow(Tree* t, QWidget* parent = nullptr);

private:
  Tree* tree_model;
  NodesWidget* nodes_view;
  SensorShow* sensor_show;

public:
  void updateModel();

signals:
  void sensorSelected(BaseSensor* sensor);
  void sensorDeselected();

public slots:
  void close();
};

#endif