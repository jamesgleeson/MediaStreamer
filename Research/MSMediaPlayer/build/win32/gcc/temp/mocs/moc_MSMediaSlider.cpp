/****************************************************************************
** Meta object code from reading C++ file 'MSMediaSlider.h'
**
<<<<<<< HEAD
** Created: Thu Aug 9 03:52:54 2012
=======
** Created: Fri Aug 3 12:56:37 2012
>>>>>>> parent of 3e56ec9... Removed "turgut/" folder from project files
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../MSMediaSlider.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MSMediaSlider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSMediaSlider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       1,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   36,   14,   14, 0x0a,
      74,   70,   14,   14, 0x0a,
      97,   14,   14,   14, 0x0a,
     110,   14,   14,   14, 0x08,
     127,   14,   14,   14, 0x08,

 // properties: name, type, flags
     145,  139, ((uint)QMetaType::QReal << 24) | 0x00095103,

       0        // eod
};

static const char qt_meta_stringdata_MSMediaSlider[] = {
    "MSMediaSlider\0\0sliderDragged(float)\0"
    ",,\0setPosition(float,int64_t,int)\0buf\0"
    "updateBuffering(float)\0hideHandle()\0"
    "startSeekTimer()\0updatePos()\0qreal\0"
    "handleOpacity\0"
};

void MSMediaSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MSMediaSlider *_t = static_cast<MSMediaSlider *>(_o);
        switch (_id) {
        case 0: _t->sliderDragged((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->setPosition((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int64_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->updateBuffering((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->hideHandle(); break;
        case 4: _t->startSeekTimer(); break;
        case 5: _t->updatePos(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MSMediaSlider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSMediaSlider::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_MSMediaSlider,
      qt_meta_data_MSMediaSlider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSMediaSlider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSMediaSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSMediaSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSMediaSlider))
        return static_cast<void*>(const_cast< MSMediaSlider*>(this));
    return QSlider::qt_metacast(_clname);
}

int MSMediaSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = handleOpacity(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setHandleOpacity(*reinterpret_cast< qreal*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MSMediaSlider::sliderDragged(float _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
