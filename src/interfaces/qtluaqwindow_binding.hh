#ifndef QTLUAQWINDOW_BINDING_HH_
#define QTLUAQWINDOW_BINDING_HH_

#include <binding/Register>
#include <QWindow>

QTLUA_NS_BEGINE

// QTLUA_CONSTRUCTOR_DECLARE(QWindow)

QTLUA_METHOD_DECLARE(QWindow, fromWinId, "Creates a local representation of a window created by another process or by using native libraries below Qt.",
	"usage: qt.QtGui.QWindow.fromWinId( wid )\n")

void registerQWindowInterfaces();

QTLUA_NS_END

#endif