/****************************************************************************
** Meta object code from reading C++ file 'TcpListener.h'
**
** Created: Tue Sep 25 14:46:37 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../network/TcpListener.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpListener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSCommon__TcpListener[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      34,   23,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MSCommon__TcpListener[] = {
    "MSCommon::TcpListener\0\0descriptor\0"
    "connectionClosed(int)\0"
};

void MSCommon::TcpListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpListener *_t = static_cast<TcpListener *>(_o);
        switch (_id) {
        case 0: _t->connectionClosed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MSCommon::TcpListener::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSCommon::TcpListener::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_MSCommon__TcpListener,
      qt_meta_data_MSCommon__TcpListener, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSCommon::TcpListener::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSCommon::TcpListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSCommon::TcpListener::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSCommon__TcpListener))
        return static_cast<void*>(const_cast< TcpListener*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int MSCommon::TcpListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
