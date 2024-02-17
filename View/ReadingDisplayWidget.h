#ifndef READINGDISPLAYWIDGET_H
#define READINGDISPLAYWIDGET_h
#include<QWidget>
#include<QHBoxLayout>
#include<QTabWidget>
#include<QColumnView>
#include<QScrollArea>
#include"Model/Observer.h"
#include"Model/Reading/ReadingTable.h"
#include"RemoveButtonWidget.h"
#include"ReadingChart.h"
#include"ChartView.h"
class ReadingDisplayWidget : public QWidget, public Observer{
  Q_OBJECT

private:
  ReadingTable* reading_table;
  ReadingChart* chart;
  ChartView* chart_view;
  RemoveButtonWidget* buttons;
  void makeButton(Reading* r);
  void deleteButton(Reading* r);
public:
  ReadingDisplayWidget(ReadingTable* table, QWidget* parent = nullptr);
  ReadingTable* getReadingTable() const;
  virtual void observerUpdate() override;
signals:
  void readingcontained(ReadingDisplayWidget* const);
public slots:
  void removeReading(Reading* r);
  void highlightReading(Reading*);
};

#endif