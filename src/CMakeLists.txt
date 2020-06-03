
# Generate moc files
QT5_WRAP_CPP(MOC_OUTFILES QtLua/qtluaconsole.hh        OPTIONS -fQtLua/Console)
QT5_WRAP_CPP(MOC_OUTFILES QtLua/qtluauseritemselectionmodel.hh OPTIONS -fQtLua/UserItemSelectionModel)
QT5_WRAP_CPP(MOC_OUTFILES QtLua/qtluauseritemmodel.hh  OPTIONS -fQtLua/UserItemModel)
QT5_WRAP_CPP(MOC_OUTFILES QtLua/qtlualuamodel.hh       OPTIONS  -fQtLua/LuaModel)
QT5_WRAP_CPP(MOC_OUTFILES QtLua/qtluatabletreemodel.hh OPTIONS -fQtLua/TableTreeModel)
QT5_WRAP_CPP(MOC_OUTFILES QtLua/qtluaitemviewdialog.hh OPTIONS -fQtLua/ItemViewDialog)
QT5_WRAP_CPP(MOC_OUTFILES QtLua/qtluatablegridmodel.hh OPTIONS -fQtLua/TableGridModel)
QT5_WRAP_CPP(MOC_OUTFILES QtLua/qtluastate.hh          OPTIONS -fQtLua/State)
QT5_WRAP_CPP(MOC_OUTFILES qtluaqtlib.hh)

SET(QTLUA_HEADERS 
	QtLua/qtluafunction.hh        QtLua/qtluafunction.hxx
	QtLua/qtluaconsole.hh         QtLua/qtluaconsole.hxx
	QtLua/qtluatabletreemodel.hh  QtLua/qtluatabletreemodel.hxx
	QtLua/qtluaitemviewdialog.hh  QtLua/qtluaitemviewdialog.hxx
	QtLua/qtluatablegridmodel.hh  QtLua/qtluatablegridmodel.hxx
	QtLua/qtlualuamodel.hh        QtLua/qtlualuamodel.hxx
	QtLua/qtluauseritem.hh        QtLua/qtluauseritem.hxx
	QtLua/qtluauserlistitem.hh    QtLua/qtluauserlistitem.hxx
	QtLua/qtluauseritemmodel.hh   QtLua/qtluauseritemmodel.hxx
	QtLua/qtluauseritemselectionmodel.hh QtLua/qtluauseritemselectionmodel.hxx
	QtLua/qtluaiterator.hh        QtLua/qtluaiterator.hxx
	QtLua/qtluaplugin.hh          QtLua/qtluaplugin.hxx
	QtLua/qtluastate.hh           QtLua/qtluastate.hxx
	QtLua/qtluauserdata.hh        QtLua/qtluauserdata.hxx
	QtLua/qtluauserobject.hh      QtLua/qtluauserobject.hxx
	QtLua/qtluavaluebase.hh       QtLua/qtluavaluebase.hxx
	QtLua/qtluavalue.hh           QtLua/qtluavalue.hxx
	QtLua/qtluavalueref.hh        QtLua/qtluavalueref.hxx
	QtLua/qtluaref.hh
	QtLua/qtluastring.hh          QtLua/qtluastring.hxx
	QtLua/qtluaqhashproxy.hh      QtLua/qtluaqhashproxy.hxx
	QtLua/qtluaqvectorproxy.hh    QtLua/qtluaqvectorproxy.hxx
	QtLua/qtluaqlistproxy.hh      QtLua/qtluaqlistproxy.hxx
	QtLua/qtluaqlinkedlistproxy.hh QtLua/qtluaqlinkedlistproxy.hxx
	QtLua/qtluaarrayproxy.hh      QtLua/qtluaarrayproxy.hxx
	QtLua/qtluametatype.hh        QtLua/qtluametatype.hxx
	QtLua/qtluadispatchproxy.hh   QtLua/qtluadispatchproxy.hxx)

