/****************************************************************************
** Meta object code from reading C++ file 'serialFixedQueryThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../serialFixedQueryThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialFixedQueryThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_serialFixedQueryThread_t {
    QByteArrayData data[10];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_serialFixedQueryThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_serialFixedQueryThread_t qt_meta_stringdata_serialFixedQueryThread = {
    {
QT_MOC_LITERAL(0, 0, 22), // "serialFixedQueryThread"
QT_MOC_LITERAL(1, 23, 5), // "error"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 1), // "s"
QT_MOC_LITERAL(4, 32, 7), // "timeout"
QT_MOC_LITERAL(5, 40, 5), // "count"
QT_MOC_LITERAL(6, 46, 8), // "response"
QT_MOC_LITERAL(7, 55, 21), // "responseRequesetCount"
QT_MOC_LITERAL(8, 77, 2), // "c1"
QT_MOC_LITERAL(9, 80, 2) // "c2"

    },
    "serialFixedQueryThread\0error\0\0s\0timeout\0"
    "count\0response\0responseRequesetCount\0"
    "c1\0c2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_serialFixedQueryThread[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       7,    2,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    8,    9,

       0        // eod
};

void serialFixedQueryThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        serialFixedQueryThread *_t = static_cast<serialFixedQueryThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->timeout((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 2: _t->response((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->responseRequesetCount((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (serialFixedQueryThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serialFixedQueryThread::error)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (serialFixedQueryThread::*_t)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serialFixedQueryThread::timeout)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (serialFixedQueryThread::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serialFixedQueryThread::response)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (serialFixedQueryThread::*_t)(quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&serialFixedQueryThread::responseRequesetCount)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject serialFixedQueryThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_serialFixedQueryThread.data,
      qt_meta_data_serialFixedQueryThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *serialFixedQueryThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *serialFixedQueryThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_serialFixedQueryThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int serialFixedQueryThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void serialFixedQueryThread::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void serialFixedQueryThread::timeout(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void serialFixedQueryThread::response(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void serialFixedQueryThread::responseRequesetCount(quint32 _t1, quint32 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
