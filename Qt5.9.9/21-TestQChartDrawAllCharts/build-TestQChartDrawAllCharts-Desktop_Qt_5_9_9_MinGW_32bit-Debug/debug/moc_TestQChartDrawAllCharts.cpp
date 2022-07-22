/****************************************************************************
** Meta object code from reading C++ file 'TestQChartDrawAllCharts.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TestQChartDrawAllCharts/TestQChartDrawAllCharts.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestQChartDrawAllCharts.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestQChartDrawAllCharts_t {
    QByteArrayData data[20];
    char stringdata0[397];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestQChartDrawAllCharts_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestQChartDrawAllCharts_t qt_meta_stringdata_TestQChartDrawAllCharts = {
    {
QT_MOC_LITERAL(0, 0, 23), // "TestQChartDrawAllCharts"
QT_MOC_LITERAL(1, 24, 14), // "on_itemChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 14), // "QStandardItem*"
QT_MOC_LITERAL(4, 55, 4), // "item"
QT_MOC_LITERAL(5, 60, 30), // "on_chartBarLegendMarkerClicked"
QT_MOC_LITERAL(6, 91, 20), // "on_PieSliceHighlight"
QT_MOC_LITERAL(7, 112, 4), // "show"
QT_MOC_LITERAL(8, 117, 23), // "on_actGenData_triggered"
QT_MOC_LITERAL(9, 141, 22), // "on_actTongJi_triggered"
QT_MOC_LITERAL(10, 164, 21), // "on_btnScatter_clicked"
QT_MOC_LITERAL(11, 186, 27), // "on_btnBuildBarChart_clicked"
QT_MOC_LITERAL(12, 214, 26), // "on_btnDrawPieChart_clicked"
QT_MOC_LITERAL(13, 241, 29), // "on_btnBuildStackedBar_clicked"
QT_MOC_LITERAL(14, 271, 24), // "on_btnPercentBar_clicked"
QT_MOC_LITERAL(15, 296, 28), // "on_spinHoleSize_valueChanged"
QT_MOC_LITERAL(16, 325, 4), // "arg1"
QT_MOC_LITERAL(17, 330, 27), // "on_spinPieSize_valueChanged"
QT_MOC_LITERAL(18, 358, 32), // "on_cBoxTheme_currentIndexChanged"
QT_MOC_LITERAL(19, 391, 5) // "index"

    },
    "TestQChartDrawAllCharts\0on_itemChanged\0"
    "\0QStandardItem*\0item\0"
    "on_chartBarLegendMarkerClicked\0"
    "on_PieSliceHighlight\0show\0"
    "on_actGenData_triggered\0on_actTongJi_triggered\0"
    "on_btnScatter_clicked\0on_btnBuildBarChart_clicked\0"
    "on_btnDrawPieChart_clicked\0"
    "on_btnBuildStackedBar_clicked\0"
    "on_btnPercentBar_clicked\0"
    "on_spinHoleSize_valueChanged\0arg1\0"
    "on_spinPieSize_valueChanged\0"
    "on_cBoxTheme_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestQChartDrawAllCharts[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    1,   83,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,
      17,    1,   96,    2, 0x08 /* Private */,
      18,    1,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void TestQChartDrawAllCharts::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestQChartDrawAllCharts *_t = static_cast<TestQChartDrawAllCharts *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_itemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 1: _t->on_chartBarLegendMarkerClicked(); break;
        case 2: _t->on_PieSliceHighlight((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_actGenData_triggered(); break;
        case 4: _t->on_actTongJi_triggered(); break;
        case 5: _t->on_btnScatter_clicked(); break;
        case 6: _t->on_btnBuildBarChart_clicked(); break;
        case 7: _t->on_btnDrawPieChart_clicked(); break;
        case 8: _t->on_btnBuildStackedBar_clicked(); break;
        case 9: _t->on_btnPercentBar_clicked(); break;
        case 10: _t->on_spinHoleSize_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_spinPieSize_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_cBoxTheme_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TestQChartDrawAllCharts::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestQChartDrawAllCharts.data,
      qt_meta_data_TestQChartDrawAllCharts,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestQChartDrawAllCharts::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestQChartDrawAllCharts::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestQChartDrawAllCharts.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestQChartDrawAllCharts::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
