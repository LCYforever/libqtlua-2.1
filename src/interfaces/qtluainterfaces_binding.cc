#include "interfaces/qtluainterfaces_binding.hh"

#include "interfaces/qtluaqwindow_binding.hh"
#include "interfaces/qtluaqapplication_binding.hh"

QTLUA_NS_BEGINE

void registerManualInterfaces()
{
	registerQWindowInterfaces();
	registerQApplicationInterfaces();
}

QTLUA_NS_END