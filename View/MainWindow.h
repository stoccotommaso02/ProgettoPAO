#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include"NodesWidget.h"

class MainWindow : public QMainWindow{
  Q_OBJECT
public:
  explicit MainWindow(Tree* t, QWidget* parent = nullptr);

private:
  bool unsaved_changes;
  NodesWidget* nodes_view;
  Tree* tree_model;

public:
  void updateModel();

public slots:
  void close();
};

#endif