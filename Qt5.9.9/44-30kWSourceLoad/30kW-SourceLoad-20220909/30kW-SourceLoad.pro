QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    communication/communicate_connect.cpp \
    communication/communicate_initial.cpp \
    communication/communicate_tcp.cpp \
    communication/communicate_usb.cpp \
    communication/communicate_with_fixquery.cpp \
    communication/communicate_with_monitor.cpp \
    communication/communication.cpp \
    core/cabout.cpp \
    core/cconnect.cpp \
    core/cfunction.cpp \
    core/cinitial.cpp \
    core/cmonitoring.cpp \
    core/csetting.cpp \
    core/ctool.cpp \
    basic_settings//basic_analog_interface.cpp \
    basic_settings/basic_common_settings.cpp \
    basic_settings/basic_parallel_settings.cpp \
    basic_settings/basic_settings.cpp \
    main.cpp \
    mainwindow.cpp \
    monitor/monitor.cpp \
    monitor/monitor_connect.cpp \
    monitor/monitor_externel_slot.cpp \
    monitor/monitor_initial.cpp \
    monitor/monitor_internel_slot.cpp \
    monitor/monitor_label.cpp \
    monitor/monitor_spinbox.cpp \
    serial/serial_config.cpp \
    serial/serial_connect.cpp \
    serial/serial_fixedquerythread.cpp \
    serial/serial_initial.cpp \
    serial/serial_variablesetting.cpp

HEADERS += \
    communication/communication.h \
    core/enum.h \
    core/spic_command.h \
    basic_settings/basic_analog_interface.h \
    basic_settings/basic_common_settings.h \
    basic_settings/basic_parallel_settings.h \
    basic_settings/basic_settings.h \
    mainwindow.h \
    monitor/monitor.h \
    monitor/monitor_label.h \
    monitor/monitor_spinbox.h \
    serial/serial_config.h \
    serial/serial_fixedquerythread.h \
    serial/serial_variablesetting.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
                images.qrc

DISTFILES += \
                readme.txt
