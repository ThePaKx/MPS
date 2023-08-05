QT       += core gui
QT += charts
QT += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    modelpredict.cpp \
    pretreatment.cpp \
    savedata.cpp \
    show.cpp \
    showresultwindow.cpp

HEADERS += \
    mainwindow.h \
    modelpredict.h \
    pretreatment.h \
    savedata.h \
    show.h \
    showresultwindow.h

FORMS += \
    mainwindow.ui \
    showresultwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#win32: LIBS += -L$$PWD/../../../material/Python/libs/ -lpython36

#INCLUDEPATH += $$PWD/../../../material/Python/libs
#DEPENDPATH += $$PWD/../../../material/Python/libs

#win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../../material/Python/libs/python36.lib


win32: LIBS += -LC:/Users/LENOVO/AppData/Local/Programs/Python/Python38/libs/ -lpython38

INCLUDEPATH += C:/Users/LENOVO/AppData/Local/Programs/Python/Python38/libs
DEPENDPATH += C:/Users/LENOVO/AppData/Local/Programs/Python/Python38/libs

win32:!win32-g++: PRE_TARGETDEPS += C:/Users/LENOVO/AppData/Local/Programs/Python/Python38/libs/python38.lib
#else:win32-g++: PRE_TARGETDEPS += C:/Users/LENOVO/AppData/Local/Programs/Python/Python38/libs/libpython38.a

DISTFILES += \
    newTest.py
