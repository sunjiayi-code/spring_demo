QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network multimedia  widgets gui
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    jpg/jpg/4.qrc \
    jpg/jpg/back.qrc \
    jpg/jpg/back2.qrc \
    jpg/jpg/background.qrc \
    jpg/jpg/direction.qrc \
    jpg/jpg/swim.qrc \
    signin.qrc \
    wav/wav/welcome.qrc
