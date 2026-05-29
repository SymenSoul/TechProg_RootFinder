QT += core testlib
CONFIG += c++17
CONFIG -= app_bundle
QMAKE_CXXFLAGS += -Wno-error=implicit-function-declaration
TARGET = MathServerTests
TEMPLATE = app

HEADERS += ../MathServer/mathsolver.h
SOURCES += main.cpp \
           ../MathServer/mathsolver.cpp
