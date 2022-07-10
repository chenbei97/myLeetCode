/****************************************************************************
** Meta object code from reading C++ file 'testQThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestQThread/testQThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testQThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestQThread_t {
    QByteArrayData data[11];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestQThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestQThread_t qt_meta_stringdata_TestQThread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TestQThread"
QT_MOC_LITERAL(1, 12, 25), // "on_btnStartThread_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 24), // "on_btnStopThread_clicked"
QT_MOC_LITERAL(4, 64, 23), // "on_btnDiceBegin_clicked"
QT_MOC_LITERAL(5, 88, 23), // "on_btnDicePause_clicked"
QT_MOC_LITERAL(6, 112, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(7, 132, 18), // "thread_status_show"
QT_MOC_LITERAL(8, 151, 9), // "dice_show"
QT_MOC_LITERAL(9, 161, 3), // "val"
QT_MOC_LITERAL(10, 165, 3) // "fre"

    },
    "TestQThread\0on_btnStartThread_clicked\0"
    "\0on_btnStopThread_clicked\0"
    "on_btnDiceBegin_clicked\0on_btnDicePause_clicked\0"
    "on_btnClear_clicked\0thread_status_show\0"
    "dice_show\0val\0fre"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestQThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    2,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

       0        // eod
};

void TestQThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestQThread *_t = static_cast<TestQThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnStartThread_clicked(); break;
        case 1: _t->on_btnStopThread_clicked(); break;
        case 2: _t->on_btnDiceBegin_clicked(); break;
        case 3: _t->on_btnDicePause_clicked(); break;
        case 4: _t->on_btnClear_clicked(); break;
        case 5: _t->thread_status_show(); break;
        case 6: _t->dice_show((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject TestQThread::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestQThread.data,
      qt_meta_data_TestQThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestQThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestQThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestQThread.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestQThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
