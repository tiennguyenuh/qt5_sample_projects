QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DESTDIR = /data1/tiennguyen7/8_QtSmarthome/workspace/led_blinking/packages

## Define the command to move the executable and copy assets.
QMAKE_POST_LINK += \
    mkdir -p $$DESTDIR && \
    chmod a+x $$DESTDIR $$PWD/assets && \
    cp -rf $$OUT_PWD/$$TARGET $$DESTDIR && \
    cp -rf $$PWD/assets $$DESTDIR
