#include <interfaces/qtluaqapplication_binding.hh>
#include "qtluaqtlib.hh"

QTLUA_NS_BEGINE

QTLUA_METHOD_IMPLEMENT(QApplication, startDragDistance)
{
	int distance = QApplication::startDragDistance();

	return Value(ls, distance);
}

void registerQApplicationInterfaces()
{
	QTLUA_INIT_MODULE(QApplication);
	QTLUA_BINDING_METHOD(QApplication, startDragDistance);
	QTLUA_END_MODULE(QApplication);

}

QTLUA_NS_END