/****************************************************************************
** Meta object code from reading C++ file 'serialPortCommunication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestSPC/serialPortCommunication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialPortCommunication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPortCommunication_t {
    QByteArrayData data[14];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortCommunication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortCommunication_t qt_meta_stringdata_SerialPortCommunication = {
    {
QT_MOC_LITERAL(0, 0, 23), // "SerialPortCommunication"
QT_MOC_LITERAL(1, 24, 17), // "receive_port_data"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 24), // "send_command_to_hardware"
QT_MOC_LITERAL(4, 68, 26), // "receive_data_from_hardware"
QT_MOC_LITERAL(5, 95, 36), // "on_serialNameBox_currentIndex..."
QT_MOC_LITERAL(6, 132, 4), // "arg1"
QT_MOC_LITERAL(7, 137, 40), // "on_serialBaudRateBox_currentI..."
QT_MOC_LITERAL(8, 178, 25), // "on_openSerialPort_clicked"
QT_MOC_LITERAL(9, 204, 26), // "on_closeSerialPort_clicked"
QT_MOC_LITERAL(10, 231, 24), // "on_volInput_valueChanged"
QT_MOC_LITERAL(11, 256, 24), // "on_curInput_valueChanged"
QT_MOC_LITERAL(12, 281, 24), // "on_powInput_valueChanged"
QT_MOC_LITERAL(13, 306, 22) // "on_RInput_valueChanged"

    },
    "SerialPortCommunication\0receive_port_data\0"
    "\0send_command_to_hardware\0"
    "receive_data_from_hardware\0"
    "on_serialNameBox_currentIndexChanged\0"
    "arg1\0on_serialBaudRateBox_currentIndexChanged\0"
    "on_openSerialPort_clicked\0"
    "on_closeSerialPort_clicked\0"
    "on_volInput_valueChanged\0"
    "on_curInput_valueChanged\0"
    "on_powInput_valueChanged\0"
    "on_RInput_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortCommunication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
       8,    0,   78,    2, 0x08 /* Private */,
       9,    0,   79,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      13,    1,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,

       0        // eod
};

void SerialPortCommunication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortCommunication *_t = static_cast<SerialPortCommunication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receive_port_data(); break;
        case 1: _t->send_command_to_hardware(); break;
        case 2: _t->receive_data_from_hardware(); break;
        case 3: _t->on_serialNameBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_serialBaudRateBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_openSerialPort_clicked(); break;
        case 6: _t->on_closeSerialPort_clicked(); break;
        case 7: _t->on_volInput_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_curInput_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_powInput_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_RInput_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SerialPortCommunication::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SerialPortCommunication.data,
      qt_meta_data_SerialPortCommunication,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialPortCommunication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortCommunication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPortCommunication.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SerialPortCommunication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
