/****************************************************************************
** Meta object code from reading C++ file 'TestMetaManager.h'
**
** Created: Wed Jul 25 00:35:03 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../TestMetaManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestMetaManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestMetaManager[] = {

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
      17,   16,   16,   16, 0x08,
      24,   16,   16,   16, 0x08,
      31,   16,   16,   16, 0x08,
      38,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestMetaManager[] = {
    "TestMetaManager\0\0open()\0read()\0save()\0"
    "set()\0"
};

void TestMetaManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestMetaManager *_t = static_cast<TestMetaManager *>(_o);
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->read(); break;
        case 2: _t->save(); break;
        case 3: _t->set(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TestMetaManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestMetaManager::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TestMetaManager,
      qt_meta_data_TestMetaManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestMetaManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestMetaManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestMetaManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestMetaManager))
        return static_cast<void*>(const_cast< TestMetaManager*>(this));
    return QDialog::qt_metacast(_clname);
}

int TestMetaManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
