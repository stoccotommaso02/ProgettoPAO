#ifndef TABLECONTAINERWIDGET_H
#define TABLECONTAINERWIDGET_H
#include<QList>
#include<QWidget>
#include<QTabWidget>
#include"../Model/Observer.h"
#include"../Model/Reading/TableContainer.h"
#include"ReadingDisplayWidget.h"

class TableContainerWidget : public QWidget, public Observer{
  Q_OBJECT
private:
  TableContainer* tablecontainer;
  QTabWidget* tabs;
  QList<ReadingDisplayWidget*> displays;
  void addNewTable(const QString& name, ReadingTable* table);
public:
  TableContainerWidget(TableContainer* tc, QWidget* parent =nullptr);

signals:
  void searchReading(Reading*);

public slots:
  void highlightReading(Reading* reading);
  void changeTab(ReadingDisplayWidget* const);
  virtual void update() override;
};

#endif