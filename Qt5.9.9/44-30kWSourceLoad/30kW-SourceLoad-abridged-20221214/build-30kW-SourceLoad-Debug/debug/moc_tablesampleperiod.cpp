/****************************************************************************
** Meta object code from reading C++ file 'tablesampleperiod.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../table/tablesampleperiod.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tablesampleperiod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TableSamplePeriod_t {
    QByteArrayData data[7];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TableSamplePeriod_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TableSamplePeriod_t qt_meta_stringdata_TableSamplePeriod = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TableSamplePeriod"
QT_MOC_LITERAL(1, 18, 14), // "selectedPeriod"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 2), // "ms"
QT_MOC_LITERAL(4, 37, 1), // "s"
QT_MOC_LITERAL(5, 39, 1), // "m"
QT_MOC_LITERAL(6, 41, 1) // "h"

    },
    "TableSamplePeriod\0selectedPeriod\0\0ms\0"
    "s\0m\0h"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TableSamplePeriod[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x06 /* Public */,
       1,    3,   43,    2, 0x26 /* Public | MethodCloned */,
       1,    2,   50,    2, 0x26 /* Public | MethodCloned */,
       1,    1,   55,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    4,
    QMetaType::Void, QMetaType::UInt,    3,

       0        // eod
};

void TableSamplePeriod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TableSamplePeriod *_t = static_cast<TableSamplePeriod *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 1: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 2: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 3: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TableSamplePeriod::*_t)(quint32 , quint32 , quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableSamplePeriod::selectedPeriod)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TableSamplePeriod::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TableSamplePeriod.data,
      qt_meta_data_TableSamplePeriod,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TableSamplePeriod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableSamplePeriod::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TableSamplePeriod.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TableSamplePeriod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TableSamplePeriod::selectedPeriod(quint32 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
