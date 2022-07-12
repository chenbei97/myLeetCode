/****************************************************************************
** Meta object code from reading C++ file 'tableItemDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../customDialog/tableItemDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tableItemDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tableItemDialog_t {
    QByteArrayData data[12];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tableItemDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tableItemDialog_t qt_meta_stringdata_tableItemDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "tableItemDialog"
QT_MOC_LITERAL(1, 16, 10), // "rowChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "row"
QT_MOC_LITERAL(4, 32, 13), // "columnChanged"
QT_MOC_LITERAL(5, 46, 21), // "on_btnSetText_clicked"
QT_MOC_LITERAL(6, 68, 19), // "on_btnClose_clicked"
QT_MOC_LITERAL(7, 88, 29), // "on_spinBoxColumn_valueChanged"
QT_MOC_LITERAL(8, 118, 4), // "arg1"
QT_MOC_LITERAL(9, 123, 26), // "on_spinBoxRow_valueChanged"
QT_MOC_LITERAL(10, 150, 10), // "statusShow"
QT_MOC_LITERAL(11, 161, 5) // "index"

    },
    "tableItemDialog\0rowChanged\0\0row\0"
    "columnChanged\0on_btnSetText_clicked\0"
    "on_btnClose_clicked\0on_spinBoxColumn_valueChanged\0"
    "arg1\0on_spinBoxRow_valueChanged\0"
    "statusShow\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tableItemDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   55,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
       9,    1,   60,    2, 0x08 /* Private */,
      10,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QModelIndex,   11,

       0        // eod
};

void tableItemDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tableItemDialog *_t = static_cast<tableItemDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rowChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->columnChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_btnSetText_clicked(); break;
        case 3: _t->on_btnClose_clicked(); break;
        case 4: _t->on_spinBoxColumn_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_spinBoxRow_valueChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->statusShow((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (tableItemDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tableItemDialog::rowChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (tableItemDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tableItemDialog::columnChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject tableItemDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_tableItemDialog.data,
      qt_meta_data_tableItemDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *tableItemDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tableItemDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tableItemDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int tableItemDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void tableItemDialog::rowChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tableItemDialog::columnChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
