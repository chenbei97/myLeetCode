/****************************************************************************
** Meta object code from reading C++ file 'qmetaobjecttest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../02-MetaObjectTest/qmetaobjecttest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmetaobjecttest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QMetaObjectTest_t {
    QByteArrayData data[11];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMetaObjectTest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMetaObjectTest_t qt_meta_stringdata_QMetaObjectTest = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QMetaObjectTest"
QT_MOC_LITERAL(1, 16, 17), // "spin_valueChanged"
QT_MOC_LITERAL(2, 34, 9), // "QSpinBox*"
QT_MOC_LITERAL(3, 44, 0), // ""
QT_MOC_LITERAL(4, 45, 3), // "arg"
QT_MOC_LITERAL(5, 49, 20), // "spinBoy_valueChanged"
QT_MOC_LITERAL(6, 70, 21), // "spinGirl_valueChanged"
QT_MOC_LITERAL(7, 92, 19), // "on_btnClear_clicked"
QT_MOC_LITERAL(8, 112, 20), // "on_btnBoyInc_clicked"
QT_MOC_LITERAL(9, 133, 21), // "on_btnGirlInc_clicked"
QT_MOC_LITERAL(10, 155, 23) // "on_btnClassInfo_clicked"

    },
    "QMetaObjectTest\0spin_valueChanged\0"
    "QSpinBox*\0\0arg\0spinBoy_valueChanged\0"
    "spinGirl_valueChanged\0on_btnClear_clicked\0"
    "on_btnBoyInc_clicked\0on_btnGirlInc_clicked\0"
    "on_btnClassInfo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMetaObjectTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    3, 0x08 /* Private */,
       5,    1,   52,    3, 0x08 /* Private */,
       6,    1,   55,    3, 0x08 /* Private */,
       7,    0,   58,    3, 0x08 /* Private */,
       8,    0,   59,    3, 0x08 /* Private */,
       9,    0,   60,    3, 0x08 /* Private */,
      10,    0,   61,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QMetaObjectTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QMetaObjectTest *_t = static_cast<QMetaObjectTest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QSpinBox* _r = _t->spin_valueChanged((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QSpinBox**>(_a[0]) = std::move(_r); }  break;
        case 1: _t->spinBoy_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->spinGirl_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_btnClear_clicked(); break;
        case 4: _t->on_btnBoyInc_clicked(); break;
        case 5: _t->on_btnGirlInc_clicked(); break;
        case 6: _t->on_btnClassInfo_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject QMetaObjectTest::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QMetaObjectTest.data,
      qt_meta_data_QMetaObjectTest,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QMetaObjectTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMetaObjectTest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QMetaObjectTest.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QMetaObjectTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
