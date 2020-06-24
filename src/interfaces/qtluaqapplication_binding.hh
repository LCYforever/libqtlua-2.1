#ifndef QTLUAQAPPLICATION_BINDING_HH_
#define QTLUAQAPPLICATION_BINDING_HH_

#include <binding/Register>
#include <QApplication>

QTLUA_NS_BEGINE

QTLUA_METHOD_DECLARE(QApplication, startDragDistance, "If you support drag and drop in your application, and want to start a drag and drop operation after the user has moved the cursor a certain distance with a button held down, you should use this property's value as the minimum distance required.",
	"usage: qt.QtGui.QApplication.startDragDistance()\n")

void registerQApplicationInterfaces();

QTLUA_NS_END

#endif