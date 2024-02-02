#include"MainWindow.h"
#include<QApplication>
#include<QMessageBox>
#include<QSplitter>

MainWindow::MainWindow(Tree* t, QWidget* parent): QMainWindow(parent), unsaved_changes(false), tree_model(t){
  QSplitter* splitter = new QSplitter(this);
  setCentralWidget(splitter);

  tree_view = new TreeWidget(tree_model);
  splitter->addWidget(tree_view);
};

void MainWindow::updateModel(){

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