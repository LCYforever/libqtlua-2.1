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

#include <QMetaObject>
#include <internal/QMetaObjectWrapper>

#include <QtLua/Console>
#include <QtLua/UserItemSelectionModel>
#include <QtLua/UserItemModel>
#include <QtLua/ItemViewDialog>
#include <QtLua/TableTreeModel>
#include <QtLua/TableGridModel>
#include <QtLua/LuaModel>
#include <QtLua/State>

#include <QAbstractItemDelegate>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCalendarWidget>
#include <QCheckBox>
#include <QClipboard>
#include <QColorDialog>
#include <QColumnView>
#include <QComboBox>
#include <QCoreApplication>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QDesktopWidget>
#include <QDial>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDockWidget>
#include <QDoubleSpinBox>
#include <QErrorMessage>
#include <QFile>
#include <QFileDialog>
#include <QFocusFrame>
#include <QFont>
#include <QFontDialog>
#include <QFrame>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QInputDialog>
#include <QItemDelegate>
#include <QLCDNumber>
#include <QLabel>
#include <QLibrary>
#include <QLineEdit>
#include <QListView>
#include <QListWidget>
#include <QLocale>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QObject>
#include <QPainter>
#include <QPalette>
#include <QPluginLoader>
#include <QProcess>
#include <QProgressBar>
#include <QProgressDialog>
#include <QPushButton>
#include <QRadioButton>
#include <QRubberBand>
#include <QScrollArea>
#include <QSettings>
#include <QShortcut>
#include <QSignalMapper>
#include <QSlider>
#include <QSpinBox>
#include <QSplashScreen>
#include <QSplitter>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QStatusBar>
#include <QStringListModel>
#include <QTabBar>
#include <QTabWidget>
#include <QTableView>
#include <QTableWidget>
#include <QTemporaryFile>
#include <QTextDocument>
#include <QTextEdit>
#include <QThread>
#include <QTimeEdit>
#include <QTimer>
#include <QToolBar>
#include <QToolBox>
#include <QToolButton>
#include <QTranslator>
#include <QTreeView>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QValidator>
#include <QWidget>
#include <QWidgetAction>

#if QT_VERSION >= 0x040400
#include <QFormLayout>
#include <QCommandLinkButton>
#include <QPlainTextEdit>
#include <QStyledItemDelegate>
#include <QWindow>
#endif

#include "qtluaqmetaobjecttable.hh"
#include "qtluaqtlib.hh"

QTLUA_NS_BEGINE

// customized class
QTLUA_CONSTRUCTOR_IMPLEMENT(Console)
QTLUA_CONSTRUCTOR_IMPLEMENT(UserItemSelectionModel)
QTLUA_CONSTRUCTOR_IMPLEMENT(UserItemModel)
QTLUA_CONSTRUCTOR_IMPLEMENT(ItemViewDialog)
QTLUA_CONSTRUCTOR_IMPLEMENT(TableTreeModel)
QTLUA_CONSTRUCTOR_IMPLEMENT(TableGridModel)
QTLUA_CONSTRUCTOR_IMPLEMENT(LuaModel)

