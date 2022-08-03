/****************************************************************************
** Meta object code from reading C++ file 'TestTRTranslation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestTRTranslation/TestTRTranslation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestTRTranslation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestTRTranslation_t {
    QByteArrayData data[22];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestTRTranslation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestTRTranslation_t qt_meta_stringdata_TestTRTranslation = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TestTRTranslation"
QT_MOC_LITERAL(1, 18, 16), // "cellIndexChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "rowNo"
QT_MOC_LITERAL(4, 42, 5), // "colNo"
QT_MOC_LITERAL(5, 48, 12), // "setACellText"
QT_MOC_LITERAL(6, 61, 3), // "row"
QT_MOC_LITERAL(7, 65, 6), // "column"
QT_MOC_LITERAL(8, 72, 8), // "QString&"
QT_MOC_LITERAL(9, 81, 4), // "text"
QT_MOC_LITERAL(10, 86, 18), // "setActLocateEnable"
QT_MOC_LITERAL(11, 105, 6), // "enable"
QT_MOC_LITERAL(12, 112, 17), // "on_currentChanged"
QT_MOC_LITERAL(13, 130, 7), // "current"
QT_MOC_LITERAL(14, 138, 8), // "previous"
QT_MOC_LITERAL(15, 147, 27), // "on_actTab_SetSize_triggered"
QT_MOC_LITERAL(16, 175, 29), // "on_actTab_SetHeader_triggered"
QT_MOC_LITERAL(17, 205, 26), // "on_actTab_Locate_triggered"
QT_MOC_LITERAL(18, 232, 20), // "on_tableView_clicked"
QT_MOC_LITERAL(19, 253, 5), // "index"
QT_MOC_LITERAL(20, 259, 23), // "on_actLang_CN_triggered"
QT_MOC_LITERAL(21, 283, 23) // "on_actLang_EN_triggered"

    },
    "TestTRTranslation\0cellIndexChanged\0\0"
    "rowNo\0colNo\0setACellText\0row\0column\0"
    "QString&\0text\0setActLocateEnable\0"
    "enable\0on_currentChanged\0current\0"
    "previous\0on_actTab_SetSize_triggered\0"
    "on_actTab_SetHeader_triggered\0"
    "on_actTab_Locate_triggered\0"
    "on_tableView_clicked\0index\0"
    "on_actLang_CN_triggered\0on_actLang_EN_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestTRTranslation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   69,    2, 0x0a /* Public */,
      10,    1,   76,    2, 0x0a /* Public */,
      12,    2,   79,    2, 0x08 /* Private */,
      15,    0,   84,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,
      17,    0,   86,    2, 0x08 /* Private */,
      18,    1,   87,    2, 0x08 /* Private */,
      20,    0,   90,    2, 0x08 /* Private */,
      21,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 8,    6,    7,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestTRTranslation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestTRTranslation *_t = static_cast<TestTRTranslation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cellIndexChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->setACellText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->setActLocateEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_currentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: _t->on_actTab_SetSize_triggered(); break;
        case 5: _t->on_actTab_SetHeader_triggered(); break;
        case 6: _t->on_actTab_Locate_triggered(); break;
        case 7: _t->on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_actLang_CN_triggered(); break;
        case 9: _t->on_actLang_EN_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TestTRTranslation::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TestTRTranslation::cellIndexChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TestTRTranslation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestTRTranslation.data,
      qt_meta_data_TestTRTranslation,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestTRTranslation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestTRTranslation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestTRTranslation.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestTRTranslation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void TestTRTranslation::cellIndexChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
