#include"MainWindow.h"
#include<QApplication>
#include<QMessageBox>
#include<QSplitter>

MainWindow::MainWindow(Tree* t, QWidget* parent): QMainWindow(parent), unsaved_changes(false), treeModel(t){
  QSplitter* splitter = new QSplitter(this);
  setCentralWidget(splitter);

  treeView = new QTreeView();
  splitter->addWidget(treeView);
};

void MainWindow::updateModel(){
  treeView->setModel(treeModel);
}

void MainWindow::close(){
  if(unsaved_changes){
    QMessageBox::StandardButton confirmation;
    confirmation = QMessageBox::question(this, "Close application?", "Close application without saving?", QMessageBox::Yes | QMessageBox::No);
    if(confirmation == QMessageBox::Yes)
      QApplication::quit();
  }
  else
    QApplication::quit();
}