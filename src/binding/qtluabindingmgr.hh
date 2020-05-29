#ifndef QTLUABINDINGMGR_HH_
#define QTLUABINDINGMGR_HH_

#include <QtLua/Ref>
#include <QtLua/Function>

QTLUA_NS_BEGINE

typedef QMap<String, QtLua::Function::ptr> interface_mgr_table;
class QTLUA_API InterfaceMgr : public QtLua::Refobj<InterfaceMgr>
{
public:
	QTLUA_REFTYPE(InterfaceMgr);

	InterfaceMgr() {}
	~InterfaceMgr() {}

	QtLua::Function::ptr findInterface(const String &name);
	void registerInterface(String name, QtLua::Function::ptr interface);

private:
	interface_mgr_table _interfaces;
};

/**
 * @short Qt class module manual binding interfaces manager class
 * @header binding/BindingMgr
 * @module {method wrapping}
 * @binding
 *
 * This is the class module for manual binding Method manager
 * manager classes.
 */

typedef QMap<String, InterfaceMgr::ptr> module_mgr_table;
class QTLUA_API BindingMgr
{
public:
	BindingMgr() {}
	~BindingMgr();

	void registerModule(String name, QtLua::InterfaceMgr::ptr module);
	QtLua::Function::ptr findInterface(const String &module, const String &name);

	static BindingMgr& Instance();

protected:
	module_mgr_table _modules;
};

QTLUA_NS_END
#endif