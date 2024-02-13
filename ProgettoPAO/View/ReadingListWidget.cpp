#include"ReadingListWidget.h"

ReadingListWidget::ReadingListWidget(ReadingList* rl, QWidget* parent): QWidget(parent), readinglist(rl){
  table_view = new QTableView();
  table_view->setModel(readinglist);
  delete_reading = new QPushButton("Delete Reading");
  add_to_display = new QPushButton("Add to display");

  QVBoxLayout* vbox = new QVBoxLayout(this);
  QHBoxLayout* buttonbox = new QHBoxLayout();
  vbox->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  buttonbox->setAlignment(Qt::AlignTop | Qt::AlignLeft);
  buttonbox->addWidget(add_to_display);
  buttonbox->addWidget(delete_reading);
  vbox->addLayout(buttonbox);
  vbox->addWidget(table_view);

  connect(delete_reading, &QPushButton::clicked, this, &ReadingListWidget::deleteReadingClicked);
  connect(add_to_display, &QPushButton::clicked, this, &ReadingListWidget::addClicked);
}

void ReadingListWidget::deleteReadingClicked(){
  QModelIndex index = table_view->selectionModel()->currentIndex();
  if(!index.isValid()){
    QMessageBox::StandardButton warn = QMessageBox::warning(this, "Invalid index", "Please select a Reading", QMessageBox::Ok);
    return;
  }
  readinglist->remove(index);
}

void ReadingListWidget::addReading(int id, Reading* reading){
  readinglist->insert(id, reading);
  table_view->selectionModel()->select(readinglist->find(id, reading), QItemSelectionModel::Select);
}

void ReadingListWidget::addClicked(){
  QModelIndex index = table_view->selectionModel()->currentIndex();
  if(index.isValid()){
    emit displayReading(readinglist->reading(index));
  }
}

void ReadingListWidget::update(){
  QWidget::update();
}