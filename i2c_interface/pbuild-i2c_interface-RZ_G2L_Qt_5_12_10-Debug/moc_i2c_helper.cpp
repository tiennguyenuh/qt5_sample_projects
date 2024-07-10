/****************************************************************************
** Meta object code from reading C++ file 'i2c_helper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../i2c_helper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'i2c_helper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_I2C_Helper_t {
    QByteArrayData data[11];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_I2C_Helper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_I2C_Helper_t qt_meta_stringdata_I2C_Helper = {
    {
QT_MOC_LITERAL(0, 0, 10), // "I2C_Helper"
QT_MOC_LITERAL(1, 11, 8), // "i2c_open"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "i2c_device_file"
QT_MOC_LITERAL(4, 37, 15), // "i2c_device_addr"
QT_MOC_LITERAL(5, 53, 9), // "i2c_write"
QT_MOC_LITERAL(6, 63, 12), // "base_address"
QT_MOC_LITERAL(7, 76, 4), // "data"
QT_MOC_LITERAL(8, 81, 8), // "i2c_read"
QT_MOC_LITERAL(9, 90, 9), // "next_byte"
QT_MOC_LITERAL(10, 100, 9) // "i2c_close"

    },
    "I2C_Helper\0i2c_open\0\0i2c_device_file\0"
    "i2c_device_addr\0i2c_write\0base_address\0"
    "data\0i2c_read\0next_byte\0i2c_close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_I2C_Helper[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x02 /* Public */,
       5,    2,   39,    2, 0x02 /* Public */,
       8,    2,   44,    2, 0x02 /* Public */,
      10,    0,   49,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Int, QMetaType::Int, QMetaType::QByteArray,    6,    7,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    9,
    QMetaType::Int,

       0        // eod
};

void I2C_Helper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<I2C_Helper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->i2c_open((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->i2c_write((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->i2c_read((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->i2c_close();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject I2C_Helper::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_I2C_Helper.data,
    qt_meta_data_I2C_Helper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *I2C_Helper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *I2C_Helper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_I2C_Helper.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int I2C_Helper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
