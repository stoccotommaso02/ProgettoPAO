#ifndef READINGDISPLAYWIDGET_H
#define READINGDISPLAYWIDGET_h
#include<QWidget>
#include<QPushButton>
#include<QTabWidget>
#include<QTableView>
#include<QChart>
#include<QChartView>
#include"Model/Observer.h"
#include"Model/Reading/ReadingTable.h"

class ReadingDisplayWidget : public QWidget, public Observer{
  Q_OBJECT
private:
  ReadingTable* reading_table;
  QTabWidget* tabs;
  QTableView* table_view;
  QChartView* chart_view;
  QPushButton* remove_reading;
public:
  ReadingDisplayWidget(ReadingTable* table, QWidget* parent = nullptr);

signals:
  void readingcontained(ReadingDisplayWidget* const);

public slots:
  void removeReading();
  void highlightReading(Reading* reading);
  void update() override;
};

#endif