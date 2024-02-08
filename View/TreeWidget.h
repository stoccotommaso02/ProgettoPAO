#ifndef TREEWIDGET_H
#define TREEWIDGET_H
#include<QWidget>
#include<QVBoxLayout>
#include<QPushButton>
#include<QMessageBox>
#include<QInputDialog>
#include<QStackedWidget>
#include<QLineEdit>
#include<QListView>
#include"DTreeView.h"
#include"../Model/Tree/Tree.h"
#include"../Model/Sensor/SensorFactory.h"
#include"../Model/Tree/NodeList.h"

class TreeWidget : public QWidget{
  Q_OBJECT
private:
  Tree* tree_model;
  QStackedWidget* stack;
  QPushButton* create_node;
  QPushButton* create_sensor;
  QPushButton* remove_node;
  QTreeView* tree_view;
  QLineEdit* searchbar;

public:
  explicit TreeWidget(Tree* t, QWidget* parent =nullptr);

public slots:
  void createNode();
  void createSensor();
  void removeNode();
};

#endif