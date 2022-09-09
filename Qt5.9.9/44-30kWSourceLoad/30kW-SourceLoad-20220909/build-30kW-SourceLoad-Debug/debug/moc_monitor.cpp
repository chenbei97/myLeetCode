/****************************************************************************
** Meta object code from reading C++ file 'monitor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../monitor/monitor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Monitor_t {
    QByteArrayData data[26];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Monitor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Monitor_t qt_meta_stringdata_Monitor = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Monitor"
QT_MOC_LITERAL(1, 8, 16), // "powSourceChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "value"
QT_MOC_LITERAL(4, 32, 14), // "powLoadChanged"
QT_MOC_LITERAL(5, 47, 16), // "resSourceChanged"
QT_MOC_LITERAL(6, 64, 14), // "resLoadChanged"
QT_MOC_LITERAL(7, 79, 11), // "voltChanged"
QT_MOC_LITERAL(8, 91, 17), // "currSourceChanged"
QT_MOC_LITERAL(9, 109, 15), // "currLoadChanged"
QT_MOC_LITERAL(10, 125, 11), // "currChanged"
QT_MOC_LITERAL(11, 137, 17), // "voltSourceChanged"
QT_MOC_LITERAL(12, 155, 15), // "voltLoadChanged"
QT_MOC_LITERAL(13, 171, 11), // "eventFilter"
QT_MOC_LITERAL(14, 183, 10), // "watchedObj"
QT_MOC_LITERAL(15, 194, 7), // "QEvent*"
QT_MOC_LITERAL(16, 202, 5), // "event"
QT_MOC_LITERAL(17, 208, 40), // "on_Communication_AvailableFix..."
QT_MOC_LITERAL(18, 249, 4), // "data"
QT_MOC_LITERAL(19, 254, 26), // "on_Communication_ErrorCode"
QT_MOC_LITERAL(20, 281, 11), // "SERIALERROR"
QT_MOC_LITERAL(21, 293, 4), // "code"
QT_MOC_LITERAL(22, 298, 11), // "TIMEOUTCODE"
QT_MOC_LITERAL(23, 310, 6), // "failed"
QT_MOC_LITERAL(24, 317, 15), // "SETTINGVARIABLE"
QT_MOC_LITERAL(25, 333, 4) // "role"

    },
    "Monitor\0powSourceChanged\0\0value\0"
    "powLoadChanged\0resSourceChanged\0"
    "resLoadChanged\0voltChanged\0currSourceChanged\0"
    "currLoadChanged\0currChanged\0"
    "voltSourceChanged\0voltLoadChanged\0"
    "eventFilter\0watchedObj\0QEvent*\0event\0"
    "on_Communication_AvailableFixedQueryData\0"
    "data\0on_Communication_ErrorCode\0"
    "SERIALERROR\0code\0TIMEOUTCODE\0failed\0"
    "SETTINGVARIABLE\0role"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Monitor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    1,   95,    2, 0x06 /* Public */,
       6,    1,   98,    2, 0x06 /* Public */,
       7,    1,  101,    2, 0x06 /* Public */,
       8,    1,  104,    2, 0x06 /* Public */,
       9,    1,  107,    2, 0x06 /* Public */,
      10,    1,  110,    2, 0x06 /* Public */,
      11,    1,  113,    2, 0x06 /* Public */,
      12,    1,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,  119,    2, 0x0a /* Public */,
      17,    1,  124,    2, 0x0a /* Public */,
      19,    1,  127,    2, 0x0a /* Public */,
      19,    1,  130,    2, 0x0a /* Public */,
      19,    2,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 15,   14,   16,
    QMetaType::Void, QMetaType::QByteArrayList,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 22,   21,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 24,   23,   25,

       0        // eod
};

void Monitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Monitor *_t = static_cast<Monitor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->powSourceChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->powLoadChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->resSourceChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->resLoadChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->voltChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->currSourceChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->currLoadChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->currChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->voltSourceChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->voltLoadChanged((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->on_Communication_AvailableFixedQueryData((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 12: _t->on_Communication_ErrorCode((*reinterpret_cast< SERIALERROR(*)>(_a[1]))); break;
        case 13: _t->on_Communication_ErrorCode((*reinterpret_cast< TIMEOUTCODE(*)>(_a[1]))); break;
        case 14: _t->on_Communication_ErrorCode((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< SETTINGVARIABLE(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SERIALERROR >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TIMEOUTCODE >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SETTINGVARIABLE >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::powSourceChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::powLoadChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::resSourceChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::resLoadChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::voltChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::currSourceChanged)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::currLoadChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::currChanged)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::voltSourceChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Monitor::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Monitor::voltLoadChanged)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject Monitor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Monitor.data,
      qt_meta_data_Monitor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Monitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Monitor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Monitor.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Monitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Monitor::powSourceChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Monitor::powLoadChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Monitor::resSourceChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Monitor::resLoadChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Monitor::voltChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Monitor::currSourceChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Monitor::currLoadChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Monitor::currChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Monitor::voltSourceChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Monitor::voltLoadChanged(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
