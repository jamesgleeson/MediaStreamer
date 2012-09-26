/****************************************************************************
** Meta object code from reading C++ file 'CustomPlayerWindow.h'
**
<<<<<<< HEAD
** Created: Thu Aug 9 03:53:10 2012
=======
** Created: Fri Aug 3 12:56:57 2012
>>>>>>> parent of 3e56ec9... Removed "turgut/" folder from project files
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../CustomPlayerWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CustomPlayerWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CustomMediaPlayer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CustomMediaPlayer[] = {
    "CustomMediaPlayer\0"
};

void CustomMediaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CustomMediaPlayer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CustomMediaPlayer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CustomMediaPlayer,
      qt_meta_data_CustomMediaPlayer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CustomMediaPlayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CustomMediaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CustomMediaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CustomMediaPlayer))
        return static_cast<void*>(const_cast< CustomMediaPlayer*>(this));
    return QWidget::qt_metacast(_clname);
}

int CustomMediaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
