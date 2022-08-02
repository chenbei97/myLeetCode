/****************************************************************************
** Meta object code from reading C++ file 'TestQAudioRecorder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestQAudioRecorder/TestQAudioRecorder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestQAudioRecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestQAudioRecorder_t {
    QByteArrayData data[14];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestQAudioRecorder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestQAudioRecorder_t qt_meta_stringdata_TestQAudioRecorder = {
    {
QT_MOC_LITERAL(0, 0, 18), // "TestQAudioRecorder"
QT_MOC_LITERAL(1, 19, 14), // "onStateChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 21), // "QMediaRecorder::State"
QT_MOC_LITERAL(4, 57, 5), // "state"
QT_MOC_LITERAL(5, 63, 17), // "onDurationChanged"
QT_MOC_LITERAL(6, 81, 8), // "duration"
QT_MOC_LITERAL(7, 90, 19), // "onAudioBufferProbed"
QT_MOC_LITERAL(8, 110, 12), // "QAudioBuffer"
QT_MOC_LITERAL(9, 123, 6), // "buffer"
QT_MOC_LITERAL(10, 130, 22), // "on_actRecord_triggered"
QT_MOC_LITERAL(11, 153, 21), // "on_actPause_triggered"
QT_MOC_LITERAL(12, 175, 20), // "on_actStop_triggered"
QT_MOC_LITERAL(13, 196, 21) // "on_btnGetFile_clicked"

    },
    "TestQAudioRecorder\0onStateChanged\0\0"
    "QMediaRecorder::State\0state\0"
    "onDurationChanged\0duration\0"
    "onAudioBufferProbed\0QAudioBuffer\0"
    "buffer\0on_actRecord_triggered\0"
    "on_actPause_triggered\0on_actStop_triggered\0"
    "on_btnGetFile_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestQAudioRecorder[] = {

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
       1,    1,   49,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       7,    1,   55,    2, 0x08 /* Private */,
      10,    0,   58,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,
      12,    0,   60,    2, 0x08 /* Private */,
      13,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::LongLong,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestQAudioRecorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestQAudioRecorder *_t = static_cast<TestQAudioRecorder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStateChanged((*reinterpret_cast< QMediaRecorder::State(*)>(_a[1]))); break;
        case 1: _t->onDurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->onAudioBufferProbed((*reinterpret_cast< const QAudioBuffer(*)>(_a[1]))); break;
        case 3: _t->on_actRecord_triggered(); break;
        case 4: _t->on_actPause_triggered(); break;
        case 5: _t->on_actStop_triggered(); break;
        case 6: _t->on_btnGetFile_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaRecorder::State >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioBuffer >(); break;
            }
            break;
        }
    }
}

const QMetaObject TestQAudioRecorder::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestQAudioRecorder.data,
      qt_meta_data_TestQAudioRecorder,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestQAudioRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestQAudioRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestQAudioRecorder.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestQAudioRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
