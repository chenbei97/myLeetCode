/****************************************************************************
** Meta object code from reading C++ file 'TestMDI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestMDI/TestMDI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestMDI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestMDI_t {
    QByteArrayData data[16];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestMDI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestMDI_t qt_meta_stringdata_TestMDI = {
    {
QT_MOC_LITERAL(0, 0, 7), // "TestMDI"
QT_MOC_LITERAL(1, 8, 23), // "on_actDoc_New_triggered"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 24), // "on_actDoc_Open_triggered"
QT_MOC_LITERAL(4, 58, 24), // "on_actViewMode_triggered"
QT_MOC_LITERAL(5, 83, 7), // "checked"
QT_MOC_LITERAL(6, 91, 23), // "on_actCascade_triggered"
QT_MOC_LITERAL(7, 115, 20), // "on_actTile_triggered"
QT_MOC_LITERAL(8, 136, 24), // "on_actCloseALL_triggered"
QT_MOC_LITERAL(9, 161, 20), // "on_actFont_triggered"
QT_MOC_LITERAL(10, 182, 20), // "on_actCopy_triggered"
QT_MOC_LITERAL(11, 203, 19), // "on_actCut_triggered"
QT_MOC_LITERAL(12, 223, 21), // "on_actPaste_triggered"
QT_MOC_LITERAL(13, 245, 29), // "on_mdiArea_subWindowActivated"
QT_MOC_LITERAL(14, 275, 14), // "QMdiSubWindow*"
QT_MOC_LITERAL(15, 290, 4) // "arg1"

    },
    "TestMDI\0on_actDoc_New_triggered\0\0"
    "on_actDoc_Open_triggered\0"
    "on_actViewMode_triggered\0checked\0"
    "on_actCascade_triggered\0on_actTile_triggered\0"
    "on_actCloseALL_triggered\0on_actFont_triggered\0"
    "on_actCopy_triggered\0on_actCut_triggered\0"
    "on_actPaste_triggered\0"
    "on_mdiArea_subWindowActivated\0"
    "QMdiSubWindow*\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestMDI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    1,   71,    2, 0x08 /* Private */,
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,
      10,    0,   78,    2, 0x08 /* Private */,
      11,    0,   79,    2, 0x08 /* Private */,
      12,    0,   80,    2, 0x08 /* Private */,
      13,    1,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void TestMDI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestMDI *_t = static_cast<TestMDI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actDoc_New_triggered(); break;
        case 1: _t->on_actDoc_Open_triggered(); break;
        case 2: _t->on_actViewMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_actCascade_triggered(); break;
        case 4: _t->on_actTile_triggered(); break;
        case 5: _t->on_actCloseALL_triggered(); break;
        case 6: _t->on_actFont_triggered(); break;
        case 7: _t->on_actCopy_triggered(); break;
        case 8: _t->on_actCut_triggered(); break;
        case 9: _t->on_actPaste_triggered(); break;
        case 10: _t->on_mdiArea_subWindowActivated((*reinterpret_cast< QMdiSubWindow*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMdiSubWindow* >(); break;
            }
            break;
        }
    }
}

const QMetaObject TestMDI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestMDI.data,
      qt_meta_data_TestMDI,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestMDI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestMDI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestMDI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestMDI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
