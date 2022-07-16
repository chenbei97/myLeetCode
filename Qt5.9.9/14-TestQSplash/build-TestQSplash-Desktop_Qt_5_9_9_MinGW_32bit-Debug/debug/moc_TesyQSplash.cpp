/****************************************************************************
** Meta object code from reading C++ file 'TesyQSplash.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestQSplash/TestQSplash.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TesyQSplash.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TesyQSplash_t {
    QByteArrayData data[14];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TesyQSplash_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TesyQSplash_t qt_meta_stringdata_TesyQSplash = {
    {
QT_MOC_LITERAL(0, 0, 11), // "TesyQSplash"
QT_MOC_LITERAL(1, 12, 23), // "on_actDoc_New_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 24), // "on_actDoc_Open_triggered"
QT_MOC_LITERAL(4, 62, 20), // "on_actFont_triggered"
QT_MOC_LITERAL(5, 83, 19), // "on_actCut_triggered"
QT_MOC_LITERAL(6, 103, 20), // "on_actCopy_triggered"
QT_MOC_LITERAL(7, 124, 21), // "on_actPaste_triggered"
QT_MOC_LITERAL(8, 146, 24), // "on_actCloseALL_triggered"
QT_MOC_LITERAL(9, 171, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(10, 199, 5), // "index"
QT_MOC_LITERAL(11, 205, 15), // "afterFileOpened"
QT_MOC_LITERAL(12, 221, 8), // "QString&"
QT_MOC_LITERAL(13, 230, 9) // "aFileName"

    },
    "TesyQSplash\0on_actDoc_New_triggered\0"
    "\0on_actDoc_Open_triggered\0"
    "on_actFont_triggered\0on_actCut_triggered\0"
    "on_actCopy_triggered\0on_actPaste_triggered\0"
    "on_actCloseALL_triggered\0"
    "on_tabWidget_currentChanged\0index\0"
    "afterFileOpened\0QString&\0aFileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TesyQSplash[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      11,    1,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void TesyQSplash::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TesyQSplash *_t = static_cast<TesyQSplash *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actDoc_New_triggered(); break;
        case 1: _t->on_actDoc_Open_triggered(); break;
        case 2: _t->on_actFont_triggered(); break;
        case 3: _t->on_actCut_triggered(); break;
        case 4: _t->on_actCopy_triggered(); break;
        case 5: _t->on_actPaste_triggered(); break;
        case 6: _t->on_actCloseALL_triggered(); break;
        case 7: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->afterFileOpened((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TesyQSplash::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TesyQSplash.data,
      qt_meta_data_TesyQSplash,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TesyQSplash::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TesyQSplash::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TesyQSplash.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TesyQSplash::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
