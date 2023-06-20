/****************************************************************************
** Meta object code from reading C++ file 'setaflightpath.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../flight_path/setaflightpath.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setaflightpath.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_setAFlightPath_t {
    QByteArrayData data[16];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_setAFlightPath_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_setAFlightPath_t qt_meta_stringdata_setAFlightPath = {
    {
QT_MOC_LITERAL(0, 0, 14), // "setAFlightPath"
QT_MOC_LITERAL(1, 15, 15), // "setSuccessfully"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "FlightPathData"
QT_MOC_LITERAL(4, 47, 4), // "data"
QT_MOC_LITERAL(5, 52, 16), // "on_btnOK_clicked"
QT_MOC_LITERAL(6, 69, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(7, 90, 20), // "on_cmbType_activated"
QT_MOC_LITERAL(8, 111, 5), // "index"
QT_MOC_LITERAL(9, 117, 30), // "on_cmbType_currentIndexChanged"
QT_MOC_LITERAL(10, 148, 21), // "on_cmbtypex_activated"
QT_MOC_LITERAL(11, 170, 21), // "on_cmbtypey_activated"
QT_MOC_LITERAL(12, 192, 21), // "on_cmbtypez_activated"
QT_MOC_LITERAL(13, 214, 23), // "on_editID_returnPressed"
QT_MOC_LITERAL(14, 238, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(15, 260, 36) // "on_cmbFlightPath_currentIndex..."

    },
    "setAFlightPath\0setSuccessfully\0\0"
    "FlightPathData\0data\0on_btnOK_clicked\0"
    "on_btnCancel_clicked\0on_cmbType_activated\0"
    "index\0on_cmbType_currentIndexChanged\0"
    "on_cmbtypex_activated\0on_cmbtypey_activated\0"
    "on_cmbtypez_activated\0on_editID_returnPressed\0"
    "on_pushButton_clicked\0"
    "on_cmbFlightPath_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_setAFlightPath[] = {

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
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    1,   74,    2, 0x08 /* Private */,
       9,    1,   77,    2, 0x08 /* Private */,
      10,    1,   80,    2, 0x08 /* Private */,
      11,    1,   83,    2, 0x08 /* Private */,
      12,    1,   86,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void setAFlightPath::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        setAFlightPath *_t = static_cast<setAFlightPath *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setSuccessfully((*reinterpret_cast< FlightPathData(*)>(_a[1]))); break;
        case 1: _t->on_btnOK_clicked(); break;
        case 2: _t->on_btnCancel_clicked(); break;
        case 3: _t->on_cmbType_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_cmbType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_cmbtypex_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_cmbtypey_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_cmbtypez_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_editID_returnPressed(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_cmbFlightPath_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (setAFlightPath::*_t)(FlightPathData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&setAFlightPath::setSuccessfully)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject setAFlightPath::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_setAFlightPath.data,
      qt_meta_data_setAFlightPath,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *setAFlightPath::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *setAFlightPath::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_setAFlightPath.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int setAFlightPath::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void setAFlightPath::setSuccessfully(FlightPathData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
