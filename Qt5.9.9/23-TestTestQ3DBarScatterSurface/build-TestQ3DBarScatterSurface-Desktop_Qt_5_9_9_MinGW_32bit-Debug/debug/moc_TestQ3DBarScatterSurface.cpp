/****************************************************************************
** Meta object code from reading C++ file 'TestQ3DBarScatterSurface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestQ3DBarScatterSurface/TestQ3DBarScatterSurface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestQ3DBarScatterSurface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestQ3DBarScatterSurface_t {
    QByteArrayData data[10];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestQ3DBarScatterSurface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestQ3DBarScatterSurface_t qt_meta_stringdata_TestQ3DBarScatterSurface = {
    {
QT_MOC_LITERAL(0, 0, 24), // "TestQ3DBarScatterSurface"
QT_MOC_LITERAL(1, 25, 12), // "mapImageName"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 4), // "name"
QT_MOC_LITERAL(4, 44, 21), // "on_act3DBar_triggered"
QT_MOC_LITERAL(5, 66, 25), // "on_act3DScatter_triggered"
QT_MOC_LITERAL(6, 92, 25), // "on_act3DSurface_triggered"
QT_MOC_LITERAL(7, 118, 21), // "on_act3DMap_triggered"
QT_MOC_LITERAL(8, 140, 20), // "on_actExit_triggered"
QT_MOC_LITERAL(9, 161, 21) // "on_pushButton_clicked"

    },
    "TestQ3DBarScatterSurface\0mapImageName\0"
    "\0name\0on_act3DBar_triggered\0"
    "on_act3DScatter_triggered\0"
    "on_act3DSurface_triggered\0"
    "on_act3DMap_triggered\0on_actExit_triggered\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestQ3DBarScatterSurface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestQ3DBarScatterSurface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestQ3DBarScatterSurface *_t = static_cast<TestQ3DBarScatterSurface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mapImageName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_act3DBar_triggered(); break;
        case 2: _t->on_act3DScatter_triggered(); break;
        case 3: _t->on_act3DSurface_triggered(); break;
        case 4: _t->on_act3DMap_triggered(); break;
        case 5: _t->on_actExit_triggered(); break;
        case 6: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TestQ3DBarScatterSurface::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestQ3DBarScatterSurface::mapImageName)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TestQ3DBarScatterSurface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestQ3DBarScatterSurface.data,
      qt_meta_data_TestQ3DBarScatterSurface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestQ3DBarScatterSurface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestQ3DBarScatterSurface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestQ3DBarScatterSurface.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestQ3DBarScatterSurface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void TestQ3DBarScatterSurface::mapImageName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
