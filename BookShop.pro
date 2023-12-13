TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    class.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    class.h

