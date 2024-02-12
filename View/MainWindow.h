#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#include"../Model/Environment.h"
#include"NodesWidget.h"
#include"SensorShow.h"
#include"ReadingListWidget.h"

class MainWindow : public QMainWindow{
  Q_OBJECT
public:
  explicit MainWindow(Environment* e, QWidget* parent = nullptr);

private:
  Environment* environment;
  NodesWidget* nodes_view;
  SensorShow* sensor_show;
  ReadingListWidget* readinglist_widget;
};

#endif