QT += core widgets
CONFIG += debug

TARGET = TreeTest

HEADERS +=  Model/BaseSensor.h \
            Model/SampleSensor.h \
            Model/Reading.h \
            Model/SampleReading.h \
            Model/Settings.h \
            Model/TreeNode.h \
            Model/LeafNode.h \
            Model/Tree.h \
            Model/sampletree.h \
            Model/SensorFactory.h \
            View/MainWindow.h \
            View/TreeWidget.h

SOURCES +=  main.cpp \
            Model/BaseSensor.cpp \
            Model/Reading.cpp \
            Model/TreeNode.cpp \
            Model/LeafNode.cpp \
            Model/Tree.cpp \
            Model/SensorFactory.cpp \
            View/MainWindow.cpp \
            View/TreeWidget.cpp