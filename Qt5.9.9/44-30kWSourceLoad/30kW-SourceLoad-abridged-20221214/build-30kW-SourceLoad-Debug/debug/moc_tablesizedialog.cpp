/****************************************************************************
** Meta object code from reading C++ file 'tablesizedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../table/tablesizedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tablesizedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TableSizeDialog_t {
    QByteArrayData data[8];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TableSizeDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TableSizeDialog_t qt_meta_stringdata_TableSizeDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TableSizeDialog"
QT_MOC_LITERAL(1, 16, 20), // "customTableNotImport"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 20), // "customTableUseImport"
QT_MOC_LITERAL(4, 59, 12), // "QStringList&"
QT_MOC_LITERAL(5, 72, 13), // "unCustomTable"
QT_MOC_LITERAL(6, 86, 15), // "workModeChanged"
QT_MOC_LITERAL(7, 102, 8) // "WORKMODE"

    },
    "TableSizeDialog\0customTableNotImport\0"
    "\0customTableUseImport\0QStringList&\0"
    "unCustomTable\0workModeChanged\0WORKMODE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TableSizeDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       5,    0,   38,    2, 0x06 /* Public */,
       6,    1,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void TableSizeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TableSizeDialog *_t = static_cast<TableSizeDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->customTableNotImport(); break;
        case 1: _t->customTableUseImport((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->unCustomTable(); break;
        case 3: _t->workModeChanged((*reinterpret_cast< WORKMODE(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
            typedef void (TableSizeDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableSizeDialog::customTableNotImport)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TableSizeDialog::*_t)(QStringList & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableSizeDialog::customTableUseImport)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TableSizeDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableSizeDialog::unCustomTable)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TableSizeDialog::*_t)(WORKMODE );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableSizeDialog::workModeChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject TableSizeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TableSizeDialog.data,
      qt_meta_data_TableSizeDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TableSizeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableSizeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TableSizeDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TableSizeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TableSizeDialog::customTableNotImport()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TableSizeDialog::customTableUseImport(QStringList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TableSizeDialog::unCustomTable()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TableSizeDialog::workModeChanged(WORKMODE _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
