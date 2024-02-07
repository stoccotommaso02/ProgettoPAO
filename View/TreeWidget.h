#ifndef TREEWIDGET_H
#define TREEWIDGET_H
#include<QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include<QMessageBox>
#include<QInputDialog>
#include<QStackedWidget>
#include"DTreeView.h"
#include"../Model/Tree/Tree.h"
#include"../Model/Sensor/SensorFactory.h"

class TreeWidget : public QWidget{
  Q_OBJECT

private:
  Tree* tree_model;
  static QStringList sensor_types;
  QPushButton* create_node;
  QPushButton* create_sensor;
  QPushButton* remove_node;
  QTreeView* tree_view;

public:
  explicit TreeWidget(Tree* t, QWidget* parent =nullptr);

public slots:
  void createNode();
  void createSensor();
  void removeNode();
};

#endif