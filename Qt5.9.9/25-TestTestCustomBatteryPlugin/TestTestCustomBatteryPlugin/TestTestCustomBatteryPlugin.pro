CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(qbatteryplugin)
TEMPLATE    = lib

HEADERS     = qbatteryplugin.h
SOURCES     = qbatteryplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(qbattery.pri)

DISTFILES += \
    readme.txt
