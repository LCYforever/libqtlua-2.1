#ifndef QTLUAREGISTER_HH_
#define QTLUAREGISTER_HH_

#include <binding/qtluabindingmgr.hh>

QTLUA_NS_BEGINE

#define QTLUA_METHOD_DECLARE(module, method, description, help) \
	QTLUA_FUNCTION_DECL(module##_##method, description, help)

#define QTLUA_METHOD_IMPLEMENT(module, method) \
	QTLUA_FUNCTION_BODY(module##_##method)

#define QTLUA_BINDING_METHOD(module, method) \
	M->registerInterface(#method, QTLUA_REFNEW(QtLua_Function_##module##_##method));

#define CONSTRUCT_DESCRIPTION(module) \
	"Dynamically create a new "#module"."
#define CONSTRUCTOR_HELP(module) \
	"usage: "#module".new( [ Constructor arguments ] )\n"

#define QTLUA_CONSTRUCTOR_DECLARE(module) \
	QTLUA_METHOD_DECLARE(module, new,  CONSTRUCT_DESCRIPTION(module), \
	CONSTRUCTOR_HELP(module))

#define QTLUA_CONSTRUCTOR_IMPLEMENT(module) \
	QTLUA_FUNCTION_BODY(module##_new) \
	{ \
		QMetaObjectWrapper::ptr mow = QMetaObjectTable::Instance().findMetaObjWrapper(#module); \
		\
		return Value(ls, mow->create(args), true, true); \
	}

#define QTLUA_BINDING_CONSTRUCTOR(module) \
	M->registerInterface("new", QTLUA_REFNEW(QtLua_Function_##module##_new));

#define QTLUA_INIT_MODULE(module) \
	InterfaceMgr::ptr M = QTLUA_REFNEW(InterfaceMgr); \
	QTLUA_BINDING_CONSTRUCTOR(module)

#define QTLUA_END_MODULE(module) \
	BindingMgr::Instance().registerModule(#module, M);
	

QTLUA_NS_END
#endif