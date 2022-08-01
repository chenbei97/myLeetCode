/****************************************************************************
** Meta object code from reading C++ file 'TCPServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TCPServer/TCPServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TCPServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TCPServer_t {
    QByteArrayData data[17];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TCPServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TCPServer_t qt_meta_stringdata_TCPServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TCPServer"
QT_MOC_LITERAL(1, 10, 21), // "on_actStart_triggered"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "on_actStop_triggered"
QT_MOC_LITERAL(4, 54, 24), // "on_actHostInfo_triggered"
QT_MOC_LITERAL(5, 79, 21), // "on_actClear_triggered"
QT_MOC_LITERAL(6, 101, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(7, 120, 15), // "onNewConnection"
QT_MOC_LITERAL(8, 136, 19), // "onSocketStateChange"
QT_MOC_LITERAL(9, 156, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(10, 185, 11), // "socketState"
QT_MOC_LITERAL(11, 197, 17), // "onClientConnected"
QT_MOC_LITERAL(12, 215, 20), // "onClientDisconnected"
QT_MOC_LITERAL(13, 236, 17), // "onSocketReadyRead"
QT_MOC_LITERAL(14, 254, 29), // "on_comboIP_currentTextChanged"
QT_MOC_LITERAL(15, 284, 4), // "arg1"
QT_MOC_LITERAL(16, 289, 24) // "on_spinPort_valueChanged"

    },
    "TCPServer\0on_actStart_triggered\0\0"
    "on_actStop_triggered\0on_actHostInfo_triggered\0"
    "on_actClear_triggered\0on_btnSend_clicked\0"
    "onNewConnection\0onSocketStateChange\0"
    "QAbstractSocket::SocketState\0socketState\0"
    "onClientConnected\0onClientDisconnected\0"
    "onSocketReadyRead\0on_comboIP_currentTextChanged\0"
    "arg1\0on_spinPort_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TCPServer[] = {

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
       8,    1,   80,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      16,    1,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void TCPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TCPServer *_t = static_cast<TCPServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actStart_triggered(); break;
        case 1: _t->on_actStop_triggered(); break;
        case 2: _t->on_actHostInfo_triggered(); break;
        case 3: _t->on_actClear_triggered(); break;
        case 4: _t->on_btnSend_clicked(); break;
        case 5: _t->onNewConnection(); break;
        case 6: _t->onSocketStateChange((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 7: _t->onClientConnected(); break;
        case 8: _t->onClientDisconnected(); break;
        case 9: _t->onSocketReadyRead(); break;
        case 10: _t->on_comboIP_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_spinPort_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

const QMetaObject TCPServer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TCPServer.data,
      qt_meta_data_TCPServer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TCPServer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
