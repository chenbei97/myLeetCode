/****************************************************************************
** Meta object code from reading C++ file 'TestQAudioInput.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestQAudioInput/TestQAudioInput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestQAudioInput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestQAudioInput_t {
    QByteArrayData data[9];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestQAudioInput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestQAudioInput_t qt_meta_stringdata_TestQAudioInput = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TestQAudioInput"
QT_MOC_LITERAL(1, 16, 27), // "on_IODevice_UpdateBlockSize"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 9), // "blockSize"
QT_MOC_LITERAL(4, 55, 26), // "on_actDeviceTest_triggered"
QT_MOC_LITERAL(5, 82, 21), // "on_actStart_triggered"
QT_MOC_LITERAL(6, 104, 20), // "on_actStop_triggered"
QT_MOC_LITERAL(7, 125, 35), // "on_comboDevices_currentIndexC..."
QT_MOC_LITERAL(8, 161, 5) // "index"

    },
    "TestQAudioInput\0on_IODevice_UpdateBlockSize\0"
    "\0blockSize\0on_actDeviceTest_triggered\0"
    "on_actStart_triggered\0on_actStop_triggered\0"
    "on_comboDevices_currentIndexChanged\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestQAudioInput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    0,   42,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void TestQAudioInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestQAudioInput *_t = static_cast<TestQAudioInput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_IODevice_UpdateBlockSize((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->on_actDeviceTest_triggered(); break;
        case 2: _t->on_actStart_triggered(); break;
        case 3: _t->on_actStop_triggered(); break;
        case 4: _t->on_comboDevices_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TestQAudioInput::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestQAudioInput.data,
      qt_meta_data_TestQAudioInput,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestQAudioInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestQAudioInput::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestQAudioInput.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestQAudioInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
