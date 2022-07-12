/****************************************************************************
** Meta object code from reading C++ file 'customDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../customDialog/customDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_customDialog_t {
    QByteArrayData data[21];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customDialog_t qt_meta_stringdata_customDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "customDialog"
QT_MOC_LITERAL(1, 13, 18), // "doubleClickedIndex"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "index"
QT_MOC_LITERAL(4, 39, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(5, 60, 27), // "on_actTab_SetSize_triggered"
QT_MOC_LITERAL(6, 88, 29), // "on_actTab_SetHeader_triggered"
QT_MOC_LITERAL(7, 118, 25), // "on_actFile_Quit_triggered"
QT_MOC_LITERAL(8, 144, 26), // "on_actTab_Locate_triggered"
QT_MOC_LITERAL(9, 171, 17), // "on_currentChanged"
QT_MOC_LITERAL(10, 189, 7), // "current"
QT_MOC_LITERAL(11, 197, 8), // "previous"
QT_MOC_LITERAL(12, 206, 10), // "on_sizeRow"
QT_MOC_LITERAL(13, 217, 3), // "row"
QT_MOC_LITERAL(14, 221, 13), // "on_sizeColumn"
QT_MOC_LITERAL(15, 235, 6), // "column"
QT_MOC_LITERAL(16, 242, 14), // "on_tableHeader"
QT_MOC_LITERAL(17, 257, 5), // "title"
QT_MOC_LITERAL(18, 263, 10), // "on_cellRow"
QT_MOC_LITERAL(19, 274, 13), // "on_cellColumn"
QT_MOC_LITERAL(20, 288, 26) // "on_tableView_doubleClicked"

    },
    "customDialog\0doubleClickedIndex\0\0index\0"
    "on_tableView_clicked\0on_actTab_SetSize_triggered\0"
    "on_actTab_SetHeader_triggered\0"
    "on_actFile_Quit_triggered\0"
    "on_actTab_Locate_triggered\0on_currentChanged\0"
    "current\0previous\0on_sizeRow\0row\0"
    "on_sizeColumn\0column\0on_tableHeader\0"
    "title\0on_cellRow\0on_cellColumn\0"
    "on_tableView_doubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   82,    2, 0x08 /* Private */,
       5,    0,   85,    2, 0x08 /* Private */,
       6,    0,   86,    2, 0x08 /* Private */,
       7,    0,   87,    2, 0x08 /* Private */,
       8,    0,   88,    2, 0x08 /* Private */,
       9,    2,   89,    2, 0x08 /* Private */,
      12,    1,   94,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      16,    1,  100,    2, 0x08 /* Private */,
      18,    1,  103,    2, 0x08 /* Private */,
      19,    1,  106,    2, 0x08 /* Private */,
      20,    1,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QModelIndex,    3,

       0        // eod
};

void customDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customDialog *_t = static_cast<customDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->doubleClickedIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_actTab_SetSize_triggered(); break;
        case 3: _t->on_actTab_SetHeader_triggered(); break;
        case 4: _t->on_actFile_Quit_triggered(); break;
        case 5: _t->on_actTab_Locate_triggered(); break;
        case 6: _t->on_currentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 7: _t->on_sizeRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_sizeColumn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_tableHeader((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->on_cellRow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->on_cellColumn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (customDialog::*_t)(const QModelIndex & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&customDialog::doubleClickedIndex)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject customDialog::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_customDialog.data,
      qt_meta_data_customDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *customDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_customDialog.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int customDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void customDialog::doubleClickedIndex(const QModelIndex & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
