#ifndef QTLUAQPOINT_BINDING_HH_
#define QTLUAQPOINT_BINDING_HH_

#include <binding/Register>
#include <QPoint>

QTLUA_NS_BEGINE

QTLUA_METHOD_DECLARE(QPoint, new, "constructor a QPoint object",
	"usage: qt.QPoint.QPoint.new()\n")

void registerQPointInterfaces();

QTLUA_NS_END

#endif