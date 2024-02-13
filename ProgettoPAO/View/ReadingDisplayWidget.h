#ifndef READINGDISPLAYWIDGET_H
#define READINGDISPLAYWIDGET_h
#include<QWidget>
#include<QPushButton>
#include<QTabWidget>
#include<QTableView>
#include<QChart>
#include<QChartView>
#include"Model/Reading/ReadingTable.h"

class ReadingDisplayWidget : public QWidget{
  Q_OBJECT
private:
  ReadingTable* reading_table;
  QTabWidget* tabs;
  QTableView* table_view;
  QChartView* chart_view;
  QPushButton* remove_reading;
public:
  ReadingDisplayWidget(QWidget* parent);

public slots:
  void addReading(Reading* reading);
  void removeReading();
};

#endif