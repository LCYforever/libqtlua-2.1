#ifndef QTLUAQTIMER_BINDING_HH_
#define QTLUAQTIMER_BINDING_HH_

#include <binding/Register>
#include <QTimer>

QTLUA_NS_BEGINE


QTLUA_METHOD_DECLARE(QTimer, fromWinId, "Creates a local representation of a window created by another process or by using native libraries below Qt.",
	"usage: qt.QtGui.QWindow.fromWinId( wid )\n")

void registerQWindowInterfaces();

QTLUA_NS_END

#endif