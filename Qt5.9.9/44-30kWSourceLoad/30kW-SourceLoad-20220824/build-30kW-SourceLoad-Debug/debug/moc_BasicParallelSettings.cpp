/****************************************************************************
** Meta object code from reading C++ file 'BasicParallelSettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dialog/BasicParallelSettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BasicParallelSettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParallelSettings_t {
    QByteArrayData data[11];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParallelSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParallelSettings_t qt_meta_stringdata_ParallelSettings = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ParallelSettings"
QT_MOC_LITERAL(1, 17, 6), // "reboot"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "Checked"
QT_MOC_LITERAL(4, 33, 18), // "on_masterSlaveMode"
QT_MOC_LITERAL(5, 52, 5), // "index"
QT_MOC_LITERAL(6, 58, 18), // "on_masterModeState"
QT_MOC_LITERAL(7, 77, 22), // "on_masterModbusAddress"
QT_MOC_LITERAL(8, 100, 5), // "value"
QT_MOC_LITERAL(9, 106, 13), // "on_slaveCount"
QT_MOC_LITERAL(10, 120, 15) // "on_rebootSystem"

    },
    "ParallelSettings\0reboot\0\0Checked\0"
    "on_masterSlaveMode\0index\0on_masterModeState\0"
    "on_masterModbusAddress\0value\0on_slaveCount\0"
    "on_rebootSystem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParallelSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       1,    0,   52,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   53,    2, 0x08 /* Private */,
       6,    1,   56,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void ParallelSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParallelSettings *_t = static_cast<ParallelSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->reboot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->reboot(); break;
        case 2: _t->on_masterSlaveMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_masterModeState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_masterModbusAddress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_slaveCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_rebootSystem(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ParallelSettings::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParallelSettings::reboot)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ParallelSettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ParallelSettings.data,
      qt_meta_data_ParallelSettings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ParallelSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParallelSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParallelSettings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ParallelSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ParallelSettings::reboot(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
