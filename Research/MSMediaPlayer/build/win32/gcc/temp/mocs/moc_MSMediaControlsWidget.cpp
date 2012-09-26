/****************************************************************************
** Meta object code from reading C++ file 'MSMediaControlsWidget.h'
**
<<<<<<< HEAD
** Created: Thu Aug 9 03:52:48 2012
=======
** Created: Fri Aug 3 12:56:32 2012
>>>>>>> parent of 3e56ec9... Removed "turgut/" folder from project files
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../MSMediaControlsWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MSMediaControlsWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSMediaControlsWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x05,
      45,   22,   22,   22, 0x05,
      61,   22,   22,   22, 0x05,
      84,   22,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
     105,   22,   22,   22, 0x0a,
     118,   22,   22,   22, 0x0a,
     125,   22,   22,   22, 0x0a,
     139,   22,   22,   22, 0x0a,
     154,  151,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MSMediaControlsWidget[] = {
    "MSMediaControlsWidget\0\0togglePlayTriggered()\0"
    "stopTriggered()\0seekToBeginTriggered()\0"
    "seekToEndTriggered()\0togglePlay()\0"
    "stop()\0seekToBegin()\0seekToEnd()\0st\0"
    "updateWidgetState(Vlc::State)\0"
};

void MSMediaControlsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MSMediaControlsWidget *_t = static_cast<MSMediaControlsWidget *>(_o);
        switch (_id) {
        case 0: _t->togglePlayTriggered(); break;
        case 1: _t->stopTriggered(); break;
        case 2: _t->seekToBeginTriggered(); break;
        case 3: _t->seekToEndTriggered(); break;
        case 4: _t->togglePlay(); break;
        case 5: _t->stop(); break;
        case 6: _t->seekToBegin(); break;
        case 7: _t->seekToEnd(); break;
        case 8: _t->updateWidgetState((*reinterpret_cast< const Vlc::State(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MSMediaControlsWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSMediaControlsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MSMediaControlsWidget,
      qt_meta_data_MSMediaControlsWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSMediaControlsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSMediaControlsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSMediaControlsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSMediaControlsWidget))
        return static_cast<void*>(const_cast< MSMediaControlsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MSMediaControlsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MSMediaControlsWidget::togglePlayTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MSMediaControlsWidget::stopTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MSMediaControlsWidget::seekToBeginTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MSMediaControlsWidget::seekToEndTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
