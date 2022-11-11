QT       += core gui
QT       += serialport
QT       += network
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += Qt_NO_CAST_FROM_ASCII

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS = cn.ts \
                                  en.ts

SOURCES += \
    communication/communication.cpp \
    communication/communication_connect.cpp \
    login/login.cpp \
    login/login_create_account.cpp \
    login/login_initial.cpp \
    login/login_retrieve_first.cpp \
    login/login_retrieve_password.cpp \
    login/login_retrieve_second.cpp \
    login/login_retrieve_third.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow/mainwindow_connect.cpp \
    mainwindow/mainwindow_initial.cpp \
    mainwindow/mainwindow_slot.cpp \
    monitor/monitor.cpp \
    monitor/monitor_initial.cpp \
    monitor/monitor_label.cpp \
    monitor/monitor_spinbox.cpp \
    serial/serial_config.cpp \
    serial/serial_fixedquery.cpp \
    serial/serial_initial.cpp \
    serial/serial_setquery.cpp \
    serial/serial_slot.cpp \
    tcp/tcp_query.cpp \

HEADERS += \
    communication/communication.h \
    core/data_processing.h \
    core/enum.h \
    core/spic_command.h \
    login/login.h \
    login/login_create_account.h \
    login/login_retrieve_password.h \
    mainwindow.h \
    monitor/monitor.h \
    monitor/monitor_label.h \
    monitor/monitor_spinbox.h \
    pytest/pytest_agreement_api.h \
    pytest/pytest_agreement_test.h \
    pytest/pytest_intro_api.h \
    pytest/pytest_intro_test.h \
    pytest/pytest_print.h \
    pytest/pytest_print_test.h \
    pytest/pytest_spec_datatype_api.h \
    pytest/pytest_spec_funcobj_api.h \
    pytest/pytest_spec_objlayer_test.h \
    pytest/pytest_tool_api.h \
    pytest/pytest_tool_test.h \
    pytest/pytest_useful_macro_api.h \
    pytest/pytest_useful_macro_test.h \
    serial/serial_config.h \
    serial/serial_fixedquery.h \
    serial/serial_setquery.h \
    tcp/tcp_query.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
                images.qrc \
                trans.qrc

DISTFILES += \
                readme.txt \
                pytest/test_function.py \
                pytest/test_plot.py \
                pytest/test_python.py \
                pytest/test_class.py

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../AppData/Local/Programs/Python/Python37-32/libs/ -lpython37
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../AppData/Local/Programs/Python/Python37-32/libs/ -lpython37d

INCLUDEPATH += $$PWD/../../AppData/Local/Programs/Python/Python37-32/libs
DEPENDPATH += $$PWD/../../AppData/Local/Programs/Python/Python37-32/libs

INCLUDEPATH += $$PWD/../../AppData/Local/Programs/Python/Python37-32/include
DEPENDPATH += $$PWD/../../AppData/Local/Programs/Python/Python37-32/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../AppData/Local/Programs/Python/Python37-32/libs/libpython37.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../AppData/Local/Programs/Python/Python37-32/libs/libpython37d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../AppData/Local/Programs/Python/Python37-32/libs/python37.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../AppData/Local/Programs/Python/Python37-32/libs/python37d.lib
