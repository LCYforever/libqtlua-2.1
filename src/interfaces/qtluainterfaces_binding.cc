#include "interfaces/qtluainterfaces_binding.hh"
#include "interfaces/qtluaqwindow_binding.hh"
#include "interfaces/qtluaqapplication_binding.hh"
#include "interfaces/qtluaqpoint_binding.hh"
#include "binding/qtluabindingmgr.hh"

QTLUA_NS_BEGINE

void registerManualInterfaces(State* ls)
{
	registerQPointInterfaces();
	registerQWindowInterfaces();
	registerQApplicationInterfaces();

	module_mgr_table _modules = BindingMgr::Instance()._modules;
	module_mgr_table::Iterator iter = _modules.begin();

	for (; iter != _modules.end(); ++iter)
	{
#define REGISTER_QT_MODULE(module, wrapper) \
	ls->set_global("qt."+ module, Value(ls, wrapper))
		REGISTER_QT_MODULE(iter.key(), iter.value());
	}
}

QTLUA_NS_END