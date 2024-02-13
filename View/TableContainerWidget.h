#ifndef TABLECONTAINERWIDGET_H
#define TABLECONTAINERWIDGET_H
#include<QList>
#include<QWidget>
#include<QTabWidget>
#include"../Model/Reading/TableContainer.h"
#include"ReadingDisplayWidget.h"

class TableContainerWidget : public QWidget{
  Q_OBJECT
private:
  TableContainer* tablecontainer;
  QTabWidget* tabs;
  QList<ReadingDisplayWidget*> displays;
public:
  TableContainerWidget(TableContainer* tc, QWidget* parent =nullptr);

signals:
  void searchReading(Reading*);

public slots:
  void highlightReading(Reading* reading);
  void changeTab(ReadingDisplayWidget* const);
};

#endif