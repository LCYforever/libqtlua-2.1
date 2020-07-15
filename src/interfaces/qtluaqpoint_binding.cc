#include <interfaces/qtluaqpoint_binding.hh>
#include "qtluaqtlib.hh"

QTLUA_NS_BEGINE

QTLUA_METHOD_IMPLEMENT(QPoint, new)
{
	QPoint point;
	return Value(ls, point);
}

void registerQPointInterfaces()
{
	QTLUA_INIT_MODULE(QPoint);
	QTLUA_BINDING_METHOD(QPoint, new);

	QTLUA_END_MODULE(QPoint);
}

QTLUA_NS_END