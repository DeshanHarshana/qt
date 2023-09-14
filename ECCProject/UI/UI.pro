QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

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




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ecclib/build-ecclib-Desktop_Qt_6_5_2_GCC_64bit-Debug/release/ -lecclib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ecclib/build-ecclib-Desktop_Qt_6_5_2_GCC_64bit-Debug/debug/ -lecclib
else:unix: LIBS += -L$$PWD/../ecclib/build-ecclib-Desktop_Qt_6_5_2_GCC_64bit-Debug/ -lecclib

INCLUDEPATH += $$PWD/../ecclib/ecclib
DEPENDPATH += $$PWD/../ecclib/ecclib
