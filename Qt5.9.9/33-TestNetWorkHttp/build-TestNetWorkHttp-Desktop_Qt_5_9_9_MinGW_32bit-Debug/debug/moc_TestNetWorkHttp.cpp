/****************************************************************************
** Meta object code from reading C++ file 'TestNetWorkHttp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestNetWorkHttp/TestNetWorkHttp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestNetWorkHttp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestNetWorkHttp_t {
    QByteArrayData data[11];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestNetWorkHttp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestNetWorkHttp_t qt_meta_stringdata_TestNetWorkHttp = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TestNetWorkHttp"
QT_MOC_LITERAL(1, 16, 11), // "on_finished"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "on_readyRead"
QT_MOC_LITERAL(4, 42, 19), // "on_downloadProgress"
QT_MOC_LITERAL(5, 62, 9), // "bytesRead"
QT_MOC_LITERAL(6, 72, 10), // "totalBytes"
QT_MOC_LITERAL(7, 83, 22), // "on_btnDownload_clicked"
QT_MOC_LITERAL(8, 106, 25), // "on_btnDefaultPath_clicked"
QT_MOC_LITERAL(9, 132, 22), // "on_editURL_textChanged"
QT_MOC_LITERAL(10, 155, 4) // "arg1"

    },
    "TestNetWorkHttp\0on_finished\0\0on_readyRead\0"
    "on_downloadProgress\0bytesRead\0totalBytes\0"
    "on_btnDownload_clicked\0on_btnDefaultPath_clicked\0"
    "on_editURL_textChanged\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestNetWorkHttp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    2,   46,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    1,   53,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void TestNetWorkHttp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestNetWorkHttp *_t = static_cast<TestNetWorkHttp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_finished(); break;
        case 1: _t->on_readyRead(); break;
        case 2: _t->on_downloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 3: _t->on_btnDownload_clicked(); break;
        case 4: _t->on_btnDefaultPath_clicked(); break;
        case 5: _t->on_editURL_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TestNetWorkHttp::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestNetWorkHttp.data,
      qt_meta_data_TestNetWorkHttp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestNetWorkHttp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestNetWorkHttp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestNetWorkHttp.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestNetWorkHttp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
