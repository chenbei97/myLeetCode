/****************************************************************************
** Meta object code from reading C++ file 'helloworld.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hello_world/helloworld.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'helloworld.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_helloWorld_t {
    QByteArrayData data[12];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_helloWorld_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_helloWorld_t qt_meta_stringdata_helloWorld = {
    {
QT_MOC_LITERAL(0, 0, 10), // "helloWorld"
QT_MOC_LITERAL(1, 11, 19), // "on_btnclose_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 24), // "on_handsome_stateChanged"
QT_MOC_LITERAL(4, 57, 4), // "arg1"
QT_MOC_LITERAL(5, 62, 29), // "on_sexBox_currentIndexChanged"
QT_MOC_LITERAL(6, 92, 5), // "index"
QT_MOC_LITERAL(7, 98, 24), // "on_actionclose_triggered"
QT_MOC_LITERAL(8, 123, 25), // "on_actionreboot_triggered"
QT_MOC_LITERAL(9, 149, 27), // "on_fontSizeBox_valueChanged"
QT_MOC_LITERAL(10, 177, 8), // "fontsize"
QT_MOC_LITERAL(11, 186, 29) // "on_startProgressbar_triggered"

    },
    "helloWorld\0on_btnclose_clicked\0\0"
    "on_handsome_stateChanged\0arg1\0"
    "on_sexBox_currentIndexChanged\0index\0"
    "on_actionclose_triggered\0"
    "on_actionreboot_triggered\0"
    "on_fontSizeBox_valueChanged\0fontsize\0"
    "on_startProgressbar_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_helloWorld[] = {

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
       3,    1,   50,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    1,   58,    2, 0x08 /* Private */,
      11,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void helloWorld::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        helloWorld *_t = static_cast<helloWorld *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnclose_clicked(); break;
        case 1: _t->on_handsome_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_sexBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_actionclose_triggered(); break;
        case 4: _t->on_actionreboot_triggered(); break;
        case 5: _t->on_fontSizeBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_startProgressbar_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject helloWorld::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_helloWorld.data,
      qt_meta_data_helloWorld,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *helloWorld::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *helloWorld::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_helloWorld.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int helloWorld::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
