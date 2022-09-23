/****************************************************************************
** Meta object code from reading C++ file 'communication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../30kW-SourceLoad-abridged/communication/communication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Communication_t {
    QByteArrayData data[17];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Communication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Communication_t qt_meta_stringdata_Communication = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Communication"
QT_MOC_LITERAL(1, 14, 18), // "updatePortSettings"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 12), // "getRoleValue"
QT_MOC_LITERAL(4, 47, 15), // "SETTINGVARIABLE"
QT_MOC_LITERAL(5, 63, 4), // "role"
QT_MOC_LITERAL(6, 68, 5), // "value"
QT_MOC_LITERAL(7, 74, 12), // "setRoleValue"
QT_MOC_LITERAL(8, 87, 14), // "fixedQueryData"
QT_MOC_LITERAL(9, 102, 6), // "values"
QT_MOC_LITERAL(10, 109, 12), // "setQueryData"
QT_MOC_LITERAL(11, 122, 3), // "ret"
QT_MOC_LITERAL(12, 126, 9), // "errorCode"
QT_MOC_LITERAL(13, 136, 11), // "TIMEOUTCODE"
QT_MOC_LITERAL(14, 148, 4), // "code"
QT_MOC_LITERAL(15, 153, 11), // "SERIALERROR"
QT_MOC_LITERAL(16, 165, 13) // "TCPERRORSTATE"

    },
    "Communication\0updatePortSettings\0\0"
    "getRoleValue\0SETTINGVARIABLE\0role\0"
    "value\0setRoleValue\0fixedQueryData\0"
    "values\0setQueryData\0ret\0errorCode\0"
    "TIMEOUTCODE\0code\0SERIALERROR\0TCPERRORSTATE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Communication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    2,   55,    2, 0x06 /* Public */,
       7,    2,   60,    2, 0x06 /* Public */,
       8,    1,   65,    2, 0x06 /* Public */,
      10,    2,   68,    2, 0x06 /* Public */,
      12,    1,   73,    2, 0x06 /* Public */,
      12,    1,   76,    2, 0x06 /* Public */,
      12,    1,   79,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QByteArray,    5,    6,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QByteArray,    5,    6,
    QMetaType::Void, QMetaType::QByteArrayList,    9,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,   11,    5,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 15,   14,
    QMetaType::Void, 0x80000000 | 16,   14,

       0        // eod
};

void Communication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Communication *_t = static_cast<Communication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePortSettings(); break;
        case 1: _t->getRoleValue((*reinterpret_cast< SETTINGVARIABLE(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 2: _t->setRoleValue((*reinterpret_cast< SETTINGVARIABLE(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 3: _t->fixedQueryData((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 4: _t->setQueryData((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< SETTINGVARIABLE(*)>(_a[2]))); break;
        case 5: _t->errorCode((*reinterpret_cast< TIMEOUTCODE(*)>(_a[1]))); break;
        case 6: _t->errorCode((*reinterpret_cast< SERIALERROR(*)>(_a[1]))); break;
        case 7: _t->errorCode((*reinterpret_cast< TCPERRORSTATE(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SETTINGVARIABLE >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SETTINGVARIABLE >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SETTINGVARIABLE >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TIMEOUTCODE >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< SERIALERROR >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TCPERRORSTATE >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Communication::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::updatePortSettings)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(SETTINGVARIABLE , const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::getRoleValue)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(SETTINGVARIABLE , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::setRoleValue)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::fixedQueryData)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(bool , SETTINGVARIABLE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::setQueryData)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(TIMEOUTCODE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::errorCode)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(SERIALERROR );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::errorCode)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Communication::*_t)(TCPERRORSTATE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Communication::errorCode)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject Communication::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Communication.data,
      qt_meta_data_Communication,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Communication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Communication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Communication.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Communication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Communication::updatePortSettings()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Communication::getRoleValue(SETTINGVARIABLE _t1, const QByteArray & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Communication::setRoleValue(SETTINGVARIABLE _t1, QByteArray _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Communication::fixedQueryData(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Communication::setQueryData(bool _t1, SETTINGVARIABLE _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Communication::errorCode(TIMEOUTCODE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Communication::errorCode(SERIALERROR _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Communication::errorCode(TCPERRORSTATE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
