/****************************************************************************
** Meta object code from reading C++ file 'showData.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../showData.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_showData_t {
    QByteArrayData data[10];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_showData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_showData_t qt_meta_stringdata_showData = {
    {
QT_MOC_LITERAL(0, 0, 8), // "showData"
QT_MOC_LITERAL(1, 9, 17), // "signalSendPicName"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "str"
QT_MOC_LITERAL(4, 32, 18), // "slotReceivePicName"
QT_MOC_LITERAL(5, 51, 14), // "updataProgress"
QT_MOC_LITERAL(6, 66, 9), // "num_bytes"
QT_MOC_LITERAL(7, 76, 22), // "slotTCPConnectincoming"
QT_MOC_LITERAL(8, 99, 15), // "slotConnect_suc"
QT_MOC_LITERAL(9, 115, 14) // "slotClient_dis"

    },
    "showData\0signalSendPicName\0\0str\0"
    "slotReceivePicName\0updataProgress\0"
    "num_bytes\0slotTCPConnectincoming\0"
    "slotConnect_suc\0slotClient_dis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_showData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       5,    1,   50,    2, 0x0a /* Public */,
       7,    0,   53,    2, 0x0a /* Public */,
       8,    0,   54,    2, 0x0a /* Public */,
       9,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::LongLong,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void showData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        showData *_t = static_cast<showData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalSendPicName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->slotReceivePicName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updataProgress((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->slotTCPConnectincoming(); break;
        case 4: _t->slotConnect_suc(); break;
        case 5: _t->slotClient_dis(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (showData::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&showData::signalSendPicName)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject showData::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_showData.data,
      qt_meta_data_showData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *showData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *showData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_showData.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int showData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void showData::signalSendPicName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
