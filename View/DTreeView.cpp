#include"DTreeView.h"

void DTreeView::mousePressEvent(QMouseEvent* event){
  QModelIndex item = indexAt(event->pos());
  if(item.isValid())
    QTreeView::mousePressEvent(event);
  else{
    clearSelection();
    selectionModel()->setCurrentIndex(QModelIndex(), QItemSelectionModel::Select);
  }
}