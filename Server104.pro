TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -lpthread
LIBS += -lpthread
SOURCES += main.cpp \
    timestamp.cpp \
    timerfd.cc \
    thread_104.cpp \
    thread_101.cpp \
    tcpsocket.cpp \
    serialport.cpp \
    queue.cpp \
    mock_serialport.cpp \
    dlt634_5104slave_disk.c \
    dlt634_5104slave_app.c \
    dlt634_5101master_disk.c \
    dlt634_5101master_app.c \
    data_cache.cpp

OTHER_FILES += \
    Server104.pro.user \
    Makefile

HEADERS += \
    types.h \
    timestamp.h \
    timerfd.h \
    thread_104.h \
    thread_101.h \
    tcpsocket.h \
    serialport.h \
    queue.h \
    mutex_guard.h \
    mock_serialport.h \
    integer.h \
    dlt634_5104slave_disk.h \
    dlt634_5104slave_config.h \
    dlt634_5104slave_app.h \
    dlt634_5101master_disk.h \
    dlt634_5101master_config.h \
    dlt634_5101master_app.h \
    data_cache.h