// qt class
QTLUA_CONSTRUCTOR_IMPLEMENT(QAbstractItemDelegate)
QTLUA_CONSTRUCTOR_IMPLEMENT(QAbstractItemModel)
QTLUA_CONSTRUCTOR_IMPLEMENT(QAbstractItemView)
QTLUA_CONSTRUCTOR_IMPLEMENT(QAction)
QTLUA_CONSTRUCTOR_IMPLEMENT(QApplication)
QTLUA_CONSTRUCTOR_IMPLEMENT(QButtonGroup)
QTLUA_CONSTRUCTOR_IMPLEMENT(QCalendarWidget)
QTLUA_CONSTRUCTOR_IMPLEMENT(QCheckBox)
QTLUA_CONSTRUCTOR_IMPLEMENT(QClipboard)
QTLUA_CONSTRUCTOR_IMPLEMENT(QColorDialog)
QTLUA_CONSTRUCTOR_IMPLEMENT(QColumnView)
QTLUA_CONSTRUCTOR_IMPLEMENT(QComboBox)
QTLUA_CONSTRUCTOR_IMPLEMENT(QCoreApplication)
QTLUA_CONSTRUCTOR_IMPLEMENT(QDateEdit)
QTLUA_CONSTRUCTOR_IMPLEMENT(QDateTimeEdit)
QTLUA_CONSTRUCTOR_IMPLEMENT(QDesktopWidget)
QTLUA_CONSTRUCTOR_IMPLEMENT(QDial)
QTLUA_CONSTRUCTOR_IMPLEMENT(QDialog)
QTLUA_CONSTRUCTOR_IMPLEMENT(QDialogButtonBox)
QTLUA_CONSTRUCTOR_IMPLEMENT(QDockWidget)
QTLUA_CONSTRUCTOR_IMPLEMENT(QDoubleSpinBox)
QTLUA_CONSTRUCTOR_IMPLEMENT(QErrorMessage)
QTLUA_CONSTRUCTOR_IMPLEMENT(QFile)
QTLUA_CONSTRUCTOR_IMPLEMENT(QFileDialog)
QTLUA_CONSTRUCTOR_IMPLEMENT(QFocusFrame)
QTLUA_CONSTRUCTOR_IMPLEMENT(QFont)
QTLUA_CONSTRUCTOR_IMPLEMENT(QFontDialog)
QTLUA_CONSTRUCTOR_IMPLEMENT(QFrame)
QTLUA_CONSTRUCTOR_IMPLEMENT(QGraphicsScene)
QTLUA_CONSTRUCTOR_IMPLEMENT(QGraphicsView)
QTLUA_CONSTRUCTOR_IMPLEMENT(QGridLayout)
QTLUA_CONSTRUCTOR_IMPLEMENT(QGroupBox)
QTLUA_CONSTRUCTOR_IMPLEMENT(QHBoxLayout)
QTLUA_CONSTRUCTOR_IMPLEMENT(QHeaderView)
QTLUA_CONSTRUCTOR_IMPLEMENT(QInputDialog)
QTLUA_CONSTRUCTOR_IMPLEMENT(QItemDelegate)
QTLUA_CONSTRUCTOR_IMPLEMENT(QLCDNumber)
QTLUA_CONSTRUCTOR_IMPLEMENT(QLabel)
QTLUA_CONSTRUCTOR_IMPLEMENT(QLayout)
QTLUA_CONSTRUCTOR_IMPLEMENT(QLibrary)
QTLUA_CONSTRUCTOR_IMPLEMENT(QLineEdit)
QTLUA_CONSTRUCTOR_IMPLEMENT(QListView)
QTLUA_CONSTRUCTOR_IMPLEMENT(QListWidget)
QTLUA_CONSTRUCTOR_IMPLEMENT(QLocale)
QTLUA_CONSTRUCTOR_IMPLEMENT(QMainWindow)
QTLUA_CONSTRUCTOR_IMPLEMENT(QMdiArea)
QTLUA_CONSTRUCTOR_IMPLEMENT(QMdiSubWindow)
QTLUA_CONSTRUCTOR_IMPLEMENT(QMenu)
QTLUA_CONSTRUCTOR_IMPLEMENT(QMenuBar)
QTLUA_CONSTRUCTOR_IMPLEMENT(QMessageBox)
QTLUA_CONSTRUCTOR_IMPLEMENT(QObject)
QTLUA_CONSTRUCTOR_IMPLEMENT(QPainter)
QTLUA_CONSTRUCTOR_IMPLEMENT(QPalette)
QTLUA_CONSTRUCTOR_IMPLEMENT(QPluginLoader)
QTLUA_CONSTRUCTOR_IMPLEMENT(QProcess)
QTLUA_CONSTRUCTOR_IMPLEMENT(QProgressBar)
QTLUA_CONSTRUCTOR_IMPLEMENT(QProgressDialog)
QTLUA_CONSTRUCTOR_IMPLEMENT(QPushButton)
QTLUA_CONSTRUCTOR_IMPLEMENT(QRadioButton)
QTLUA_CONSTRUCTOR_IMPLEMENT(QRubberBand)
QTLUA_CONSTRUCTOR_IMPLEMENT(QScrollArea)
QTLUA_CONSTRUCTOR_IMPLEMENT(QSettings)
QTLUA_CONSTRUCTOR_IMPLEMENT(QShortcut)
QTLUA_CONSTRUCTOR_IMPLEMENT(QSignalMapper)
QTLUA_CONSTRUCTOR_IMPLEMENT(QSlider)
QTLUA_CONSTRUCTOR_IMPLEMENT(QSpinBox)
QTLUA_CONSTRUCTOR_IMPLEMENT(QSplashScreen)
QTLUA_CONSTRUCTOR_IMPLEMENT(QSplitter)
QTLUA_CONSTRUCTOR_IMPLEMENT(QStackedLayout)
QTLUA_CONSTRUCTOR_IMPLEMENT(QStackedWidget)
QTLUA_CONSTRUCTOR_IMPLEMENT(QStatusBar)
QTLUA_CONSTRUCTOR_IMPLEMENT(QStringListModel)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTabBar)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTabWidget)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTableView)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTableWidget)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTemporaryFile)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTextDocument)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTextEdit)
QTLUA_CONSTRUCTOR_IMPLEMENT(QThread)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTimeEdit)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTimer)
QTLUA_CONSTRUCTOR_IMPLEMENT(QToolBar)
QTLUA_CONSTRUCTOR_IMPLEMENT(QToolBox)
QTLUA_CONSTRUCTOR_IMPLEMENT(QToolButton)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTranslator)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTreeView)
QTLUA_CONSTRUCTOR_IMPLEMENT(QTreeWidget)
QTLUA_CONSTRUCTOR_IMPLEMENT(QVBoxLayout)
QTLUA_CONSTRUCTOR_IMPLEMENT(QValidator)
QTLUA_CONSTRUCTOR_IMPLEMENT(QWidget)
QTLUA_CONSTRUCTOR_IMPLEMENT(QWidgetAction)

