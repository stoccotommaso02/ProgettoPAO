#ifndef SAMPLETREE_H
#define SAMPLETREE_H
#include"Tree.h"
#include"SampleSensor.h"

void populateSampleTree(Tree* tree){
  tree->appendNode("Nodo0");
  tree->appendNode("Nodo1");
  tree->appendNode("Nodo2");
  tree->appendSensor(new SampleSensor(QString("0.0")), tree->index(0,0));
  tree->appendSensor(new SampleSensor(QString("Sensor3")));
  tree->appendNode("Nodo0.1", tree->index(0,0));
  tree->appendNode("Nodo0.2", tree->index(0,0));
  tree->appendSensor(new SampleSensor(QString("Sensor0.1.0")), tree->index(1,0,tree->index(0,0)));
}

#endif