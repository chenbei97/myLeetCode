/****************************************************************************
** Meta object code from reading C++ file 'serial_fixedquery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serial/serial_fixedquery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serial_fixedquery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialFixedQueryThread_t {
    QByteArrayData data[14];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialFixedQueryThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialFixedQueryThread_t qt_meta_stringdata_SerialFixedQueryThread = {
    {
QT_MOC_LITERAL(0, 0, 22), // "SerialFixedQueryThread"
QT_MOC_LITERAL(1, 23, 12), // "setRoleValue"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 15), // "SETTINGVARIABLE"
QT_MOC_LITERAL(4, 53, 4), // "role"
QT_MOC_LITERAL(5, 58, 5), // "value"
QT_MOC_LITERAL(6, 64, 18), // "portFixedQueryData"
QT_MOC_LITERAL(7, 83, 4), // "data"
QT_MOC_LITERAL(8, 88, 16), // "portSetQueryData"
QT_MOC_LITERAL(9, 105, 3), // "ret"
QT_MOC_LITERAL(10, 109, 9), // "errorCode"
QT_MOC_LITERAL(11, 119, 11), // "TIMEOUTCODE"
QT_MOC_LITERAL(12, 131, 4), // "code"
QT_MOC_LITERAL(13, 136, 11) // "SERIALERROR"

    },
    "SerialFixedQueryThread\0setRoleValue\0"
    "\0SETTINGVARIABLE\0role\0value\0"
    "portFixedQueryData\0data\0portSetQueryData\0"
    "ret\0errorCode\0TIMEOUTCODE\0code\0"
    "SERIALERROR"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialFixedQueryThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       6,    1,   44,    2, 0x06 /* Public */,
       8,    2,   47,    2, 0x06 /* Public */,
      10,    1,   52,    2, 0x06 /* Public */,
      10,    1,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,    5,
    QMetaType::Void, QMetaType::QByteArrayList,    7,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3,    9,    4,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 13,   12,

       0        // eod
};

void SerialFixedQueryThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialFixedQueryThread *_t = static_cast<SerialFixedQueryThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRoleValue((*reinterpret_cast< SETTINGVARIABLE(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->portFixedQueryData((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 2: _t->portSetQueryData((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< SETTINGVARIABLE(*)>(_a[2]))); break;
        case 3: _t->errorCode((*reinterpret_cast< TIMEOUTCODE(*)>(_a[1]))); break;
        case 4: _t->errorCode((*reinterpret_cast< SERIALERROR(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SETTINGVARIABLE >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SETTINGVARIABLE >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TIMEOUTCODE >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SERIALERROR >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SerialFixedQueryThread::*_t)(SETTINGVARIABLE , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFixedQueryThread::setRoleValue)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SerialFixedQueryThread::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFixedQueryThread::portFixedQueryData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SerialFixedQueryThread::*_t)(bool , SETTINGVARIABLE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFixedQueryThread::portSetQueryData)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SerialFixedQueryThread::*_t)(TIMEOUTCODE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFixedQueryThread::errorCode)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (SerialFixedQueryThread::*_t)(SERIALERROR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFixedQueryThread::errorCode)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject SerialFixedQueryThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SerialFixedQueryThread.data,
      qt_meta_data_SerialFixedQueryThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialFixedQueryThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialFixedQueryThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialFixedQueryThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int SerialFixedQueryThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void SerialFixedQueryThread::setRoleValue(SETTINGVARIABLE _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialFixedQueryThread::portFixedQueryData(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialFixedQueryThread::portSetQueryData(bool _t1, SETTINGVARIABLE _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialFixedQueryThread::errorCode(TIMEOUTCODE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SerialFixedQueryThread::errorCode(SERIALERROR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
