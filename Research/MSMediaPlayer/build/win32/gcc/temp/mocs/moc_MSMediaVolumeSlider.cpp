/****************************************************************************
** Meta object code from reading C++ file 'MSMediaVolumeSlider.h'
**
<<<<<<< HEAD
** Created: Thu Aug 9 03:52:59 2012
=======
** Created: Fri Aug 3 12:56:42 2012
>>>>>>> parent of 3e56ec9... Removed "turgut/" folder from project files
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../MSMediaVolumeSlider.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MSMediaVolumeSlider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSMediaVolumeSlider[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   21,   20,   20, 0x0a,
      45,   41,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MSMediaVolumeSlider[] = {
    "MSMediaVolumeSlider\0\0mute\0setMuted(bool)\0"
    "vol\0setVolume(int)\0"
};

void MSMediaVolumeSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MSMediaVolumeSlider *_t = static_cast<MSMediaVolumeSlider *>(_o);
        switch (_id) {
        case 0: _t->setMuted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MSMediaVolumeSlider::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSMediaVolumeSlider::staticMetaObject = {
    { &QSlider::staticMetaObject, qt_meta_stringdata_MSMediaVolumeSlider,
      qt_meta_data_MSMediaVolumeSlider, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSMediaVolumeSlider::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSMediaVolumeSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSMediaVolumeSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSMediaVolumeSlider))
        return static_cast<void*>(const_cast< MSMediaVolumeSlider*>(this));
    return QSlider::qt_metacast(_clname);
}

int MSMediaVolumeSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
