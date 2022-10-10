/****************************************************************************
** Meta object code from reading C++ file 'tcp_fixedquery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcp/tcp_fixedquery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcp_fixedquery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpFixedQuery_t {
    QByteArrayData data[16];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpFixedQuery_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpFixedQuery_t qt_meta_stringdata_TcpFixedQuery = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TcpFixedQuery"
QT_MOC_LITERAL(1, 14, 12), // "setRoleValue"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "SETTINGVARIABLE"
QT_MOC_LITERAL(4, 44, 4), // "role"
QT_MOC_LITERAL(5, 49, 7), // "request"
QT_MOC_LITERAL(6, 57, 9), // "connected"
QT_MOC_LITERAL(7, 67, 12), // "disconnected"
QT_MOC_LITERAL(8, 80, 9), // "errorCode"
QT_MOC_LITERAL(9, 90, 13), // "TCPERRORSTATE"
QT_MOC_LITERAL(10, 104, 4), // "code"
QT_MOC_LITERAL(11, 109, 11), // "TIMEOUTCODE"
QT_MOC_LITERAL(12, 121, 17), // "tcpFixedQueryData"
QT_MOC_LITERAL(13, 139, 4), // "data"
QT_MOC_LITERAL(14, 144, 15), // "tcpSetQueryData"
QT_MOC_LITERAL(15, 160, 3) // "ret"

    },
    "TcpFixedQuery\0setRoleValue\0\0SETTINGVARIABLE\0"
    "role\0request\0connected\0disconnected\0"
    "errorCode\0TCPERRORSTATE\0code\0TIMEOUTCODE\0"
    "tcpFixedQueryData\0data\0tcpSetQueryData\0"
    "ret"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpFixedQuery[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       6,    0,   54,    2, 0x06 /* Public */,
       7,    0,   55,    2, 0x06 /* Public */,
       8,    1,   56,    2, 0x06 /* Public */,
       8,    1,   59,    2, 0x06 /* Public */,
      12,    1,   62,    2, 0x06 /* Public */,
      14,    2,   65,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 11,   10,
    QMetaType::Void, QMetaType::QByteArrayList,   13,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3,   15,    4,

       0        // eod
};

void TcpFixedQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpFixedQuery *_t = static_cast<TcpFixedQuery *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRoleValue((*reinterpret_cast< SETTINGVARIABLE(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 1: _t->connected(); break;
        case 2: _t->disconnected(); break;
        case 3: _t->errorCode((*reinterpret_cast< TCPERRORSTATE(*)>(_a[1]))); break;
        case 4: _t->errorCode((*reinterpret_cast< TIMEOUTCODE(*)>(_a[1]))); break;
        case 5: _t->tcpFixedQueryData((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 6: _t->tcpSetQueryData((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< SETTINGVARIABLE(*)>(_a[2]))); break;
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
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TCPERRORSTATE >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TIMEOUTCODE >(); break;
            }
            break;
        case 6:
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
            typedef void (TcpFixedQuery::*_t)(SETTINGVARIABLE , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpFixedQuery::setRoleValue)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpFixedQuery::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpFixedQuery::connected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpFixedQuery::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpFixedQuery::disconnected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TcpFixedQuery::*_t)(TCPERRORSTATE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpFixedQuery::errorCode)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TcpFixedQuery::*_t)(TIMEOUTCODE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpFixedQuery::errorCode)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (TcpFixedQuery::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpFixedQuery::tcpFixedQueryData)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (TcpFixedQuery::*_t)(bool , SETTINGVARIABLE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpFixedQuery::tcpSetQueryData)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject TcpFixedQuery::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TcpFixedQuery.data,
      qt_meta_data_TcpFixedQuery,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TcpFixedQuery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpFixedQuery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpFixedQuery.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpFixedQuery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TcpFixedQuery::setRoleValue(SETTINGVARIABLE _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpFixedQuery::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TcpFixedQuery::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TcpFixedQuery::errorCode(TCPERRORSTATE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpFixedQuery::errorCode(TIMEOUTCODE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpFixedQuery::tcpFixedQueryData(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TcpFixedQuery::tcpSetQueryData(bool _t1, SETTINGVARIABLE _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
