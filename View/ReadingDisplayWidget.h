#ifndef READINGDISPLAYWIDGET_H
#define READINGDISPLAYWIDGET_h
#include<QWidget>
#include<QPushButton>
#include<QTabWidget>
#include<QTableView>
#include"Model/Observer.h"
#include"Model/Reading/ReadingTable.h"
#include"ReadingChart.h"
#include"ChartView.h"
class ReadingDisplayWidget : public QWidget, public Observer{
  Q_OBJECT

private:
  ReadingTable* reading_table;
  ReadingChart* chart;
  QTabWidget* tabs;
  QTableView* table_view;
  ChartView* chart_view;
  QPushButton* remove_reading;
  
public:
  ReadingDisplayWidget(ReadingTable* table, QWidget* parent = nullptr);
  ReadingTable* getReadingTable() const;
signals:
  void readingcontained(ReadingDisplayWidget* const);
public slots:
  void removeReading();
  void highlightReading(Reading* reading);
  void observerUpdate() override;
};

#endif