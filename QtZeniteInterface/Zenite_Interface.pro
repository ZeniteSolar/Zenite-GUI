QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    compass.cpp \
    electricdata.cpp \
    gps.cpp \
    gyroscope.cpp \
    main.cpp \
    mainwindow.cpp \
    navigation.cpp  \
    acceleration.cpp \
    displayponteiro.cpp

HEADERS += \
    compass.h \
    electricdata.h \
    gps.h \
    gyroscope.h \
    main.h \
    mainwindow.h \
    navigation.h  \
    acceleration.h \
    displayponteiro.h

FORMS += \
    mainwindow.ui \
    navigation.ui  \
    acceleration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    uml_teste.qmodel
