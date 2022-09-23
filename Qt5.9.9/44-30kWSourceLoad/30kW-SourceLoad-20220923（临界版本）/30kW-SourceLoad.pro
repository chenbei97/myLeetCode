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
    communication/communication.cpp \
    settings//basic_analog_interface.cpp \
    settings/basic_common_settings.cpp \
    settings/basic_parallel_settings.cpp \
    settings/basic_settings.cpp \
    communication/communication_connect.cpp \
    communication/communication_initial.cpp \
    communication/communication_slot_from_fixedquery.cpp \
    communication/communication_slot_from_monitor.cpp \
    communication/communication_slot_from_tcp.cpp \
    communication/communication_slot_from_usb.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow/mainwindow_connect.cpp \
    mainwindow/mainwindow_initial.cpp \
    mainwindow/mainwindow_slot_from_about.cpp \
    mainwindow/mainwindow_slot_from_function.cpp \
    mainwindow/mainwindow_slot_from_monitor.cpp \
    mainwindow/mainwindow_slot_from_setting.cpp \
    mainwindow/mainwindow_slot_from_tool.cpp \
    monitor/monitor.cpp \
    monitor/monitor_connect.cpp \
    monitor/monitor_initial.cpp \
    monitor/monitor_label.cpp \
    monitor/monitor_slot_from_communication.cpp \
    monitor/monitor_slot_from_spinbox.cpp \
    monitor/monitor_spinbox.cpp \
    serial/serial.cpp \
    serial/serial_connect.cpp \
    serial/serial_fixedquery_thread.cpp \
    serial/serial_initial.cpp \
    serial/serial_slot_from_ui.cpp \
    serial/serial_variable_setting.cpp

HEADERS += \
    communication/communication.h \
    core/enum.h \
    core/spic_command.h \
    settings/basic_analog_interface.h \
    settings/basic_common_settings.h \
    settings/basic_parallel_settings.h \
    settings/basic_settings.h \
    mainwindow.h \
    monitor/monitor.h \
    monitor/monitor_label.h \
    monitor/monitor_spinbox.h \
    serial/serial.h \
    serial/serial_fixedquery_thread.h \
    serial/serial_variable_setting.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
                images.qrc

DISTFILES += \
                readme.txt
