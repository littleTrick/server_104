TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror

SOURCES += main.cpp \
    dlt634_5104slave_disk.c \
    dlt634_5104slave_app.c \
    data_cache.c \
    tcpsocket.cpp

HEADERS += \
    logging.h \
    integer.h \
    dlt634_5104slave_disk.h \
    dlt634_5104slave_config.h \
    dlt634_5104slave_app.h \
    data_cache.h \
    tcpsocket.h

