/****************************************************************************
** Meta object code from reading C++ file 'data_processing.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../core/data_processing.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'data_processing.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ResponseProcessor_t {
    QByteArrayData data[14];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResponseProcessor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResponseProcessor_t qt_meta_stringdata_ResponseProcessor = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ResponseProcessor"
QT_MOC_LITERAL(1, 18, 10), // "fixedQuery"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "data"
QT_MOC_LITERAL(4, 35, 8), // "setQuery"
QT_MOC_LITERAL(5, 44, 3), // "ret"
QT_MOC_LITERAL(6, 48, 15), // "SETTINGVARIABLE"
QT_MOC_LITERAL(7, 64, 4), // "role"
QT_MOC_LITERAL(8, 69, 14), // "selectedPeriod"
QT_MOC_LITERAL(9, 84, 8), // "uint32_t"
QT_MOC_LITERAL(10, 93, 2), // "ms"
QT_MOC_LITERAL(11, 96, 1), // "s"
QT_MOC_LITERAL(12, 98, 1), // "m"
QT_MOC_LITERAL(13, 100, 1) // "h"

    },
    "ResponseProcessor\0fixedQuery\0\0data\0"
    "setQuery\0ret\0SETTINGVARIABLE\0role\0"
    "selectedPeriod\0uint32_t\0ms\0s\0m\0h"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResponseProcessor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    2,   47,    2, 0x06 /* Public */,
       8,    4,   52,    2, 0x06 /* Public */,
       8,    3,   61,    2, 0x26 /* Public | MethodCloned */,
       8,    2,   68,    2, 0x26 /* Public | MethodCloned */,
       8,    1,   73,    2, 0x26 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArrayList,    3,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 6,    5,    7,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9,   10,   11,   12,   13,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9, 0x80000000 | 9,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 9, 0x80000000 | 9,   10,   11,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void ResponseProcessor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResponseProcessor *_t = static_cast<ResponseProcessor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fixedQuery((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        case 1: _t->setQuery((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< SETTINGVARIABLE(*)>(_a[2]))); break;
        case 2: _t->selectedPeriod((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2])),(*reinterpret_cast< uint32_t(*)>(_a[3])),(*reinterpret_cast< uint32_t(*)>(_a[4]))); break;
        case 3: _t->selectedPeriod((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2])),(*reinterpret_cast< uint32_t(*)>(_a[3]))); break;
        case 4: _t->selectedPeriod((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2]))); break;
        case 5: _t->selectedPeriod((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            typedef void (ResponseProcessor::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResponseProcessor::fixedQuery)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ResponseProcessor::*_t)(bool , SETTINGVARIABLE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResponseProcessor::setQuery)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ResponseProcessor::*_t)(uint32_t , uint32_t , uint32_t , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ResponseProcessor::selectedPeriod)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ResponseProcessor::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ResponseProcessor.data,
      qt_meta_data_ResponseProcessor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ResponseProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResponseProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ResponseProcessor.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ResponseProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ResponseProcessor::fixedQuery(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ResponseProcessor::setQuery(bool _t1, SETTINGVARIABLE _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ResponseProcessor::selectedPeriod(uint32_t _t1, uint32_t _t2, uint32_t _t3, uint32_t _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
