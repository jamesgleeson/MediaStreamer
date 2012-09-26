/****************************************************************************
** Meta object code from reading C++ file 'TcpRequestSender.h'
**
** Created: Tue Sep 25 14:46:38 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../network/TcpRequestSender.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpRequestSender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSCommon__TcpRequestSender[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      40,   28,   27,   27, 0x0a,
      82,   27,   27,   27, 0x0a,
      94,   27,   27,   27, 0x0a,
     126,  109,   27,   27, 0x0a,
     166,  157,   27,   27, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_MSCommon__TcpRequestSender[] = {
    "MSCommon::TcpRequestSender\0\0socketError\0"
    "handleError(QAbstractSocket::SocketError)\0"
    "connected()\0disconnected()\0response,timeout\0"
    "readResponse(TcpResponse&,int)\0response\0"
    "readResponse(TcpResponse&)\0"
};

void MSCommon::TcpRequestSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpRequestSender *_t = static_cast<TcpRequestSender *>(_o);
        switch (_id) {
        case 0: _t->handleError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->connected(); break;
        case 2: _t->disconnected(); break;
        case 3: _t->readResponse((*reinterpret_cast< TcpResponse(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->readResponse((*reinterpret_cast< TcpResponse(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MSCommon::TcpRequestSender::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSCommon::TcpRequestSender::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MSCommon__TcpRequestSender,
      qt_meta_data_MSCommon__TcpRequestSender, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSCommon::TcpRequestSender::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSCommon::TcpRequestSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSCommon::TcpRequestSender::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSCommon__TcpRequestSender))
        return static_cast<void*>(const_cast< TcpRequestSender*>(this));
    return QObject::qt_metacast(_clname);
}

int MSCommon::TcpRequestSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
