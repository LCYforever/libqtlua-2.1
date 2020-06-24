#include <interfaces/qtluaqwindow_binding.hh>
#include "qtluaqtlib.hh"

QTLUA_NS_BEGINE

//QTLUA_CONSTRUCTOR_IMPLEMENT(QWindow)

QTLUA_METHOD_IMPLEMENT(QWindow, fromWinId)
{
	WId id = (unsigned int)get_arg<unsigned int>(args, 0);
	QWindow* win = QWindow::fromWinId(id);

	return Value(ls, win, true, true);
}

void registerQWindowInterfaces()
{
	QTLUA_INIT_MODULE(QWindow);
	QTLUA_BINDING_METHOD(QWindow, fromWinId);

	QTLUA_END_MODULE(QWindow);
}

QTLUA_NS_END