/****************************************************************************
** Meta object code from reading C++ file 'qflightpath.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../flight_path/qflightpath.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qflightpath.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QFlightPath_t {
    QByteArrayData data[19];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QFlightPath_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QFlightPath_t qt_meta_stringdata_QFlightPath = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QFlightPath"
QT_MOC_LITERAL(1, 12, 9), // "SendAPath"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "flightpathdata"
QT_MOC_LITERAL(4, 38, 7), // "Startup"
QT_MOC_LITERAL(5, 46, 12), // "SendShowFlag"
QT_MOC_LITERAL(6, 59, 32), // "on_actionAddFlightPath_triggered"
QT_MOC_LITERAL(7, 92, 20), // "on_ReceptAFlightPath"
QT_MOC_LITERAL(8, 113, 14), // "FlightPathData"
QT_MOC_LITERAL(9, 128, 5), // "apath"
QT_MOC_LITERAL(10, 134, 31), // "on_btnDisplayFlightPath_clicked"
QT_MOC_LITERAL(11, 166, 20), // "UpdateFlightPathData"
QT_MOC_LITERAL(12, 187, 15), // "DisplayDateTime"
QT_MOC_LITERAL(13, 203, 28), // "on_btnHideFlightPath_clicked"
QT_MOC_LITERAL(14, 232, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(15, 251, 24), // "on_btnDisconnect_clicked"
QT_MOC_LITERAL(16, 276, 31), // "on_actionCalification_triggered"
QT_MOC_LITERAL(17, 308, 21), // "on_btnSavelog_clicked"
QT_MOC_LITERAL(18, 330, 21) // "on_pushButton_clicked"

    },
    "QFlightPath\0SendAPath\0\0flightpathdata\0"
    "Startup\0SendShowFlag\0"
    "on_actionAddFlightPath_triggered\0"
    "on_ReceptAFlightPath\0FlightPathData\0"
    "apath\0on_btnDisplayFlightPath_clicked\0"
    "UpdateFlightPathData\0DisplayDateTime\0"
    "on_btnHideFlightPath_clicked\0"
    "on_btnSend_clicked\0on_btnDisconnect_clicked\0"
    "on_actionCalification_triggered\0"
    "on_btnSavelog_clicked\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QFlightPath[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,
       5,    1,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   91,    2, 0x08 /* Private */,
       7,    1,   92,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QFlightPath::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QFlightPath *_t = static_cast<QFlightPath *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendAPath((*reinterpret_cast< flightpathdata(*)>(_a[1]))); break;
        case 1: _t->Startup(); break;
        case 2: _t->SendShowFlag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_actionAddFlightPath_triggered(); break;
        case 4: _t->on_ReceptAFlightPath((*reinterpret_cast< FlightPathData(*)>(_a[1]))); break;
        case 5: _t->on_btnDisplayFlightPath_clicked(); break;
        case 6: _t->UpdateFlightPathData(); break;
        case 7: _t->DisplayDateTime(); break;
        case 8: _t->on_btnHideFlightPath_clicked(); break;
        case 9: _t->on_btnSend_clicked(); break;
        case 10: _t->on_btnDisconnect_clicked(); break;
        case 11: _t->on_actionCalification_triggered(); break;
        case 12: _t->on_btnSavelog_clicked(); break;
        case 13: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (QFlightPath::*_t)(flightpathdata );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QFlightPath::SendAPath)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QFlightPath::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QFlightPath::Startup)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QFlightPath::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QFlightPath::SendShowFlag)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QFlightPath::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QFlightPath.data,
      qt_meta_data_QFlightPath,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QFlightPath::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QFlightPath::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QFlightPath.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QFlightPath::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QFlightPath::SendAPath(flightpathdata _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QFlightPath::Startup()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QFlightPath::SendShowFlag(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
