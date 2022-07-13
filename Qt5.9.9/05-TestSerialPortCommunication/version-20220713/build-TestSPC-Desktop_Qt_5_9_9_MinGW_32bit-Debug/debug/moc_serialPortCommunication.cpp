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
    QByteArrayData data[20];
    char stringdata0[429];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPortCommunication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPortCommunication_t qt_meta_stringdata_SerialPortCommunication = {
    {
QT_MOC_LITERAL(0, 0, 23), // "SerialPortCommunication"
QT_MOC_LITERAL(1, 24, 14), // "on_sendCommand"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 7), // "command"
QT_MOC_LITERAL(4, 48, 10), // "fixedQuery"
QT_MOC_LITERAL(5, 59, 22), // "on_Input1_valueChanged"
QT_MOC_LITERAL(6, 82, 4), // "arg1"
QT_MOC_LITERAL(7, 87, 24), // "on_Input2PS_valueChanged"
QT_MOC_LITERAL(8, 112, 24), // "on_Input2EL_valueChanged"
QT_MOC_LITERAL(9, 137, 26), // "on_powInputEL_valueChanged"
QT_MOC_LITERAL(10, 164, 26), // "on_powInputPS_valueChanged"
QT_MOC_LITERAL(11, 191, 26), // "on_openPowerSupply_clicked"
QT_MOC_LITERAL(12, 218, 27), // "on_closePowerSupply_clicked"
QT_MOC_LITERAL(13, 246, 36), // "on_serialNameBox_currentIndex..."
QT_MOC_LITERAL(14, 283, 40), // "on_serialBaudRateBox_currentI..."
QT_MOC_LITERAL(15, 324, 25), // "on_openSerialPort_clicked"
QT_MOC_LITERAL(16, 350, 26), // "on_closeSerialPort_clicked"
QT_MOC_LITERAL(17, 377, 16), // "on_rbtCV_clicked"
QT_MOC_LITERAL(18, 394, 16), // "on_rbtCC_clicked"
QT_MOC_LITERAL(19, 411, 17) // "receive_port_data"

    },
    "SerialPortCommunication\0on_sendCommand\0"
    "\0command\0fixedQuery\0on_Input1_valueChanged\0"
    "arg1\0on_Input2PS_valueChanged\0"
    "on_Input2EL_valueChanged\0"
    "on_powInputEL_valueChanged\0"
    "on_powInputPS_valueChanged\0"
    "on_openPowerSupply_clicked\0"
    "on_closePowerSupply_clicked\0"
    "on_serialNameBox_currentIndexChanged\0"
    "on_serialBaudRateBox_currentIndexChanged\0"
    "on_openSerialPort_clicked\0"
    "on_closeSerialPort_clicked\0on_rbtCV_clicked\0"
    "on_rbtCC_clicked\0receive_port_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPortCommunication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       4,    0,   97,    2, 0x08 /* Private */,
       5,    1,   98,    2, 0x08 /* Private */,
       7,    1,  101,    2, 0x08 /* Private */,
       8,    1,  104,    2, 0x08 /* Private */,
       9,    1,  107,    2, 0x08 /* Private */,
      10,    1,  110,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    1,  115,    2, 0x08 /* Private */,
      14,    1,  118,    2, 0x08 /* Private */,
      15,    0,  121,    2, 0x08 /* Private */,
      16,    0,  122,    2, 0x08 /* Private */,
      17,    0,  123,    2, 0x08 /* Private */,
      18,    0,  124,    2, 0x08 /* Private */,
      19,    0,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
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
        case 0: _t->on_sendCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->fixedQuery(); break;
        case 2: _t->on_Input1_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_Input2PS_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_Input2EL_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_powInputEL_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_powInputPS_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_openPowerSupply_clicked(); break;
        case 8: _t->on_closePowerSupply_clicked(); break;
        case 9: _t->on_serialNameBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_serialBaudRateBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_openSerialPort_clicked(); break;
        case 12: _t->on_closeSerialPort_clicked(); break;
        case 13: _t->on_rbtCV_clicked(); break;
        case 14: _t->on_rbtCC_clicked(); break;
        case 15: _t->receive_port_data(); break;
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
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
