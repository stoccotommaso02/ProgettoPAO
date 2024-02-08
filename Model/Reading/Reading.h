#ifndef READING_H
#define READING_H
#include<QList>
#include<QString>
#include<QVariant>

class ReadingVisitor;

class Reading{
private:
  QString name;
  const QList<double>* reading;
public:
  Reading(const QString& n, const QList<double>* r): name(n), reading(r) {};
  virtual ~Reading();
  void setName(QString n);
  QString getName() const;
  int getSize() const;
  const QVariant getValue(int index) const;
  virtual void accept(ReadingVisitor& v) =0;
};

#endif