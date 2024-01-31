#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include<QTreeView>
#include"../Model/Tree.h"

class MainWindow : public QMainWindow{
  Q_OBJECT
public:
  explicit MainWindow(Tree* t, QWidget* parent = nullptr);

private:
  bool unsaved_changes;
  QTreeView* treeView;
  Tree* treeModel;

public:
  void updateModel();

public slots:
  void close();
};

#endif