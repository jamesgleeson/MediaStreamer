/****************************************************************************
** Meta object code from reading C++ file 'TestMain.h'
**
** Created: Wed Jul 25 02:17:22 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TestMain.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestMain[] = {

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
      10,    9,    9,    9, 0x08,
      25,    9,    9,    9, 0x08,
      38,    9,    9,    9, 0x08,
      44,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestMain[] = {
    "TestMain\0\0dualInstance()\0dualPlayer()\0"
    "lib()\0player()\0"
};

void TestMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestMain *_t = static_cast<TestMain *>(_o);
        switch (_id) {
        case 0: _t->dualInstance(); break;
        case 1: _t->dualPlayer(); break;
        case 2: _t->lib(); break;
        case 3: _t->player(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TestMain::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TestMain,
      qt_meta_data_TestMain, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestMain))
        return static_cast<void*>(const_cast< TestMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TestMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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