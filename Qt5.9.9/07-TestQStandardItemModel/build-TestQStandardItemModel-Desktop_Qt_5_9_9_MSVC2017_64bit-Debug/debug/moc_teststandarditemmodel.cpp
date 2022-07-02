/****************************************************************************
** Meta object code from reading C++ file 'teststandarditemmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestQStandardItemModel/teststandarditemmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teststandarditemmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestStandardItemModel_t {
    QByteArrayData data[17];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestStandardItemModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestStandardItemModel_t qt_meta_stringdata_TestStandardItemModel = {
    {
QT_MOC_LITERAL(0, 0, 21), // "TestStandardItemModel"
QT_MOC_LITERAL(1, 22, 20), // "on_actOpen_triggered"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 22), // "on_actAppend_triggered"
QT_MOC_LITERAL(4, 67, 20), // "on_actSave_triggered"
QT_MOC_LITERAL(5, 88, 22), // "on_actInsert_triggered"
QT_MOC_LITERAL(6, 111, 22), // "on_actDelete_triggered"
QT_MOC_LITERAL(7, 134, 20), // "on_actExit_triggered"
QT_MOC_LITERAL(8, 155, 25), // "on_actModelData_triggered"
QT_MOC_LITERAL(9, 181, 25), // "on_actAlignLeft_triggered"
QT_MOC_LITERAL(10, 207, 27), // "on_actAlignCenter_triggered"
QT_MOC_LITERAL(11, 235, 26), // "on_actAlignRight_triggered"
QT_MOC_LITERAL(12, 262, 24), // "on_actFontBold_triggered"
QT_MOC_LITERAL(13, 287, 7), // "checked"
QT_MOC_LITERAL(14, 295, 26), // "on_currentItemIndexChanged"
QT_MOC_LITERAL(15, 322, 7), // "current"
QT_MOC_LITERAL(16, 330, 8) // "previous"

    },
    "TestStandardItemModel\0on_actOpen_triggered\0"
    "\0on_actAppend_triggered\0on_actSave_triggered\0"
    "on_actInsert_triggered\0on_actDelete_triggered\0"
    "on_actExit_triggered\0on_actModelData_triggered\0"
    "on_actAlignLeft_triggered\0"
    "on_actAlignCenter_triggered\0"
    "on_actAlignRight_triggered\0"
    "on_actFontBold_triggered\0checked\0"
    "on_currentItemIndexChanged\0current\0"
    "previous"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestStandardItemModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    0,   79,    2, 0x08 /* Private */,
       8,    0,   80,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    1,   84,    2, 0x08 /* Private */,
      14,    2,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   15,   16,

       0        // eod
};

void TestStandardItemModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestStandardItemModel *_t = static_cast<TestStandardItemModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actOpen_triggered(); break;
        case 1: _t->on_actAppend_triggered(); break;
        case 2: _t->on_actSave_triggered(); break;
        case 3: _t->on_actInsert_triggered(); break;
        case 4: _t->on_actDelete_triggered(); break;
        case 5: _t->on_actExit_triggered(); break;
        case 6: _t->on_actModelData_triggered(); break;
        case 7: _t->on_actAlignLeft_triggered(); break;
        case 8: _t->on_actAlignCenter_triggered(); break;
        case 9: _t->on_actAlignRight_triggered(); break;
        case 10: _t->on_actFontBold_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_currentItemIndexChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject TestStandardItemModel::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestStandardItemModel.data,
      qt_meta_data_TestStandardItemModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestStandardItemModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestStandardItemModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestStandardItemModel.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestStandardItemModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
