/****************************************************************************
** Meta object code from reading C++ file 'db.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ServerTest/db.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'db.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DB_t {
    QByteArrayData data[9];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DB_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DB_t qt_meta_stringdata_DB = {
    {
QT_MOC_LITERAL(0, 0, 2), // "DB"
QT_MOC_LITERAL(1, 3, 7), // "sendImg"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 12), // "sendQueryRes"
QT_MOC_LITERAL(4, 25, 3), // "res"
QT_MOC_LITERAL(5, 29, 12), // "updateImgSrc"
QT_MOC_LITERAL(6, 42, 8), // "infoJson"
QT_MOC_LITERAL(7, 51, 11), // "queryResult"
QT_MOC_LITERAL(8, 63, 5) // "query"

    },
    "DB\0sendImg\0\0sendQueryRes\0res\0updateImgSrc\0"
    "infoJson\0queryResult\0query"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DB[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   38,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonArray,    4,

 // slots: parameters
    QMetaType::Bool, QMetaType::QJsonObject,    6,
    QMetaType::QJsonArray, QMetaType::QJsonObject,    8,

       0        // eod
};

void DB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DB *_t = static_cast<DB *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendImg(); break;
        case 1: _t->sendQueryRes((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 2: { bool _r = _t->updateImgSrc((*reinterpret_cast< QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { QJsonArray _r = _t->queryResult((*reinterpret_cast< QJsonObject(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QJsonArray*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DB::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DB::sendImg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DB::*_t)(QJsonArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DB::sendQueryRes)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject DB::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DB.data,
      qt_meta_data_DB,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DB::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DB.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void DB::sendImg()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DB::sendQueryRes(QJsonArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
