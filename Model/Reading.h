#ifndef READING_H
#define READING_H
#include<QAbstractTableModel>
#include<QString>
#include<array>

class Reading{
private:
  QString name;
  const std::array<double, 24> reading;
public:
  Reading(QString n, std::array<double, 24> r): name(n), reading(r) {};
  virtual ~Reading(){};
  void setName(QString n);
  QString getName() const;
  std::array<double, 24> getValues() const;
};

#endif