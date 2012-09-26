/****************************************************************************
** Meta object code from reading C++ file 'TestRecorder.h'
**
** Created: Wed Jul 25 00:35:01 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TestRecorder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestRecorder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestRecorder[] = {

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
      14,   13,   13,   13, 0x08,
      21,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestRecorder[] = {
    "TestRecorder\0\0play()\0stop()\0"
};

void TestRecorder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestRecorder *_t = static_cast<TestRecorder *>(_o);
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->stop(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TestRecorder::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestRecorder::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TestRecorder,
      qt_meta_data_TestRecorder, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestRecorder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestRecorder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestRecorder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestRecorder))
        return static_cast<void*>(const_cast< TestRecorder*>(this));
    return QDialog::qt_metacast(_clname);
}

int TestRecorder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