SET(INTERNAL_HEADERS
	internal/qtluaenum.hh internal/qtluaenum.hxx
	internal/qtluaenumiterator.hh internal/qtlualistiterator.hh
	internal/qtluamember.hh internal/qtluamember.hxx
	internal/qtluametacache.hh internal/qtluametacache.hxx
	internal/qtluamethod.hh internal/qtluamethod.hxx
	internal/qtluapoolarray.hh internal/qtluaqobjectiterator.hh
	internal/qtluaqmetaobjectwrapper.hh internal/qtluatableiterator.hh
	internal/qtluaproperty.hh internal/qtluaproperty.hxx
	internal/qtluaqmetavalue.hh internal/qtluaqmetavalue.hxx
	internal/qtluaqobjectwrapper.hh internal/qtluaqobjectwrapper.hxx
	internal/qtluatabletreekeys.hh internal/qtluatabletreekeys.hxx
	)

SET(BINDINGS_FILES
	binding/qtluabindingmgr.hh binding/qtluabindingmgr.cc
	binding/qtluaregister.hh
	)

SET(BINDING_INTERFACES
	interfaces/qtluainterfaces_binding.hh interfaces/qtluainterfaces_binding.cc
	interfaces/qtluaqwindow_binding.hh interfaces/qtluaqwindow_binding.cc
	)

source_group("binding" FILES ${BINDINGS_FILES})
source_group("interfaces" FILES ${BINDING_INTERFACES})

ADD_LIBRARY(qtlua SHARED
			qtluaconfig.hh
			qtluaqtlib.hh
			${INTERNAL_HEADERS}
			${QTLUA_HEADERS}
			${BINDINGS_FILES}
			${BINDING_INTERFACES}
            qtluaconsole.cc qtluaenum.cc
            qtluaenumiterator.cc qtluafunction.cc
            qtluauseritem.cc qtluauseritemmodel.cc
            qtluauseritemselectionmodel.cc
            qtluauserlistitem.cc qtlualistiterator.cc
            qtluamember.cc qtluametacache.cc
            qtluamethod.cc qtluaplugin.cc qtluaproperty.cc
            qtluaqmetaobjecttable.cc qtluaqmetavalue.cc
            qtluaqmetaobjectwrapper.cc qtlualuamodel.cc
            qtluaqobjectiterator.cc qtluaqobjectwrapper.cc
            qtluaqtlib.cc qtluastate.cc
            qtluaitemviewdialog.cc qtluatablegridmodel.cc
            qtluatableiterator.cc qtluatabletreekeys.cc
            qtluatabletreemodel.cc qtluauserdata.cc
            qtluavaluebase.cc qtluavalue.cc
            qtluavalueref.cc qtluadispatchproxy.cc
			
            ${MOC_OUTFILES})

QT5_USE_MODULES(qtlua Widgets Core UiTools)

TARGET_LINK_LIBRARIES(qtlua ${QT_LIBRARIES} ${LUA_LIBRARIES})

INSTALL(TARGETS qtlua
	LIBRARY DESTINATION ${INSTALL_LIB}
	ARCHIVE DESTINATION ${INSTALL_LIB})

INSTALL(FILES
        QtLua/Function
		QtLua/Console
        QtLua/TableTreeModel
        QtLua/ItemViewDialog
        QtLua/TableGridModel
        QtLua/LuaModel
        QtLua/UserItem
        QtLua/UserListItem
        QtLua/UserItemModel
        QtLua/UserItemSelectionModel
        QtLua/Iterator
        QtLua/Plugin
        QtLua/State
        QtLua/UserData
        QtLua/UserObject
        QtLua/ValueBase
        QtLua/Value
        QtLua/ValueRef
        QtLua/Ref
        QtLua/String
        QtLua/QHashProxy
        QtLua/QVectorProxy
        QtLua/QListProxy
        QtLua/QLinkedListProxy
        QtLua/ArrayProxy
        QtLua/MetaType
        QtLua/DispatchProxy
		${QTLUA_HEADERS}
        DESTINATION ${INSTALL_INC}/QtLua)

