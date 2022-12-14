/****************************************************************************
** Meta object code from reading C++ file 'tcp_query.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcp/tcp_query.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp_query.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpQuery_t {
    QByteArrayData data[21];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpQuery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpQuery_t qt_meta_stringdata_TcpQuery = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TcpQuery"
QT_MOC_LITERAL(1, 9, 12), // "setRoleValue"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "SETTINGVARIABLE"
QT_MOC_LITERAL(4, 39, 4), // "role"
QT_MOC_LITERAL(5, 44, 7), // "request"
QT_MOC_LITERAL(6, 52, 14), // "selectedPeriod"
QT_MOC_LITERAL(7, 67, 2), // "ms"
QT_MOC_LITERAL(8, 70, 1), // "s"
QT_MOC_LITERAL(9, 72, 1), // "m"
QT_MOC_LITERAL(10, 74, 1), // "h"
QT_MOC_LITERAL(11, 76, 9), // "connected"
QT_MOC_LITERAL(12, 86, 12), // "disconnected"
QT_MOC_LITERAL(13, 99, 9), // "errorCode"
QT_MOC_LITERAL(14, 109, 13), // "TCPERRORSTATE"
QT_MOC_LITERAL(15, 123, 4), // "code"
QT_MOC_LITERAL(16, 128, 11), // "TIMEOUTCODE"
QT_MOC_LITERAL(17, 140, 17), // "tcpFixedQueryData"
QT_MOC_LITERAL(18, 158, 4), // "data"
QT_MOC_LITERAL(19, 163, 15), // "tcpSetQueryData"
QT_MOC_LITERAL(20, 179, 3) // "ret"

    },
    "TcpQuery\0setRoleValue\0\0SETTINGVARIABLE\0"
    "role\0request\0selectedPeriod\0ms\0s\0m\0h\0"
    "connected\0disconnected\0errorCode\0"
    "TCPERRORSTATE\0code\0TIMEOUTCODE\0"
    "tcpFixedQueryData\0data\0tcpSetQueryData\0"
    "ret"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpQuery[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       6,    4,   74,    2, 0x06 /* Public */,
       6,    3,   83,    2, 0x26 /* Public | MethodCloned */,
       6,    2,   90,    2, 0x26 /* Public | MethodCloned */,
       6,    1,   95,    2, 0x26 /* Public | MethodCloned */,
      11,    0,   98,    2, 0x06 /* Public */,
      12,    0,   99,    2, 0x06 /* Public */,
      13,    1,  100,    2, 0x06 /* Public */,
      13,    1,  103,    2, 0x06 /* Public */,
      17,    1,  106,    2, 0x06 /* Public */,
      19,    2,  109,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,    5,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    7,    8,    9,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    7,    8,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 16,   15,
    QMetaType::Void, QMetaType::QByteArrayList,   18,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3,   20,    4,

       0        // eod
};

void TcpQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpQuery *_t = static_cast<TcpQuery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRoleValue((*reinterpret_cast< SETTINGVARIABLE(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 2: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 3: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 4: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 5: _t->connected(); break;
        case 6: _t->disconnected(); break;
        case 7: _t->errorCode((*reinterpret_cast< TCPERRORSTATE(*)>(_a[1]))); break;
        case 8: _t->errorCode((*reinterpret_cast< TIMEOUTCODE(*)>(_a[1]))); break;
        case 9: _t->tcpFixedQueryData((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 10: _t->tcpSetQueryData((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< SETTINGVARIABLE(*)>(_a[2]))); break;
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
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TCPERRORSTATE >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TIMEOUTCODE >(); break;
            }
            break;
        case 10:
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
            typedef void (TcpQuery::*_t)(SETTINGVARIABLE , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpQuery::setRoleValue)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpQuery::*_t)(quint32 , quint32 , quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpQuery::selectedPeriod)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpQuery::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpQuery::connected)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (TcpQuery::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpQuery::disconnected)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (TcpQuery::*_t)(TCPERRORSTATE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpQuery::errorCode)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (TcpQuery::*_t)(TIMEOUTCODE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpQuery::errorCode)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (TcpQuery::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpQuery::tcpFixedQueryData)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (TcpQuery::*_t)(bool , SETTINGVARIABLE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpQuery::tcpSetQueryData)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject TcpQuery::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TcpQuery.data,
      qt_meta_data_TcpQuery,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TcpQuery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpQuery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpQuery.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpQuery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TcpQuery::setRoleValue(SETTINGVARIABLE _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpQuery::selectedPeriod(quint32 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 5
void TcpQuery::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void TcpQuery::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void TcpQuery::errorCode(TCPERRORSTATE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TcpQuery::errorCode(TIMEOUTCODE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TcpQuery::tcpFixedQueryData(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void TcpQuery::tcpSetQueryData(bool _t1, SETTINGVARIABLE _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