#if QT_VERSION >= 0x040400
QTLUA_CONSTRUCTOR_IMPLEMENT(QCommandLinkButton)
QTLUA_CONSTRUCTOR_IMPLEMENT(QFormLayout)
QTLUA_CONSTRUCTOR_IMPLEMENT(QPlainTextEdit)
QTLUA_CONSTRUCTOR_IMPLEMENT(QStyledItemDelegate)
QTLUA_CONSTRUCTOR_IMPLEMENT(QWindow)
#endif

const meta_object_table_s meta_object_table[] = {
  { "QtLua", &QtLua::Console::staticMetaObject, &create_qobject<QtLua::Console>, QTLUA_ALLOCATE_CONSTRUCTOR(Console)},
  { "QtLua", &QtLua::UserItemSelectionModel::staticMetaObject, 0 , QTLUA_ALLOCATE_CONSTRUCTOR(UserItemSelectionModel)},
  { "QtLua", &QtLua::UserItemModel::staticMetaObject,	     0 , QTLUA_ALLOCATE_CONSTRUCTOR(UserItemModel)},
  { "QtLua", &QtLua::ItemViewDialog::staticMetaObject,	     0 , QTLUA_ALLOCATE_CONSTRUCTOR(ItemViewDialog)},
  { "QtLua", &QtLua::TableTreeModel::staticMetaObject,	     0 , QTLUA_ALLOCATE_CONSTRUCTOR(TableTreeModel)},
  { "QtLua", &QtLua::TableGridModel::staticMetaObject,	     0 , QTLUA_ALLOCATE_CONSTRUCTOR(TableGridModel)},
  { "QtLua", &QtLua::LuaModel::staticMetaObject,	     0 , QTLUA_ALLOCATE_CONSTRUCTOR(LuaModel)},

  { "QtWidgets", &QAbstractItemDelegate::staticMetaObject,	     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QAbstractItemDelegate)},
  { "QtCore", &QAbstractItemModel::staticMetaObject,	     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QAbstractItemModel)},
  { "QtWidgets", &QAbstractItemView::staticMetaObject,	     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QAbstractItemView)},
  { "QtWidgets", &QAction::staticMetaObject,			     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QAction)},
  { "QtWidgets", &QApplication::staticMetaObject,		     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QApplication)},
  { "QtWidgets", &QButtonGroup::staticMetaObject,		     &create_qobject<QButtonGroup> , QTLUA_ALLOCATE_CONSTRUCTOR(QButtonGroup)},
  { "QtWidgets", &QCalendarWidget::staticMetaObject,		     &create_qobject<QCalendarWidget> , QTLUA_ALLOCATE_CONSTRUCTOR(QCalendarWidget)},
  { "QtWidgets", &QCheckBox::staticMetaObject,		     &create_qobject<QCheckBox> , QTLUA_ALLOCATE_CONSTRUCTOR(QCheckBox)},
  { "QtGui", &QClipboard::staticMetaObject,		     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QClipboard)},
  { "QtWidgets", &QColorDialog::staticMetaObject,		     &create_qobject<QColorDialog> , QTLUA_ALLOCATE_CONSTRUCTOR(QColorDialog)},
  { "QtWidgets", &QColumnView::staticMetaObject,		     &create_qobject<QColumnView> , QTLUA_ALLOCATE_CONSTRUCTOR(QColumnView)},
  { "QtWidgets", &QComboBox::staticMetaObject,		     &create_qobject<QComboBox> , QTLUA_ALLOCATE_CONSTRUCTOR(QComboBox)},
  { "QtCore", &QCoreApplication::staticMetaObject,	     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QCoreApplication)},
  { "QtWidgets", &QDateEdit::staticMetaObject,		     &create_qobject<QDateEdit> , QTLUA_ALLOCATE_CONSTRUCTOR(QDateEdit)},
  { "QtWidgets", &QDateTimeEdit::staticMetaObject,		     &create_qobject<QDateTimeEdit> , QTLUA_ALLOCATE_CONSTRUCTOR(QDateTimeEdit)},
  { "QtWidgets", &QDesktopWidget::staticMetaObject,		     &create_qobject<QDesktopWidget> , QTLUA_ALLOCATE_CONSTRUCTOR(QDesktopWidget)},
  { "QtWidgets", &QDial::staticMetaObject,			     &create_qobject<QDial> , QTLUA_ALLOCATE_CONSTRUCTOR(QDial)},
  { "QtWidgets", &QDialog::staticMetaObject,			     &create_qobject<QDialog> , QTLUA_ALLOCATE_CONSTRUCTOR(QDialog)},
  { "QtWidgets", &QDialogButtonBox::staticMetaObject,	     &create_qobject<QDialogButtonBox> , QTLUA_ALLOCATE_CONSTRUCTOR(QDialogButtonBox)},
  { "QtWidgets", &QDockWidget::staticMetaObject,		     &create_qobject<QDockWidget> , QTLUA_ALLOCATE_CONSTRUCTOR(QDockWidget)},
  { "QtWidgets", &QDoubleSpinBox::staticMetaObject,		     &create_qobject<QDoubleSpinBox> , QTLUA_ALLOCATE_CONSTRUCTOR(QDoubleSpinBox)},
  { "QtWidgets", &QErrorMessage::staticMetaObject,		     &create_qobject<QErrorMessage> , QTLUA_ALLOCATE_CONSTRUCTOR(QErrorMessage)},
  { "QtCore", &QFile::staticMetaObject,			     &create_qobject<QFile> , QTLUA_ALLOCATE_CONSTRUCTOR(QFile)},
  { "QtWidgets", &QFileDialog::staticMetaObject,		     &create_qobject<QFileDialog> , QTLUA_ALLOCATE_CONSTRUCTOR(QFileDialog)},
  { "QtWidgets", &QFocusFrame::staticMetaObject,		     &create_qobject<QFocusFrame> , QTLUA_ALLOCATE_CONSTRUCTOR(QFocusFrame)},
  { "QtGui", &QFont::staticMetaObject,			     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QFont)},
  { "QtWidgets", &QFontDialog::staticMetaObject,		     &create_qobject<QFontDialog> , QTLUA_ALLOCATE_CONSTRUCTOR(QFontDialog)},
  { "QtWidgets", &QFrame::staticMetaObject,			     &create_qobject<QFrame> , QTLUA_ALLOCATE_CONSTRUCTOR(QFrame)},
  { "QtWidgets", &QGraphicsScene::staticMetaObject,		     &create_qobject<QGraphicsScene> , QTLUA_ALLOCATE_CONSTRUCTOR(QGraphicsScene)},
  { "QtWidgets", &QGraphicsView::staticMetaObject,		     &create_qobject<QGraphicsView> , QTLUA_ALLOCATE_CONSTRUCTOR(QGraphicsView)},
  { "QtWidgets", &QGridLayout::staticMetaObject,		     &create_qobject<QGridLayout> , QTLUA_ALLOCATE_CONSTRUCTOR(QGridLayout)},
  { "QtWidgets", &QGroupBox::staticMetaObject,		     &create_qobject<QGroupBox> , QTLUA_ALLOCATE_CONSTRUCTOR(QGroupBox)},
  { "QtWidgets", &QHBoxLayout::staticMetaObject,		     &create_qobject<QHBoxLayout> , QTLUA_ALLOCATE_CONSTRUCTOR(QHBoxLayout)},
  { "QtWidgets", &QHeaderView::staticMetaObject,		     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QHeaderView)},
  { "QtWidgets", &QInputDialog::staticMetaObject,		     &create_qobject<QInputDialog> , QTLUA_ALLOCATE_CONSTRUCTOR(QInputDialog)},
  { "QtWidgets", &QItemDelegate::staticMetaObject,		     &create_qobject<QItemDelegate> , QTLUA_ALLOCATE_CONSTRUCTOR(QItemDelegate)},
  { "QtWidgets", &QLCDNumber::staticMetaObject,		     &create_qobject<QLCDNumber> , QTLUA_ALLOCATE_CONSTRUCTOR(QLCDNumber)},
  { "QtWidgets", &QLabel::staticMetaObject,			     &create_qobject<QLabel> , QTLUA_ALLOCATE_CONSTRUCTOR(QLabel)},
  { "QtWidgets", &QLayout::staticMetaObject,			     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QLayout)},
  { "QtCore", &QLibrary::staticMetaObject,		     &create_qobject<QLibrary> , QTLUA_ALLOCATE_CONSTRUCTOR(QLibrary)},
  { "QtWidgets", &QLineEdit::staticMetaObject,		     &create_qobject<QLineEdit> , QTLUA_ALLOCATE_CONSTRUCTOR(QLineEdit)},
  { "QtWidgets", &QListView::staticMetaObject,		     &create_qobject<QListView> , QTLUA_ALLOCATE_CONSTRUCTOR(QListView)},
  { "QtWidgets", &QListWidget::staticMetaObject,		     &create_qobject<QListWidget> , QTLUA_ALLOCATE_CONSTRUCTOR(QListWidget)},
  { "QtCore", &QLocale::staticMetaObject,			     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QLocale)},
  { "QtWidgets", &QMainWindow::staticMetaObject,		     &create_qobject<QMainWindow> , QTLUA_ALLOCATE_CONSTRUCTOR(QMainWindow)},
  { "QtWidgets", &QMdiArea::staticMetaObject,		     &create_qobject<QMdiArea> , QTLUA_ALLOCATE_CONSTRUCTOR(QMdiArea)},
  { "QtWidgets", &QMdiSubWindow::staticMetaObject,		     &create_qobject<QMdiSubWindow> , QTLUA_ALLOCATE_CONSTRUCTOR(QMdiSubWindow)},
  { "QtWidgets", &QMenu::staticMetaObject,			     &create_qobject<QMenu> , QTLUA_ALLOCATE_CONSTRUCTOR(QMenu)},
  { "QtWidgets", &QMenuBar::staticMetaObject,		     &create_qobject<QMenuBar> , QTLUA_ALLOCATE_CONSTRUCTOR(QMenuBar)},
  { "QtWidgets", &QMessageBox::staticMetaObject,		     &create_qobject<QMessageBox> , QTLUA_ALLOCATE_CONSTRUCTOR(QMessageBox)},
  { "QtCore", &QObject::staticMetaObject,			     &create_qobject<QObject> , QTLUA_ALLOCATE_CONSTRUCTOR(QObject)},
  { "QtGui", &QPainter::staticMetaObject,		     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QPainter)},
  { "QtGui", &QPalette::staticMetaObject,		     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QPalette)},
  { "QtCore", &QPluginLoader::staticMetaObject,		     &create_qobject<QPluginLoader> , QTLUA_ALLOCATE_CONSTRUCTOR(QPluginLoader)},
  { "QtCore", &QProcess::staticMetaObject,		     &create_qobject<QProcess> , QTLUA_ALLOCATE_CONSTRUCTOR(QProcess)},
  { "QtWidgets", &QProgressBar::staticMetaObject,		     &create_qobject<QProgressBar> , QTLUA_ALLOCATE_CONSTRUCTOR(QProgressBar)},
  { "QtWidgets", &QProgressDialog::staticMetaObject,		     &create_qobject<QProgressDialog> , QTLUA_ALLOCATE_CONSTRUCTOR(QProgressDialog)},
  { "QtWidgets", &QPushButton::staticMetaObject,		     &create_qobject<QPushButton> , QTLUA_ALLOCATE_CONSTRUCTOR(QPushButton)},
  { "QtWidgets", &QRadioButton::staticMetaObject,		     &create_qobject<QRadioButton> , QTLUA_ALLOCATE_CONSTRUCTOR(QRadioButton)},
  { "QtWidgets", &QRubberBand::staticMetaObject,		     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QRubberBand)},
  { "QtWidgets", &QScrollArea::staticMetaObject,		     &create_qobject<QScrollArea> , QTLUA_ALLOCATE_CONSTRUCTOR(QScrollArea)},
  { "QtCore", &QSettings::staticMetaObject,		     &create_qobject<QSettings> , QTLUA_ALLOCATE_CONSTRUCTOR(QSettings)},
  { "QtWidgets", &QShortcut::staticMetaObject,		     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QShortcut)},
  { "QtCore", &QSignalMapper::staticMetaObject,		     &create_qobject<QSignalMapper> , QTLUA_ALLOCATE_CONSTRUCTOR(QSignalMapper)},
  { "QtWidgets", &QSlider::staticMetaObject,			     &create_qobject<QSlider> , QTLUA_ALLOCATE_CONSTRUCTOR(QSlider)},
  { "QtWidgets", &QSpinBox::staticMetaObject,		     &create_qobject<QSpinBox> , QTLUA_ALLOCATE_CONSTRUCTOR(QSpinBox)},
  { "QtWidgets", &QSplashScreen::staticMetaObject,		     &create_qobject<QSplashScreen> , QTLUA_ALLOCATE_CONSTRUCTOR(QSplashScreen)},
  { "QtWidgets", &QSplitter::staticMetaObject,		     &create_qobject<QSplitter> , QTLUA_ALLOCATE_CONSTRUCTOR(QSplitter)},
  { "QtWidgets", &QStackedLayout::staticMetaObject,		     &create_qobject<QStackedLayout> , QTLUA_ALLOCATE_CONSTRUCTOR(QStackedLayout)},
  { "QtWidgets", &QStackedWidget::staticMetaObject,		     &create_qobject<QStackedWidget> , QTLUA_ALLOCATE_CONSTRUCTOR(QStackedWidget)},
  { "QtWidgets", &QStatusBar::staticMetaObject,		     &create_qobject<QStatusBar> , QTLUA_ALLOCATE_CONSTRUCTOR(QStatusBar)},
  { "QtCore", &QStringListModel::staticMetaObject,	     &create_qobject<QStringListModel> , QTLUA_ALLOCATE_CONSTRUCTOR(QStringListModel)},
  { "QtWidgets", &QTabBar::staticMetaObject,			     &create_qobject<QTabBar> , QTLUA_ALLOCATE_CONSTRUCTOR(QTabBar)},
  { "QtWidgets", &QTabWidget::staticMetaObject,		     &create_qobject<QTabWidget> , QTLUA_ALLOCATE_CONSTRUCTOR(QTabWidget)},
  { "QtWidgets", &QTableView::staticMetaObject,		     &create_qobject<QTableView> , QTLUA_ALLOCATE_CONSTRUCTOR(QTableView)},
  { "QtWidgets", &QTableWidget::staticMetaObject,		     &create_qobject<QTableWidget> , QTLUA_ALLOCATE_CONSTRUCTOR(QTableWidget)},
  { "QtCore", &QTemporaryFile::staticMetaObject,		     &create_qobject<QTemporaryFile> , QTLUA_ALLOCATE_CONSTRUCTOR(QTemporaryFile)},
  { "QtGui", &QTextDocument::staticMetaObject,		     &create_qobject<QTextDocument> , QTLUA_ALLOCATE_CONSTRUCTOR(QTextDocument)},
  { "QtWidgets", &QTextEdit::staticMetaObject,		     &create_qobject<QTextEdit> , QTLUA_ALLOCATE_CONSTRUCTOR(QTextEdit)},
  { "QtCore", &QThread::staticMetaObject,			     &create_qobject<QThread> , QTLUA_ALLOCATE_CONSTRUCTOR(QThread)},
  { "QtWidgets", &QTimeEdit::staticMetaObject,		     &create_qobject<QTimeEdit> , QTLUA_ALLOCATE_CONSTRUCTOR(QTimeEdit)},
  { "QtCore", &QTimer::staticMetaObject,			     &create_qobject<QTimer> , QTLUA_ALLOCATE_CONSTRUCTOR(QTimer)},
  { "QtWidgets", &QToolBar::staticMetaObject,		     &create_qobject<QToolBar> , QTLUA_ALLOCATE_CONSTRUCTOR(QToolBar)},
  { "QtWidgets", &QToolBox::staticMetaObject,		     &create_qobject<QToolBox> , QTLUA_ALLOCATE_CONSTRUCTOR(QToolBox)},
  { "QtWidgets", &QToolButton::staticMetaObject,		     &create_qobject<QToolButton> , QTLUA_ALLOCATE_CONSTRUCTOR(QToolButton)},
  { "QtCore", &QTranslator::staticMetaObject,		     &create_qobject<QTranslator> , QTLUA_ALLOCATE_CONSTRUCTOR(QTranslator)},
  { "QtWidgets", &QTreeView::staticMetaObject,		     &create_qobject<QTreeView> , QTLUA_ALLOCATE_CONSTRUCTOR(QTreeView)},
  { "QtWidgets", &QTreeWidget::staticMetaObject,		     &create_qobject<QTreeWidget> , QTLUA_ALLOCATE_CONSTRUCTOR(QTreeWidget)},
  { "QtWidgets", &QVBoxLayout::staticMetaObject,		     &create_qobject<QVBoxLayout> , QTLUA_ALLOCATE_CONSTRUCTOR(QVBoxLayout)},
  { "QtGui", &QValidator::staticMetaObject,		     0 , QTLUA_ALLOCATE_CONSTRUCTOR(QValidator)},
  { "QtWidgets", &QWidget::staticMetaObject,			     &create_qobject<QWidget> , QTLUA_ALLOCATE_CONSTRUCTOR(QWidget)},
  { "QtWidgets", &QWidgetAction::staticMetaObject,                0 , QTLUA_ALLOCATE_CONSTRUCTOR(QWidgetAction)},

#if QT_VERSION >= 0x040400
  { "QtWidgets", &QCommandLinkButton::staticMetaObject,           &create_qobject<QCommandLinkButton> , QTLUA_ALLOCATE_CONSTRUCTOR(QCommandLinkButton) },
  { "QtWidgets", &QFormLayout::staticMetaObject,		     &create_qobject<QFormLayout> , QTLUA_ALLOCATE_CONSTRUCTOR(QFormLayout) },
  { "QtWidgets", &QPlainTextEdit::staticMetaObject,		     &create_qobject<QPlainTextEdit> , QTLUA_ALLOCATE_CONSTRUCTOR(QPlainTextEdit) },
  { "QtWidgets", &QStyledItemDelegate::staticMetaObject,          &create_qobject<QStyledItemDelegate> , QTLUA_ALLOCATE_CONSTRUCTOR(QStyledItemDelegate) },
  { "QtGui", &QWindow::staticMetaObject,          &create_qobject<QWindow> , QTLUA_ALLOCATE_CONSTRUCTOR(QWindow) },
#endif

  { 0, 0 },
};

QTLUA_NS_END

