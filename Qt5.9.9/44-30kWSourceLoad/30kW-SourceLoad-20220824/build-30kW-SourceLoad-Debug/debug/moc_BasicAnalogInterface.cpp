/****************************************************************************
** Meta object code from reading C++ file 'BasicAnalogInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dialog/BasicAnalogInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BasicAnalogInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AnalogInterface_t {
    QByteArrayData data[12];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnalogInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnalogInterface_t qt_meta_stringdata_AnalogInterface = {
    {
QT_MOC_LITERAL(0, 0, 15), // "AnalogInterface"
QT_MOC_LITERAL(1, 16, 16), // "on_remoteControl"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "checked"
QT_MOC_LITERAL(4, 42, 15), // "on_voltageRange"
QT_MOC_LITERAL(5, 58, 5), // "index"
QT_MOC_LITERAL(6, 64, 9), // "on_pinSix"
QT_MOC_LITERAL(7, 74, 14), // "on_pinFourteen"
QT_MOC_LITERAL(8, 89, 13), // "on_pinFifteen"
QT_MOC_LITERAL(9, 103, 8), // "on_vcMon"
QT_MOC_LITERAL(10, 112, 13), // "on_remSBState"
QT_MOC_LITERAL(11, 126, 14) // "on_remSBAction"

    },
    "AnalogInterface\0on_remoteControl\0\0"
    "checked\0on_voltageRange\0index\0on_pinSix\0"
    "on_pinFourteen\0on_pinFifteen\0on_vcMon\0"
    "on_remSBState\0on_remSBAction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnalogInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       7,    1,   63,    2, 0x08 /* Private */,
       8,    1,   66,    2, 0x08 /* Private */,
       9,    1,   69,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      11,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void AnalogInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnalogInterface *_t = static_cast<AnalogInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_remoteControl((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_voltageRange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pinSix((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pinFourteen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pinFifteen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_vcMon((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_remSBState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_remSBAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AnalogInterface::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AnalogInterface.data,
      qt_meta_data_AnalogInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AnalogInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnalogInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AnalogInterface.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AnalogInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
