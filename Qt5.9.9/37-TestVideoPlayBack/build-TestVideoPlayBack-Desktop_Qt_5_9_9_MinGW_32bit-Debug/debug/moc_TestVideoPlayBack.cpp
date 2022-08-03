/****************************************************************************
** Meta object code from reading C++ file 'TestVideoPlayBack.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestVideoPlayBack/TestVideoPlayBack.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestVideoPlayBack.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestVideoPlayBack_t {
    QByteArrayData data[9];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestVideoPlayBack_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestVideoPlayBack_t qt_meta_stringdata_TestVideoPlayBack = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TestVideoPlayBack"
QT_MOC_LITERAL(1, 18, 27), // "on_actVideoWidget_triggered"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 33), // "on_actGraphicsVideoItem_trigg..."
QT_MOC_LITERAL(4, 81, 18), // "onAct1WindowClosed"
QT_MOC_LITERAL(5, 100, 5), // "close"
QT_MOC_LITERAL(6, 106, 18), // "onAct2WindowClosed"
QT_MOC_LITERAL(7, 125, 18), // "onAct3WindowClosed"
QT_MOC_LITERAL(8, 144, 29) // "on_actOperateCamera_triggered"

    },
    "TestVideoPlayBack\0on_actVideoWidget_triggered\0"
    "\0on_actGraphicsVideoItem_triggered\0"
    "onAct1WindowClosed\0close\0onAct2WindowClosed\0"
    "onAct3WindowClosed\0on_actOperateCamera_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestVideoPlayBack[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       6,    1,   49,    2, 0x08 /* Private */,
       7,    1,   52,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,

       0        // eod
};

void TestVideoPlayBack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestVideoPlayBack *_t = static_cast<TestVideoPlayBack *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actVideoWidget_triggered(); break;
        case 1: _t->on_actGraphicsVideoItem_triggered(); break;
        case 2: _t->onAct1WindowClosed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onAct2WindowClosed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onAct3WindowClosed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_actOperateCamera_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject TestVideoPlayBack::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestVideoPlayBack.data,
      qt_meta_data_TestVideoPlayBack,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestVideoPlayBack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestVideoPlayBack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestVideoPlayBack.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestVideoPlayBack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
