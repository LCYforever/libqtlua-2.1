#include <binding/qtluabindingmgr.hh>

QTLUA_NS_BEGINE

QtLua::Function::ptr InterfaceMgr::findInterface(const String &name)
{
	QtLua::Function::ptr fn;
	interface_mgr_table::Iterator iter = _interfaces.find(name);
	if (iter != _interfaces.end())
		fn = iter.value();

	return fn;
}

void InterfaceMgr::registerInterface(String name, QtLua::Function::ptr interface)
{
	_interfaces.insert(name, interface);
}

BindingMgr::~BindingMgr()
{

}

void BindingMgr::registerModule(String name, QtLua::InterfaceMgr::ptr module)
{
	_modules.insert(name, module);
}

QtLua::Function::ptr BindingMgr::findInterface(const String &module, const String &name)
{
	QtLua::Function::ptr fn;
	module_mgr_table::Iterator im = _modules.find(module);

	if (im != _modules.end()) fn = im.value()->findInterface(name);

	return fn;
}

BindingMgr& BindingMgr::Instance()
{
	static BindingMgr _inst;
	return _inst;
}

QTLUA_NS_END