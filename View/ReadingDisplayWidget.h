#ifndef READINGDISPLAYWIDGET_H
#define READINGDISPLAYWIDGET_h
#include<QWidget>
#include<QHBoxLayout>
#include<QTabWidget>
#include<QColumnView>
#include<QScrollArea>
#include"Model/Observer.h"
#include"Model/Reading/ReadingTable.h"
#include"ReadingChart.h"
#include"ChartView.h"
class ReadingDisplayWidget : public QWidget, public Observer{
  Q_OBJECT

private:
  ReadingTable* reading_table;
  ReadingChart* chart;
  ChartView* chart_view;
public:
  ReadingDisplayWidget(ReadingTable* table, QWidget* parent = nullptr);
  ReadingTable* getReadingTable() const;
  virtual void observerUpdate() override;
public slots:
  void highlightReading(Reading*);
};

#endif