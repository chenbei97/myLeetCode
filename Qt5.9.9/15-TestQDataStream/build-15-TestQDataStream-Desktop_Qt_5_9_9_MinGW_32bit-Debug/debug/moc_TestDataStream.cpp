/****************************************************************************
** Meta object code from reading C++ file 'TestDataStream.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../15-TestQDataStream/TestDataStream.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestDataStream.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestDataStream_t {
    QByteArrayData data[21];
    char stringdata0[427];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestDataStream_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestDataStream_t qt_meta_stringdata_TestDataStream = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TestDataStream"
QT_MOC_LITERAL(1, 15, 20), // "on_actOpen_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 20), // "on_actSave_triggered"
QT_MOC_LITERAL(4, 58, 23), // "on_actOpenBin_triggered"
QT_MOC_LITERAL(5, 82, 23), // "on_actSaveBin_triggered"
QT_MOC_LITERAL(6, 106, 23), // "on_actOpenTxt_triggered"
QT_MOC_LITERAL(7, 130, 23), // "on_actSaveTxt_triggered"
QT_MOC_LITERAL(8, 154, 24), // "on_actTabReset_triggered"
QT_MOC_LITERAL(9, 179, 22), // "on_actAppend_triggered"
QT_MOC_LITERAL(10, 202, 22), // "on_actInsert_triggered"
QT_MOC_LITERAL(11, 225, 22), // "on_actDelete_triggered"
QT_MOC_LITERAL(12, 248, 25), // "on_actModelData_triggered"
QT_MOC_LITERAL(13, 274, 25), // "on_actAlignLeft_triggered"
QT_MOC_LITERAL(14, 300, 27), // "on_actAlignCenter_triggered"
QT_MOC_LITERAL(15, 328, 26), // "on_actAlignRight_triggered"
QT_MOC_LITERAL(16, 355, 24), // "on_actFontBold_triggered"
QT_MOC_LITERAL(17, 380, 7), // "checked"
QT_MOC_LITERAL(18, 388, 21), // "on_currentItemChanged"
QT_MOC_LITERAL(19, 410, 7), // "current"
QT_MOC_LITERAL(20, 418, 8) // "previous"

    },
    "TestDataStream\0on_actOpen_triggered\0"
    "\0on_actSave_triggered\0on_actOpenBin_triggered\0"
    "on_actSaveBin_triggered\0on_actOpenTxt_triggered\0"
    "on_actSaveTxt_triggered\0"
    "on_actTabReset_triggered\0"
    "on_actAppend_triggered\0on_actInsert_triggered\0"
    "on_actDelete_triggered\0on_actModelData_triggered\0"
    "on_actAlignLeft_triggered\0"
    "on_actAlignCenter_triggered\0"
    "on_actAlignRight_triggered\0"
    "on_actFontBold_triggered\0checked\0"
    "on_currentItemChanged\0current\0previous"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestDataStream[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    0,   95,    2, 0x08 /* Private */,
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    1,  108,    2, 0x08 /* Private */,
      18,    2,  111,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   19,   20,

       0        // eod
};

void TestDataStream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestDataStream *_t = static_cast<TestDataStream *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actOpen_triggered(); break;
        case 1: _t->on_actSave_triggered(); break;
        case 2: _t->on_actOpenBin_triggered(); break;
        case 3: _t->on_actSaveBin_triggered(); break;
        case 4: _t->on_actOpenTxt_triggered(); break;
        case 5: _t->on_actSaveTxt_triggered(); break;
        case 6: _t->on_actTabReset_triggered(); break;
        case 7: _t->on_actAppend_triggered(); break;
        case 8: _t->on_actInsert_triggered(); break;
        case 9: _t->on_actDelete_triggered(); break;
        case 10: _t->on_actModelData_triggered(); break;
        case 11: _t->on_actAlignLeft_triggered(); break;
        case 12: _t->on_actAlignCenter_triggered(); break;
        case 13: _t->on_actAlignRight_triggered(); break;
        case 14: _t->on_actFontBold_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_currentItemChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject TestDataStream::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestDataStream.data,
      qt_meta_data_TestDataStream,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestDataStream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestDataStream::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestDataStream.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestDataStream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
