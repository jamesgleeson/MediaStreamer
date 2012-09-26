/****************************************************************************
** Meta object code from reading C++ file 'MSMediaVolumeContolWidget.h'
**
<<<<<<< HEAD
** Created: Thu Aug 9 03:53:02 2012
=======
** Created: Mon Aug 6 03:30:09 2012
>>>>>>> parent of 3e56ec9... Removed "turgut/" folder from project files
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../MSMediaVolumeContolWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MSMediaVolumeContolWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSMediaVolumeContolWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   27,   26,   26, 0x05,
      55,   50,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,   27,   26,   26, 0x0a,
      88,   50,   26,   26, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MSMediaVolumeContolWidget[] = {
    "MSMediaVolumeContolWidget\0\0vol\0"
    "volumeChanged(int)\0mute\0muteChanged(bool)\0"
    "setVolume(int)\0setMuted(bool)\0"
};

void MSMediaVolumeContolWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MSMediaVolumeContolWidget *_t = static_cast<MSMediaVolumeContolWidget *>(_o);
        switch (_id) {
        case 0: _t->volumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->muteChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setMuted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MSMediaVolumeContolWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSMediaVolumeContolWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MSMediaVolumeContolWidget,
      qt_meta_data_MSMediaVolumeContolWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSMediaVolumeContolWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSMediaVolumeContolWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSMediaVolumeContolWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSMediaVolumeContolWidget))
        return static_cast<void*>(const_cast< MSMediaVolumeContolWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MSMediaVolumeContolWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MSMediaVolumeContolWidget::volumeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MSMediaVolumeContolWidget::muteChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
