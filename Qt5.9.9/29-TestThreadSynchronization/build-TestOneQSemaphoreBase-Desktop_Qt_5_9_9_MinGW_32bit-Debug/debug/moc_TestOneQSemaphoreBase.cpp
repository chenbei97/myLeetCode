/****************************************************************************
** Meta object code from reading C++ file 'TestOneQSemaphoreBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestOneQSemaphoreBase/TestOneQSemaphoreBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestOneQSemaphoreBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestOneQSemaphoreBase_t {
    QByteArrayData data[14];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestOneQSemaphoreBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestOneQSemaphoreBase_t qt_meta_stringdata_TestOneQSemaphoreBase = {
    {
QT_MOC_LITERAL(0, 0, 21), // "TestOneQSemaphoreBase"
QT_MOC_LITERAL(1, 22, 25), // "on_btnStartThread_clicked"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 24), // "on_btnStopThread_clicked"
QT_MOC_LITERAL(4, 74, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(5, 94, 19), // "on_producer_started"
QT_MOC_LITERAL(6, 114, 20), // "on_producer_finished"
QT_MOC_LITERAL(7, 135, 19), // "on_consumer_started"
QT_MOC_LITERAL(8, 155, 20), // "on_consumer_finished"
QT_MOC_LITERAL(9, 176, 20), // "on_consumer_newValue"
QT_MOC_LITERAL(10, 197, 4), // "int*"
QT_MOC_LITERAL(11, 202, 4), // "data"
QT_MOC_LITERAL(12, 207, 5), // "count"
QT_MOC_LITERAL(13, 213, 5) // "bufId"

    },
    "TestOneQSemaphoreBase\0on_btnStartThread_clicked\0"
    "\0on_btnStopThread_clicked\0on_btnClear_clicked\0"
    "on_producer_started\0on_producer_finished\0"
    "on_consumer_started\0on_consumer_finished\0"
    "on_consumer_newValue\0int*\0data\0count\0"
    "bufId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestOneQSemaphoreBase[] = {

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
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    3,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int,   11,   12,   13,

       0        // eod
};

void TestOneQSemaphoreBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestOneQSemaphoreBase *_t = static_cast<TestOneQSemaphoreBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnStartThread_clicked(); break;
        case 1: _t->on_btnStopThread_clicked(); break;
        case 2: _t->on_btnClear_clicked(); break;
        case 3: _t->on_producer_started(); break;
        case 4: _t->on_producer_finished(); break;
        case 5: _t->on_consumer_started(); break;
        case 6: _t->on_consumer_finished(); break;
        case 7: _t->on_consumer_newValue((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject TestOneQSemaphoreBase::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestOneQSemaphoreBase.data,
      qt_meta_data_TestOneQSemaphoreBase,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestOneQSemaphoreBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestOneQSemaphoreBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestOneQSemaphoreBase.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestOneQSemaphoreBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
