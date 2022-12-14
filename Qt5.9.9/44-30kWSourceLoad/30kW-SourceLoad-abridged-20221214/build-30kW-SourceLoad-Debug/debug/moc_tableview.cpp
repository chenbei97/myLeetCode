/****************************************************************************
** Meta object code from reading C++ file 'tableview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../table/tableview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tableview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TableView_t {
    QByteArrayData data[10];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TableView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TableView_t qt_meta_stringdata_TableView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TableView"
QT_MOC_LITERAL(1, 10, 15), // "workModeChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "WORKMODE"
QT_MOC_LITERAL(4, 36, 14), // "selectedPeriod"
QT_MOC_LITERAL(5, 51, 2), // "ms"
QT_MOC_LITERAL(6, 54, 1), // "s"
QT_MOC_LITERAL(7, 56, 1), // "m"
QT_MOC_LITERAL(8, 58, 1), // "h"
QT_MOC_LITERAL(9, 60, 3) // "log"

    },
    "TableView\0workModeChanged\0\0WORKMODE\0"
    "selectedPeriod\0ms\0s\0m\0h\0log"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TableView[] = {

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
       4,    4,   47,    2, 0x06 /* Public */,
       4,    3,   56,    2, 0x26 /* Public | MethodCloned */,
       4,    2,   63,    2, 0x26 /* Public | MethodCloned */,
       4,    1,   68,    2, 0x26 /* Public | MethodCloned */,
       9,    1,   71,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    5,    6,    7,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    5,    6,
    QMetaType::Void, QMetaType::UInt,    5,
    QMetaType::Void, QMetaType::QByteArrayList,    2,

       0        // eod
};

void TableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TableView *_t = static_cast<TableView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workModeChanged((*reinterpret_cast< WORKMODE(*)>(_a[1]))); break;
        case 1: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4]))); break;
        case 2: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 3: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 4: _t->selectedPeriod((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 5: _t->log((*reinterpret_cast< const QList<QByteArray>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WORKMODE >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TableView::*_t)(WORKMODE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableView::workModeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TableView::*_t)(quint32 , quint32 , quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableView::selectedPeriod)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TableView::*_t)(const QList<QByteArray> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableView::log)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject TableView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TableView.data,
      qt_meta_data_TableView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TableView.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TableView::workModeChanged(WORKMODE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TableView::selectedPeriod(quint32 _t1, quint32 _t2, quint32 _t3, quint32 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 5
void TableView::log(const QList<QByteArray> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
