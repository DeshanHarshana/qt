/****************************************************************************
** Meta object code from reading C++ file 'dowork.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../progressBar/dowork.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dowork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DoWork_t {
    QByteArrayData data[14];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DoWork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DoWork_t qt_meta_stringdata_DoWork = {
    {
QT_MOC_LITERAL(0, 0, 6), // "DoWork"
QT_MOC_LITERAL(1, 7, 17), // "emitRandomNumber1"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 1), // "x"
QT_MOC_LITERAL(4, 28, 17), // "emitRandomNumber2"
QT_MOC_LITERAL(5, 46, 17), // "emitRandomNumber3"
QT_MOC_LITERAL(6, 64, 17), // "emitRandomNumber4"
QT_MOC_LITERAL(7, 82, 9), // "emitTimer"
QT_MOC_LITERAL(8, 92, 4), // "time"
QT_MOC_LITERAL(9, 97, 7), // "worker1"
QT_MOC_LITERAL(10, 105, 7), // "worker2"
QT_MOC_LITERAL(11, 113, 7), // "worker3"
QT_MOC_LITERAL(12, 121, 7), // "worker4"
QT_MOC_LITERAL(13, 129, 5) // "timer"

    },
    "DoWork\0emitRandomNumber1\0\0x\0"
    "emitRandomNumber2\0emitRandomNumber3\0"
    "emitRandomNumber4\0emitTimer\0time\0"
    "worker1\0worker2\0worker3\0worker4\0timer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DoWork[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,
       6,    1,   73,    2, 0x06 /* Public */,
       7,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   79,    2, 0x0a /* Public */,
      10,    0,   80,    2, 0x0a /* Public */,
      11,    0,   81,    2, 0x0a /* Public */,
      12,    0,   82,    2, 0x0a /* Public */,
      13,    0,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DoWork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DoWork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->emitRandomNumber1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->emitRandomNumber2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->emitRandomNumber3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->emitRandomNumber4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->emitTimer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->worker1(); break;
        case 6: _t->worker2(); break;
        case 7: _t->worker3(); break;
        case 8: _t->worker4(); break;
        case 9: _t->timer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DoWork::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoWork::emitRandomNumber1)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DoWork::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoWork::emitRandomNumber2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DoWork::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoWork::emitRandomNumber3)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DoWork::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoWork::emitRandomNumber4)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DoWork::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DoWork::emitTimer)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DoWork::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_DoWork.data,
    qt_meta_data_DoWork,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DoWork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DoWork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DoWork.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int DoWork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DoWork::emitRandomNumber1(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DoWork::emitRandomNumber2(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DoWork::emitRandomNumber3(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DoWork::emitRandomNumber4(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DoWork::emitTimer(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
