#ifndef READINGDISPLAYWIDGET_H
#define READINGDISPLAYWIDGET_h
#include<QWidget>
#include<QPushButton>
#include<QTabWidget>
#include<QColumnView>
#include<QScrollArea>
#include"Model/Observer.h"
#include"Model/Reading/ReadingTable.h"
#include"RemovalButton.h"
#include"ReadingChart.h"
#include"ChartView.h"
class ReadingDisplayWidget : public QWidget, public Observer{
  Q_OBJECT

private:
  QList<RemovalButton*> buttons;
  ReadingTable* reading_table;
  ReadingChart* chart;
  ChartView* chart_view;
  QHBoxLayout* hbox;
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