#ifndef DTREEVIEW_H
#define DTREEVIEW_H
#include<QTreeView>
#include<QMouseEvent>

class DTreeView : public QTreeView{
public:
  DTreeView(QWidget* parent =nullptr): QTreeView(parent){};
  virtual ~DTreeView(){};
  virtual void mousePressEvent(QMouseEvent* event);
};

#endif