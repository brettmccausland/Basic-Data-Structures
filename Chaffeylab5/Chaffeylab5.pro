TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Booklist.h \
    Bookiterator.h \
    Booknode.h \
    node.h \
    stacklist.h \
    queuelist.h \
    linkedlist.h

