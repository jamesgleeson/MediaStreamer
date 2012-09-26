/****************************************************************************
** Meta object code from reading C++ file 'MSTcpRequestHandler.h'
**
** Created: Mon Sep 24 08:17:14 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../MSServer/network/MSTcpRequestHandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MSTcpRequestHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSServer__MSTcpRequestHandler[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x0a,
      46,   30,   30,   30, 0x0a,
      67,   58,   30,   30, 0x0a,
      94,   30,   30,   30, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MSServer__MSTcpRequestHandler[] = {
    "MSServer::MSTcpRequestHandler\0\0"
    "disconnected()\0readyRead()\0response\0"
    "sendResponse(TcpResponse*)\0socketDestroyed()\0"
};

void MSServer::MSTcpRequestHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MSTcpRequestHandler *_t = static_cast<MSTcpRequestHandler *>(_o);
        switch (_id) {
        case 0: _t->disconnected(); break;
        case 1: _t->readyRead(); break;
        case 2: _t->sendResponse((*reinterpret_cast< TcpResponse*(*)>(_a[1]))); break;
        case 3: _t->socketDestroyed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MSServer::MSTcpRequestHandler::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSServer::MSTcpRequestHandler::staticMetaObject = {
    { &TcpRequestHandler::staticMetaObject, qt_meta_stringdata_MSServer__MSTcpRequestHandler,
      qt_meta_data_MSServer__MSTcpRequestHandler, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSServer::MSTcpRequestHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSServer::MSTcpRequestHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSServer::MSTcpRequestHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSServer__MSTcpRequestHandler))
        return static_cast<void*>(const_cast< MSTcpRequestHandler*>(this));
    return TcpRequestHandler::qt_metacast(_clname);
}

int MSServer::MSTcpRequestHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TcpRequestHandler::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
