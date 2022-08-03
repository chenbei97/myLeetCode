/****************************************************************************
** Meta object code from reading C++ file 'operateCamera.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestVideoPlayBack/operateCamera.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'operateCamera.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_operateCamera_t {
    QByteArrayData data[29];
    char stringdata0[473];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_operateCamera_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_operateCamera_t qt_meta_stringdata_operateCamera = {
    {
QT_MOC_LITERAL(0, 0, 13), // "operateCamera"
QT_MOC_LITERAL(1, 14, 12), // "windowClosed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "close"
QT_MOC_LITERAL(4, 34, 21), // "on_cameraStateChanged"
QT_MOC_LITERAL(5, 56, 14), // "QCamera::State"
QT_MOC_LITERAL(6, 71, 5), // "state"
QT_MOC_LITERAL(7, 77, 27), // "on_cameraCaptureModeChanged"
QT_MOC_LITERAL(8, 105, 21), // "QCamera::CaptureModes"
QT_MOC_LITERAL(9, 127, 4), // "mode"
QT_MOC_LITERAL(10, 132, 23), // "on_imageReadyForCapture"
QT_MOC_LITERAL(11, 156, 5), // "ready"
QT_MOC_LITERAL(12, 162, 16), // "on_imageCaptured"
QT_MOC_LITERAL(13, 179, 2), // "id"
QT_MOC_LITERAL(14, 182, 7), // "preview"
QT_MOC_LITERAL(15, 190, 13), // "on_imageSaved"
QT_MOC_LITERAL(16, 204, 8), // "fileName"
QT_MOC_LITERAL(17, 213, 20), // "on_videoStateChanged"
QT_MOC_LITERAL(18, 234, 21), // "QMediaRecorder::State"
QT_MOC_LITERAL(19, 256, 23), // "on_videoDurationChanged"
QT_MOC_LITERAL(20, 280, 8), // "duration"
QT_MOC_LITERAL(21, 289, 27), // "on_actStartCamera_triggered"
QT_MOC_LITERAL(22, 317, 26), // "on_actStopCamera_triggered"
QT_MOC_LITERAL(23, 344, 27), // "on_actVideoRecord_triggered"
QT_MOC_LITERAL(24, 372, 25), // "on_actVideoStop_triggered"
QT_MOC_LITERAL(25, 398, 23), // "on_actCapture_triggered"
QT_MOC_LITERAL(26, 422, 23), // "on_btnVideoFile_clicked"
QT_MOC_LITERAL(27, 446, 18), // "on_chkMute_clicked"
QT_MOC_LITERAL(28, 465, 7) // "checked"

    },
    "operateCamera\0windowClosed\0\0close\0"
    "on_cameraStateChanged\0QCamera::State\0"
    "state\0on_cameraCaptureModeChanged\0"
    "QCamera::CaptureModes\0mode\0"
    "on_imageReadyForCapture\0ready\0"
    "on_imageCaptured\0id\0preview\0on_imageSaved\0"
    "fileName\0on_videoStateChanged\0"
    "QMediaRecorder::State\0on_videoDurationChanged\0"
    "duration\0on_actStartCamera_triggered\0"
    "on_actStopCamera_triggered\0"
    "on_actVideoRecord_triggered\0"
    "on_actVideoStop_triggered\0"
    "on_actCapture_triggered\0on_btnVideoFile_clicked\0"
    "on_chkMute_clicked\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_operateCamera[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   92,    2, 0x08 /* Private */,
       7,    1,   95,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      12,    2,  101,    2, 0x08 /* Private */,
      15,    2,  106,    2, 0x08 /* Private */,
      17,    1,  111,    2, 0x08 /* Private */,
      19,    1,  114,    2, 0x08 /* Private */,
      21,    0,  117,    2, 0x08 /* Private */,
      22,    0,  118,    2, 0x08 /* Private */,
      23,    0,  119,    2, 0x08 /* Private */,
      24,    0,  120,    2, 0x08 /* Private */,
      25,    0,  121,    2, 0x08 /* Private */,
      26,    0,  122,    2, 0x08 /* Private */,
      27,    1,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   13,   16,
    QMetaType::Void, 0x80000000 | 18,    6,
    QMetaType::Void, QMetaType::LongLong,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   28,

       0        // eod
};

void operateCamera::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        operateCamera *_t = static_cast<operateCamera *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->windowClosed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_cameraStateChanged((*reinterpret_cast< QCamera::State(*)>(_a[1]))); break;
        case 2: _t->on_cameraCaptureModeChanged((*reinterpret_cast< QCamera::CaptureModes(*)>(_a[1]))); break;
        case 3: _t->on_imageReadyForCapture((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_imageCaptured((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2]))); break;
        case 5: _t->on_imageSaved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->on_videoStateChanged((*reinterpret_cast< QMediaRecorder::State(*)>(_a[1]))); break;
        case 7: _t->on_videoDurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->on_actStartCamera_triggered(); break;
        case 9: _t->on_actStopCamera_triggered(); break;
        case 10: _t->on_actVideoRecord_triggered(); break;
        case 11: _t->on_actVideoStop_triggered(); break;
        case 12: _t->on_actCapture_triggered(); break;
        case 13: _t->on_btnVideoFile_clicked(); break;
        case 14: _t->on_chkMute_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCamera::State >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCamera::CaptureModes >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaRecorder::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (operateCamera::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&operateCamera::windowClosed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject operateCamera::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_operateCamera.data,
      qt_meta_data_operateCamera,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *operateCamera::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *operateCamera::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_operateCamera.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int operateCamera::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void operateCamera::windowClosed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
