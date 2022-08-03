/****************************************************************************
** Meta object code from reading C++ file 'graphicsVideoItemBased.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestVideoPlayBack/graphicsVideoItemBased.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsVideoItemBased.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_graphicsVideoItem_t {
    QByteArrayData data[19];
    char stringdata0[302];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_graphicsVideoItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_graphicsVideoItem_t qt_meta_stringdata_graphicsVideoItem = {
    {
QT_MOC_LITERAL(0, 0, 17), // "graphicsVideoItem"
QT_MOC_LITERAL(1, 18, 12), // "windowClosed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "close"
QT_MOC_LITERAL(4, 38, 14), // "onStateChanged"
QT_MOC_LITERAL(5, 53, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(6, 73, 5), // "state"
QT_MOC_LITERAL(7, 79, 17), // "onDurationChanged"
QT_MOC_LITERAL(8, 97, 8), // "duration"
QT_MOC_LITERAL(9, 106, 17), // "onPositionChanged"
QT_MOC_LITERAL(10, 124, 8), // "position"
QT_MOC_LITERAL(11, 133, 18), // "on_btnAdd__clicked"
QT_MOC_LITERAL(12, 152, 19), // "on_btnPlay__clicked"
QT_MOC_LITERAL(13, 172, 20), // "on_btnPause__clicked"
QT_MOC_LITERAL(14, 193, 19), // "on_btnStop__clicked"
QT_MOC_LITERAL(15, 213, 20), // "on_btnSound__clicked"
QT_MOC_LITERAL(16, 234, 29), // "on_sliderVolumn__valueChanged"
QT_MOC_LITERAL(17, 264, 5), // "value"
QT_MOC_LITERAL(18, 270, 31) // "on_sliderPosition__valueChanged"

    },
    "graphicsVideoItem\0windowClosed\0\0close\0"
    "onStateChanged\0QMediaPlayer::State\0"
    "state\0onDurationChanged\0duration\0"
    "onPositionChanged\0position\0"
    "on_btnAdd__clicked\0on_btnPlay__clicked\0"
    "on_btnPause__clicked\0on_btnStop__clicked\0"
    "on_btnSound__clicked\0on_sliderVolumn__valueChanged\0"
    "value\0on_sliderPosition__valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_graphicsVideoItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   72,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
       9,    1,   78,    2, 0x08 /* Private */,
      11,    0,   81,    2, 0x08 /* Private */,
      12,    0,   82,    2, 0x08 /* Private */,
      13,    0,   83,    2, 0x08 /* Private */,
      14,    0,   84,    2, 0x08 /* Private */,
      15,    0,   85,    2, 0x08 /* Private */,
      16,    1,   86,    2, 0x08 /* Private */,
      18,    1,   89,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void graphicsVideoItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        graphicsVideoItem *_t = static_cast<graphicsVideoItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->windowClosed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onStateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 2: _t->onDurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->onPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->on_btnAdd__clicked(); break;
        case 5: _t->on_btnPlay__clicked(); break;
        case 6: _t->on_btnPause__clicked(); break;
        case 7: _t->on_btnStop__clicked(); break;
        case 8: _t->on_btnSound__clicked(); break;
        case 9: _t->on_sliderVolumn__valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_sliderPosition__valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
            typedef void (graphicsVideoItem::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&graphicsVideoItem::windowClosed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject graphicsVideoItem::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_graphicsVideoItem.data,
      qt_meta_data_graphicsVideoItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *graphicsVideoItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *graphicsVideoItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_graphicsVideoItem.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int graphicsVideoItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void graphicsVideoItem::windowClosed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
