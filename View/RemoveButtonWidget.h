#ifndef REMOVEBUTTONWIDGET_H
#define REMOVEBUTTONWIDGET_H
#include<QWidget>
#include<QLIst>
#include<QHBoxLayout>
#include"RemovalButton.h"
#include<QLabel>

class RemoveButtonWidget : public QWidget{
  Q_OBJECT
private:
  QList<RemovalButton*> buttons;
public:
  RemoveButtonWidget(QWidget* parent =nullptr);
  QHBoxLayout* hbox;
  void addButton(Reading*);
  void removeButton(Reading*);
  QLabel* label;

signals:
  void toRemove(Reading*);

public slots:
  void buttonclicked(Reading*);
};

#endif