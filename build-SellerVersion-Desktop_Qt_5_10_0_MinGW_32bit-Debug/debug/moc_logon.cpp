/****************************************************************************
** Meta object code from reading C++ file 'logon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SellerVersion/logon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogOn_t {
    QByteArrayData data[8];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogOn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogOn_t qt_meta_stringdata_LogOn = {
    {
QT_MOC_LITERAL(0, 0, 5), // "LogOn"
QT_MOC_LITERAL(1, 6, 9), // "logOnSucc"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 12), // "needRegister"
QT_MOC_LITERAL(4, 30, 13), // "sendLogOnInfo"
QT_MOC_LITERAL(5, 44, 8), // "Infojson"
QT_MOC_LITERAL(6, 53, 20), // "on_LogOn_Btn_clicked"
QT_MOC_LITERAL(7, 74, 23) // "on_Register_Btn_clicked"

    },
    "LogOn\0logOnSucc\0\0needRegister\0"
    "sendLogOnInfo\0Infojson\0on_LogOn_Btn_clicked\0"
    "on_Register_Btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogOn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonObject,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LogOn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogOn *_t = static_cast<LogOn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->logOnSucc(); break;
        case 1: _t->needRegister(); break;
        case 2: _t->sendLogOnInfo((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 3: _t->on_LogOn_Btn_clicked(); break;
        case 4: _t->on_Register_Btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LogOn::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LogOn::logOnSucc)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LogOn::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LogOn::needRegister)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LogOn::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LogOn::sendLogOnInfo)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject LogOn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LogOn.data,
      qt_meta_data_LogOn,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LogOn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogOn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogOn.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LogOn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LogOn::logOnSucc()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LogOn::needRegister()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LogOn::sendLogOnInfo(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
