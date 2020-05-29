#include "interfaces/qtluainterfaces_binding.hh"

#include "interfaces/qtluaqwindow_binding.hh"

QTLUA_NS_BEGINE

void registerManualInterfaces()
{
	registerQWindowInterfaces();
}

QTLUA_NS_END