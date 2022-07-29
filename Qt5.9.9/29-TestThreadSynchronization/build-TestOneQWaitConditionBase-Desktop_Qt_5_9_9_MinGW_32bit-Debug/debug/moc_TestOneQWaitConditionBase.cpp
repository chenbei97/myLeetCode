/****************************************************************************
** Meta object code from reading C++ file 'TestOneQWaitConditionBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestOneQWaitConditionBase/TestOneQWaitConditionBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestOneQWaitConditionBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestOneQWaitConditionBase_t {
    QByteArrayData data[12];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestOneQWaitConditionBase_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestOneQWaitConditionBase_t qt_meta_stringdata_TestOneQWaitConditionBase = {
    {
QT_MOC_LITERAL(0, 0, 25), // "TestOneQWaitConditionBase"
QT_MOC_LITERAL(1, 26, 25), // "on_btnStartThread_clicked"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 24), // "on_btnStopThread_clicked"
QT_MOC_LITERAL(4, 78, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(5, 98, 25), // "on_producerThread_started"
QT_MOC_LITERAL(6, 124, 25), // "on_consumerThread_started"
QT_MOC_LITERAL(7, 150, 25), // "on_producerThread_finshed"
QT_MOC_LITERAL(8, 176, 25), // "on_consumerThread_finshed"
QT_MOC_LITERAL(9, 202, 31), // "on_producerThread_readDiceValue"
QT_MOC_LITERAL(10, 234, 9), // "frequency"
QT_MOC_LITERAL(11, 244, 9) // "diceValue"

    },
    "TestOneQWaitConditionBase\0"
    "on_btnStartThread_clicked\0\0"
    "on_btnStopThread_clicked\0on_btnClear_clicked\0"
    "on_producerThread_started\0"
    "on_consumerThread_started\0"
    "on_producerThread_finshed\0"
    "on_consumerThread_finshed\0"
    "on_producerThread_readDiceValue\0"
    "frequency\0diceValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestOneQWaitConditionBase[] = {

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
       9,    2,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,

       0        // eod
};

void TestOneQWaitConditionBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestOneQWaitConditionBase *_t = static_cast<TestOneQWaitConditionBase *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnStartThread_clicked(); break;
        case 1: _t->on_btnStopThread_clicked(); break;
        case 2: _t->on_btnClear_clicked(); break;
        case 3: _t->on_producerThread_started(); break;
        case 4: _t->on_consumerThread_started(); break;
        case 5: _t->on_producerThread_finshed(); break;
        case 6: _t->on_consumerThread_finshed(); break;
        case 7: _t->on_producerThread_readDiceValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject TestOneQWaitConditionBase::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestOneQWaitConditionBase.data,
      qt_meta_data_TestOneQWaitConditionBase,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestOneQWaitConditionBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestOneQWaitConditionBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestOneQWaitConditionBase.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestOneQWaitConditionBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
