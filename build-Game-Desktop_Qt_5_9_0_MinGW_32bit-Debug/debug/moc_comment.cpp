/****************************************************************************
** Meta object code from reading C++ file 'comment.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Game/comment.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'comment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_comment_t {
    QByteArrayData data[16];
    char stringdata0[146];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_comment_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_comment_t qt_meta_stringdata_comment = {
    {
QT_MOC_LITERAL(0, 0, 7), // "comment"
QT_MOC_LITERAL(1, 8, 11), // "sendComment"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "commentJson"
QT_MOC_LITERAL(4, 33, 12), // "queryComment"
QT_MOC_LITERAL(5, 46, 7), // "labelId"
QT_MOC_LITERAL(6, 54, 9), // "ProductId"
QT_MOC_LITERAL(7, 64, 10), // "sendPraise"
QT_MOC_LITERAL(8, 75, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(9, 97, 6), // "praise"
QT_MOC_LITERAL(10, 104, 2), // "id"
QT_MOC_LITERAL(11, 107, 3), // "seq"
QT_MOC_LITERAL(12, 111, 5), // "isadd"
QT_MOC_LITERAL(13, 117, 11), // "showComment"
QT_MOC_LITERAL(14, 129, 11), // "commentInfo"
QT_MOC_LITERAL(15, 141, 4) // "Show"

    },
    "comment\0sendComment\0\0commentJson\0"
    "queryComment\0labelId\0ProductId\0"
    "sendPraise\0on_pushButton_clicked\0"
    "praise\0id\0seq\0isadd\0showComment\0"
    "commentInfo\0Show"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_comment[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    2,   52,    2, 0x06 /* Public */,
       7,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   60,    2, 0x08 /* Private */,
       9,    5,   61,    2, 0x08 /* Private */,
      13,    1,   72,    2, 0x0a /* Public */,
      15,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QJsonObject,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::Bool,   10,    5,   11,    6,   12,
    QMetaType::Void, QMetaType::QJsonArray,   14,
    QMetaType::Void,

       0        // eod
};

void comment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        comment *_t = static_cast<comment *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendComment((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 1: _t->queryComment((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->sendPraise((*reinterpret_cast< QJsonObject(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->praise((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 5: _t->showComment((*reinterpret_cast< QJsonArray(*)>(_a[1]))); break;
        case 6: _t->Show(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (comment::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&comment::sendComment)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (comment::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&comment::queryComment)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (comment::*_t)(QJsonObject );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&comment::sendPraise)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject comment::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_comment.data,
      qt_meta_data_comment,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *comment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *comment::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_comment.stringdata0))
        return static_cast<void*>(const_cast< comment*>(this));
    return QDialog::qt_metacast(_clname);
}

int comment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void comment::sendComment(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void comment::queryComment(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void comment::sendPraise(QJsonObject _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
