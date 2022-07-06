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
    QByteArrayData data[18];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortCommunication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortCommunication_t qt_meta_stringdata_SerialPortCommunication = {
    {
QT_MOC_LITERAL(0, 0, 23), // "SerialPortCommunication"
QT_MOC_LITERAL(1, 24, 25), // "on_openSerialPort_clicked"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 26), // "on_closeSerialPort_clicked"
QT_MOC_LITERAL(4, 78, 17), // "receive_port_data"
QT_MOC_LITERAL(5, 96, 36), // "on_serialNameBox_currentIndex..."
QT_MOC_LITERAL(6, 133, 4), // "arg1"
QT_MOC_LITERAL(7, 138, 40), // "on_serialBaudRateBox_currentI..."
QT_MOC_LITERAL(8, 179, 18), // "send_query_command"
QT_MOC_LITERAL(9, 198, 22), // "on_Input1_valueChanged"
QT_MOC_LITERAL(10, 221, 24), // "on_Input2PS_valueChanged"
QT_MOC_LITERAL(11, 246, 24), // "on_Input2EL_valueChanged"
QT_MOC_LITERAL(12, 271, 26), // "on_powInputEL_valueChanged"
QT_MOC_LITERAL(13, 298, 26), // "on_powInputPS_valueChanged"
QT_MOC_LITERAL(14, 325, 16), // "on_rbtCV_clicked"
QT_MOC_LITERAL(15, 342, 16), // "on_rbtCC_clicked"
QT_MOC_LITERAL(16, 359, 26), // "on_openPowerSupply_clicked"
QT_MOC_LITERAL(17, 386, 27) // "on_closePowerSupply_clicked"

    },
    "SerialPortCommunication\0"
    "on_openSerialPort_clicked\0\0"
    "on_closeSerialPort_clicked\0receive_port_data\0"
    "on_serialNameBox_currentIndexChanged\0"
    "arg1\0on_serialBaudRateBox_currentIndexChanged\0"
    "send_query_command\0on_Input1_valueChanged\0"
    "on_Input2PS_valueChanged\0"
    "on_Input2EL_valueChanged\0"
    "on_powInputEL_valueChanged\0"
    "on_powInputPS_valueChanged\0on_rbtCV_clicked\0"
    "on_rbtCC_clicked\0on_openPowerSupply_clicked\0"
    "on_closePowerSupply_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortCommunication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       7,    1,   95,    2, 0x08 /* Private */,
       8,    0,   98,    2, 0x08 /* Private */,
       9,    1,   99,    2, 0x08 /* Private */,
      10,    1,  102,    2, 0x08 /* Private */,
      11,    1,  105,    2, 0x08 /* Private */,
      12,    1,  108,    2, 0x08 /* Private */,
      13,    1,  111,    2, 0x08 /* Private */,
      14,    0,  114,    2, 0x08 /* Private */,
      15,    0,  115,    2, 0x08 /* Private */,
      16,    0,  116,    2, 0x08 /* Private */,
      17,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SerialPortCommunication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPortCommunication *_t = static_cast<SerialPortCommunication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_openSerialPort_clicked(); break;
        case 1: _t->on_closeSerialPort_clicked(); break;
        case 2: _t->receive_port_data(); break;
        case 3: _t->on_serialNameBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_serialBaudRateBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->send_query_command(); break;
        case 6: _t->on_Input1_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_Input2PS_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_Input2EL_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_powInputEL_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_powInputPS_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_rbtCV_clicked(); break;
        case 12: _t->on_rbtCC_clicked(); break;
        case 13: _t->on_openPowerSupply_clicked(); break;
        case 14: _t->on_closePowerSupply_clicked(); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
