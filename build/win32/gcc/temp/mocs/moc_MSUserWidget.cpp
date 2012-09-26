/****************************************************************************
** Meta object code from reading C++ file 'MSUserWidget.h'
**
** Created: Tue Sep 25 10:07:30 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../MSAdministrator/gui/users/MSUserWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MSUserWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MSAdministrator__MSUsersWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   31,   31,   31, 0x0a,
      52,   31,   31,   31, 0x0a,
      73,   31,   31,   31, 0x0a,
      96,   31,   31,   31, 0x0a,
     120,   31,   31,   31, 0x0a,
     141,   31,   31,   31, 0x0a,
     166,   31,   31,   31, 0x0a,
     188,   31,   31,   31, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MSAdministrator__MSUsersWidget[] = {
    "MSAdministrator::MSUsersWidget\0\0"
    "btnUserAddClicked()\0btnUserEditClicked()\0"
    "btnUserRemoveClicked()\0btnUserRefreshClicked()\0"
    "activateUserWidget()\0itemClicked(QModelIndex)\0"
    "refreshUserList(bool)\0refreshButtons(bool)\0"
};

void MSAdministrator::MSUsersWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MSUsersWidget *_t = static_cast<MSUsersWidget *>(_o);
        switch (_id) {
        case 0: _t->btnUserAddClicked(); break;
        case 1: _t->btnUserEditClicked(); break;
        case 2: _t->btnUserRemoveClicked(); break;
        case 3: _t->btnUserRefreshClicked(); break;
        case 4: _t->activateUserWidget(); break;
        case 5: _t->itemClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->refreshUserList((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->refreshButtons((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MSAdministrator::MSUsersWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MSAdministrator::MSUsersWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MSAdministrator__MSUsersWidget,
      qt_meta_data_MSAdministrator__MSUsersWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MSAdministrator::MSUsersWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MSAdministrator::MSUsersWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MSAdministrator::MSUsersWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MSAdministrator__MSUsersWidget))
        return static_cast<void*>(const_cast< MSUsersWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MSAdministrator::MSUsersWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
