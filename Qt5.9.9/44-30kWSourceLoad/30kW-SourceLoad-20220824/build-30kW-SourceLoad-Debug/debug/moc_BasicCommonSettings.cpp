/****************************************************************************
** Meta object code from reading C++ file 'BasicCommonSettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dialog/BasicCommonSettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BasicCommonSettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommonSettings_t {
    QByteArrayData data[11];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommonSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommonSettings_t qt_meta_stringdata_CommonSettings = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CommonSettings"
QT_MOC_LITERAL(1, 15, 11), // "on_workMode"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "index"
QT_MOC_LITERAL(4, 34, 21), // "on_voltageRisingSlope"
QT_MOC_LITERAL(5, 56, 1), // "d"
QT_MOC_LITERAL(6, 58, 22), // "on_voltageDropingSlope"
QT_MOC_LITERAL(7, 81, 21), // "on_currentRisingSlope"
QT_MOC_LITERAL(8, 103, 22), // "on_currentDropingSlope"
QT_MOC_LITERAL(9, 126, 18), // "on_DcOutputDelayOn"
QT_MOC_LITERAL(10, 145, 19) // "on_DcOutputDelayOff"

    },
    "CommonSettings\0on_workMode\0\0index\0"
    "on_voltageRisingSlope\0d\0on_voltageDropingSlope\0"
    "on_currentRisingSlope\0on_currentDropingSlope\0"
    "on_DcOutputDelayOn\0on_DcOutputDelayOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommonSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x08 /* Private */,
       6,    1,   55,    2, 0x08 /* Private */,
       7,    1,   58,    2, 0x08 /* Private */,
       8,    1,   61,    2, 0x08 /* Private */,
       9,    1,   64,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    5,

       0        // eod
};

void CommonSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CommonSettings *_t = static_cast<CommonSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_workMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_voltageRisingSlope((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_voltageDropingSlope((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_currentRisingSlope((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_currentDropingSlope((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_DcOutputDelayOn((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_DcOutputDelayOff((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CommonSettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CommonSettings.data,
      qt_meta_data_CommonSettings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CommonSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommonSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommonSettings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CommonSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
