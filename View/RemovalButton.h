#ifndef REMOVALBUTTON_H
#define REMOVALBUTTON_H
#include<QPushButton>
#include"../Model/Observer.h"
#include"../Model/Reading/Reading.h"

class ReadingDisplayWidget;

class RemovalButton: public QPushButton, public Observer{
  Q_OBJECT
  friend class ReadingDisplayWidget;
private:
  Reading* reading;
  RemovalButton(Reading* r, QWidget* parent=nullptr);
  ~RemovalButton();
  void observerUpdate() override;

signals:
  void deleteclicked(Reading* r);

public slots:
  void remove();
};


#endif