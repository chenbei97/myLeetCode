/****************************************************************************
** Meta object code from reading C++ file 'videoWidgetBased.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestVideoPlayBack/videoWidgetBased.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videoWidgetBased.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_videoWidgetBased_t {
    QByteArrayData data[20];
    char stringdata0[316];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_videoWidgetBased_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_videoWidgetBased_t qt_meta_stringdata_videoWidgetBased = {
    {
QT_MOC_LITERAL(0, 0, 16), // "videoWidgetBased"
QT_MOC_LITERAL(1, 17, 12), // "windowClosed"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "close"
QT_MOC_LITERAL(4, 37, 14), // "onStateChanged"
QT_MOC_LITERAL(5, 52, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(6, 72, 5), // "state"
QT_MOC_LITERAL(7, 78, 17), // "onDurationChanged"
QT_MOC_LITERAL(8, 96, 8), // "duration"
QT_MOC_LITERAL(9, 105, 17), // "onPositionChanged"
QT_MOC_LITERAL(10, 123, 8), // "position"
QT_MOC_LITERAL(11, 132, 17), // "on_btnAdd_clicked"
QT_MOC_LITERAL(12, 150, 18), // "on_btnPlay_clicked"
QT_MOC_LITERAL(13, 169, 19), // "on_btnPause_clicked"
QT_MOC_LITERAL(14, 189, 18), // "on_btnStop_clicked"
QT_MOC_LITERAL(15, 208, 19), // "on_btnSound_clicked"
QT_MOC_LITERAL(16, 228, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(17, 250, 28), // "on_sliderVolumn_valueChanged"
QT_MOC_LITERAL(18, 279, 5), // "value"
QT_MOC_LITERAL(19, 285, 30) // "on_sliderPosition_valueChanged"

    },
    "videoWidgetBased\0windowClosed\0\0close\0"
    "onStateChanged\0QMediaPlayer::State\0"
    "state\0onDurationChanged\0duration\0"
    "onPositionChanged\0position\0on_btnAdd_clicked\0"
    "on_btnPlay_clicked\0on_btnPause_clicked\0"
    "on_btnStop_clicked\0on_btnSound_clicked\0"
    "on_pushButton_clicked\0"
    "on_sliderVolumn_valueChanged\0value\0"
    "on_sliderPosition_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_videoWidgetBased[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   77,    2, 0x08 /* Private */,
       7,    1,   80,    2, 0x08 /* Private */,
       9,    1,   83,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,
      17,    1,   92,    2, 0x08 /* Private */,
      19,    1,   95,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void videoWidgetBased::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        videoWidgetBased *_t = static_cast<videoWidgetBased *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->windowClosed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onStateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 2: _t->onDurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->onPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->on_btnAdd_clicked(); break;
        case 5: _t->on_btnPlay_clicked(); break;
        case 6: _t->on_btnPause_clicked(); break;
        case 7: _t->on_btnStop_clicked(); break;
        case 8: _t->on_btnSound_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_sliderVolumn_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_sliderPosition_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (videoWidgetBased::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&videoWidgetBased::windowClosed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject videoWidgetBased::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_videoWidgetBased.data,
      qt_meta_data_videoWidgetBased,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *videoWidgetBased::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *videoWidgetBased::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_videoWidgetBased.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int videoWidgetBased::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void videoWidgetBased::windowClosed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
