/*
	This file is part of LibQtLua.

	LibQtLua is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	LibQtLua is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with LibQtLua.  If not, see <http://www.gnu.org/licenses/>.

	Copyright (C) 2008, Alexandre Becoulet <alexandre.becoulet@free.fr>

*/
#include <binding/Register>

QTLUA_NS_BEGINE

// customized class
QTLUA_CONSTRUCTOR_DECLARE(Console)
QTLUA_CONSTRUCTOR_DECLARE(UserItemSelectionModel)
QTLUA_CONSTRUCTOR_DECLARE(UserItemModel)
QTLUA_CONSTRUCTOR_DECLARE(ItemViewDialog)
QTLUA_CONSTRUCTOR_DECLARE(TableTreeModel)
QTLUA_CONSTRUCTOR_DECLARE(TableGridModel)
QTLUA_CONSTRUCTOR_DECLARE(LuaModel)

// qt class
QTLUA_CONSTRUCTOR_DECLARE(QAbstractItemDelegate)
QTLUA_CONSTRUCTOR_DECLARE(QAbstractItemModel)
QTLUA_CONSTRUCTOR_DECLARE(QAbstractItemView)
QTLUA_CONSTRUCTOR_DECLARE(QAction)
QTLUA_CONSTRUCTOR_DECLARE(QApplication)
QTLUA_CONSTRUCTOR_DECLARE(QButtonGroup)
QTLUA_CONSTRUCTOR_DECLARE(QCalendarWidget)
QTLUA_CONSTRUCTOR_DECLARE(QCheckBox)
QTLUA_CONSTRUCTOR_DECLARE(QClipboard)
QTLUA_CONSTRUCTOR_DECLARE(QColorDialog)
QTLUA_CONSTRUCTOR_DECLARE(QColumnView)
QTLUA_CONSTRUCTOR_DECLARE(QComboBox)
QTLUA_CONSTRUCTOR_DECLARE(QCoreApplication)
QTLUA_CONSTRUCTOR_DECLARE(QDateEdit)
QTLUA_CONSTRUCTOR_DECLARE(QDateTimeEdit)
QTLUA_CONSTRUCTOR_DECLARE(QDesktopWidget)
QTLUA_CONSTRUCTOR_DECLARE(QDial)
QTLUA_CONSTRUCTOR_DECLARE(QDialog)
QTLUA_CONSTRUCTOR_DECLARE(QDialogButtonBox)
QTLUA_CONSTRUCTOR_DECLARE(QDockWidget)
QTLUA_CONSTRUCTOR_DECLARE(QDoubleSpinBox)
QTLUA_CONSTRUCTOR_DECLARE(QErrorMessage)
QTLUA_CONSTRUCTOR_DECLARE(QFile)
QTLUA_CONSTRUCTOR_DECLARE(QFileDialog)
QTLUA_CONSTRUCTOR_DECLARE(QFocusFrame)
QTLUA_CONSTRUCTOR_DECLARE(QFont)
QTLUA_CONSTRUCTOR_DECLARE(QFontDialog)
QTLUA_CONSTRUCTOR_DECLARE(QFrame)
QTLUA_CONSTRUCTOR_DECLARE(QGraphicsScene)
QTLUA_CONSTRUCTOR_DECLARE(QGraphicsView)
QTLUA_CONSTRUCTOR_DECLARE(QGridLayout)
QTLUA_CONSTRUCTOR_DECLARE(QGroupBox)
QTLUA_CONSTRUCTOR_DECLARE(QHBoxLayout)
QTLUA_CONSTRUCTOR_DECLARE(QHeaderView)
QTLUA_CONSTRUCTOR_DECLARE(QInputDialog)
QTLUA_CONSTRUCTOR_DECLARE(QItemDelegate)
QTLUA_CONSTRUCTOR_DECLARE(QLCDNumber)
QTLUA_CONSTRUCTOR_DECLARE(QLabel)
QTLUA_CONSTRUCTOR_DECLARE(QLayout)
QTLUA_CONSTRUCTOR_DECLARE(QLibrary)
QTLUA_CONSTRUCTOR_DECLARE(QLineEdit)
QTLUA_CONSTRUCTOR_DECLARE(QListView)
QTLUA_CONSTRUCTOR_DECLARE(QListWidget)
QTLUA_CONSTRUCTOR_DECLARE(QLocale)
QTLUA_CONSTRUCTOR_DECLARE(QMainWindow)
QTLUA_CONSTRUCTOR_DECLARE(QMdiArea)
QTLUA_CONSTRUCTOR_DECLARE(QMdiSubWindow)
QTLUA_CONSTRUCTOR_DECLARE(QMenu)
QTLUA_CONSTRUCTOR_DECLARE(QMenuBar)
QTLUA_CONSTRUCTOR_DECLARE(QMessageBox)
QTLUA_CONSTRUCTOR_DECLARE(QObject)
QTLUA_CONSTRUCTOR_DECLARE(QPainter)
QTLUA_CONSTRUCTOR_DECLARE(QPalette)
QTLUA_CONSTRUCTOR_DECLARE(QPluginLoader)
QTLUA_CONSTRUCTOR_DECLARE(QProcess)
QTLUA_CONSTRUCTOR_DECLARE(QProgressBar)
QTLUA_CONSTRUCTOR_DECLARE(QProgressDialog)
QTLUA_CONSTRUCTOR_DECLARE(QPushButton)
QTLUA_CONSTRUCTOR_DECLARE(QRadioButton)
QTLUA_CONSTRUCTOR_DECLARE(QRubberBand)
QTLUA_CONSTRUCTOR_DECLARE(QScrollArea)
QTLUA_CONSTRUCTOR_DECLARE(QSettings)
QTLUA_CONSTRUCTOR_DECLARE(QShortcut)
QTLUA_CONSTRUCTOR_DECLARE(QSignalMapper)
QTLUA_CONSTRUCTOR_DECLARE(QSlider)
QTLUA_CONSTRUCTOR_DECLARE(QSpinBox)
QTLUA_CONSTRUCTOR_DECLARE(QSplashScreen)
QTLUA_CONSTRUCTOR_DECLARE(QSplitter)
QTLUA_CONSTRUCTOR_DECLARE(QStackedLayout)
QTLUA_CONSTRUCTOR_DECLARE(QStackedWidget)
QTLUA_CONSTRUCTOR_DECLARE(QStatusBar)
QTLUA_CONSTRUCTOR_DECLARE(QStringListModel)
QTLUA_CONSTRUCTOR_DECLARE(QTabBar)
QTLUA_CONSTRUCTOR_DECLARE(QTabWidget)
QTLUA_CONSTRUCTOR_DECLARE(QTableView)
QTLUA_CONSTRUCTOR_DECLARE(QTableWidget)
QTLUA_CONSTRUCTOR_DECLARE(QTemporaryFile)
QTLUA_CONSTRUCTOR_DECLARE(QTextDocument)
QTLUA_CONSTRUCTOR_DECLARE(QTextEdit)
QTLUA_CONSTRUCTOR_DECLARE(QThread)
QTLUA_CONSTRUCTOR_DECLARE(QTimeEdit)
QTLUA_CONSTRUCTOR_DECLARE(QTimer)
QTLUA_CONSTRUCTOR_DECLARE(QToolBar)
QTLUA_CONSTRUCTOR_DECLARE(QToolBox)
QTLUA_CONSTRUCTOR_DECLARE(QToolButton)
QTLUA_CONSTRUCTOR_DECLARE(QTranslator)
QTLUA_CONSTRUCTOR_DECLARE(QTreeView)
QTLUA_CONSTRUCTOR_DECLARE(QTreeWidget)
QTLUA_CONSTRUCTOR_DECLARE(QVBoxLayout)
QTLUA_CONSTRUCTOR_DECLARE(QValidator)
QTLUA_CONSTRUCTOR_DECLARE(QWidget)
QTLUA_CONSTRUCTOR_DECLARE(QWidgetAction)

#if QT_VERSION >= 0x040400
QTLUA_CONSTRUCTOR_DECLARE(QCommandLinkButton)
QTLUA_CONSTRUCTOR_DECLARE(QFormLayout)
QTLUA_CONSTRUCTOR_DECLARE(QPlainTextEdit)
QTLUA_CONSTRUCTOR_DECLARE(QStyledItemDelegate)
QTLUA_CONSTRUCTOR_DECLARE(QWindow)
#endif

QTLUA_NS_END