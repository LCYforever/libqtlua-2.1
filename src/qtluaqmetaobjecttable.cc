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

namespace QtLua {

	const meta_object_table_s meta_object_table[] = {
	  { "QtLua", &QtLua::Console::staticMetaObject,               &create_qobject<QtLua::Console> },
	  { "QtLua", &QtLua::UserItemSelectionModel::staticMetaObject,    0 },
	  { "QtLua", &QtLua::UserItemModel::staticMetaObject,	     0 },
	  { "QtLua", &QtLua::ItemViewDialog::staticMetaObject,	     0 },
	  { "QtLua", &QtLua::TableTreeModel::staticMetaObject,	     0 },
	  { "QtLua", &QtLua::TableGridModel::staticMetaObject,	     0 },
	  { "QtLua", &QtLua::LuaModel::staticMetaObject,	     0 },

	  { "QtWidgets", &QAbstractItemDelegate::staticMetaObject,	     0 },
	  { "QtCore", &QAbstractItemModel::staticMetaObject,	     0 },
	  { "QtWidgets", &QAbstractItemView::staticMetaObject,	     0 },
	  { "QtWidgets", &QAction::staticMetaObject,			     0 },
	  { "QtWidgets", &QApplication::staticMetaObject,		     0 },
	  { "QtWidgets", &QButtonGroup::staticMetaObject,		     &create_qobject<QButtonGroup> },
	  { "QtWidgets", &QCalendarWidget::staticMetaObject,		     &create_qobject<QCalendarWidget> },
	  { "QtWidgets", &QCheckBox::staticMetaObject,		     &create_qobject<QCheckBox> },
	  { "QtGui", &QClipboard::staticMetaObject,		     0 },
	  { "QtWidgets", &QColorDialog::staticMetaObject,		     &create_qobject<QColorDialog> },
	  { "QtWidgets", &QColumnView::staticMetaObject,		     &create_qobject<QColumnView> },
	  { "QtWidgets", &QComboBox::staticMetaObject,		     &create_qobject<QComboBox> },
	  { "QtCore", &QCoreApplication::staticMetaObject,	     0 },
	  { "QtWidgets", &QDateEdit::staticMetaObject,		     &create_qobject<QDateEdit> },
	  { "QtWidgets", &QDateTimeEdit::staticMetaObject,		     &create_qobject<QDateTimeEdit> },
	  { "QtWidgets", &QDesktopWidget::staticMetaObject,		     &create_qobject<QDesktopWidget> },
	  { "QtWidgets", &QDial::staticMetaObject,			     &create_qobject<QDial> },
	  { "QtWidgets", &QDialog::staticMetaObject,			     &create_qobject<QDialog> },
	  { "QtWidgets", &QDialogButtonBox::staticMetaObject,	     &create_qobject<QDialogButtonBox> },
	  { "QtWidgets", &QDockWidget::staticMetaObject,		     &create_qobject<QDockWidget> },
	  { "QtWidgets", &QDoubleSpinBox::staticMetaObject,		     &create_qobject<QDoubleSpinBox> },
	  { "QtWidgets", &QErrorMessage::staticMetaObject,		     &create_qobject<QErrorMessage> },
	  { "QtCore", &QFile::staticMetaObject,			     &create_qobject<QFile> },
	  { "QtWidgets", &QFileDialog::staticMetaObject,		     &create_qobject<QFileDialog> },
	  { "QtWidgets", &QFocusFrame::staticMetaObject,		     &create_qobject<QFocusFrame> },
	  { "QtGui", &QFont::staticMetaObject,			     0 },
	  { "QtWidgets", &QFontDialog::staticMetaObject,		     &create_qobject<QFontDialog> },
	  { "QtWidgets", &QFrame::staticMetaObject,			     &create_qobject<QFrame> },
	  { "QtWidgets", &QGraphicsScene::staticMetaObject,		     &create_qobject<QGraphicsScene> },
	  { "QtWidgets", &QGraphicsView::staticMetaObject,		     &create_qobject<QGraphicsView> },
	  { "QtWidgets", &QGridLayout::staticMetaObject,		     &create_qobject<QGridLayout> },
	  { "QtWidgets", &QGroupBox::staticMetaObject,		     &create_qobject<QGroupBox> },
	  { "QtWidgets", &QHBoxLayout::staticMetaObject,		     &create_qobject<QHBoxLayout> },
	  { "QtWidgets", &QHeaderView::staticMetaObject,		     0 },
	  { "QtWidgets", &QInputDialog::staticMetaObject,		     &create_qobject<QInputDialog> },
	  { "QtWidgets", &QItemDelegate::staticMetaObject,		     &create_qobject<QItemDelegate> },
	  { "QtWidgets", &QLCDNumber::staticMetaObject,		     &create_qobject<QLCDNumber> },
	  { "QtWidgets", &QLabel::staticMetaObject,			     &create_qobject<QLabel> },
	  { "QtWidgets", &QLayout::staticMetaObject,			     0 },
	  { "QtCore", &QLibrary::staticMetaObject,		     &create_qobject<QLibrary> },
	  { "QtWidgets", &QLineEdit::staticMetaObject,		     &create_qobject<QLineEdit> },
	  { "QtWidgets", &QListView::staticMetaObject,		     &create_qobject<QListView> },
	  { "QtWidgets", &QListWidget::staticMetaObject,		     &create_qobject<QListWidget> },
	  { "QtCore", &QLocale::staticMetaObject,			     0 },
	  { "QtWidgets", &QMainWindow::staticMetaObject,		     &create_qobject<QMainWindow> },
	  { "QtWidgets", &QMdiArea::staticMetaObject,		     &create_qobject<QMdiArea> },
	  { "QtWidgets", &QMdiSubWindow::staticMetaObject,		     &create_qobject<QMdiSubWindow> },
	  { "QtWidgets", &QMenu::staticMetaObject,			     &create_qobject<QMenu> },
	  { "QtWidgets", &QMenuBar::staticMetaObject,		     &create_qobject<QMenuBar> },
	  { "QtWidgets", &QMessageBox::staticMetaObject,		     &create_qobject<QMessageBox> },
	  { "QtCore", &QObject::staticMetaObject,			     &create_qobject<QObject> },
	  { "QtGui", &QPainter::staticMetaObject,		     0 },
	  { "QtGui", &QPalette::staticMetaObject,		     0 },
	  { "QtCore", &QPluginLoader::staticMetaObject,		     &create_qobject<QPluginLoader> },
	  { "QtCore", &QProcess::staticMetaObject,		     &create_qobject<QProcess> },
	  { "QtWidgets", &QProgressBar::staticMetaObject,		     &create_qobject<QProgressBar> },
	  { "QtWidgets", &QProgressDialog::staticMetaObject,		     &create_qobject<QProgressDialog> },
	  { "QtWidgets", &QPushButton::staticMetaObject,		     &create_qobject<QPushButton> },
	  { "QtWidgets", &QRadioButton::staticMetaObject,		     &create_qobject<QRadioButton> },
	  { "QtWidgets", &QRubberBand::staticMetaObject,		     0 },
	  { "QtWidgets", &QScrollArea::staticMetaObject,		     &create_qobject<QScrollArea> },
	  { "QtCore", &QSettings::staticMetaObject,		     &create_qobject<QSettings> },
	  { "QtWidgets", &QShortcut::staticMetaObject,		     0 },
	  { "QtCore", &QSignalMapper::staticMetaObject,		     &create_qobject<QSignalMapper> },
	  { "QtWidgets", &QSlider::staticMetaObject,			     &create_qobject<QSlider> },
	  { "QtWidgets", &QSpinBox::staticMetaObject,		     &create_qobject<QSpinBox> },
	  { "QtWidgets", &QSplashScreen::staticMetaObject,		     &create_qobject<QSplashScreen> },
	  { "QtWidgets", &QSplitter::staticMetaObject,		     &create_qobject<QSplitter> },
	  { "QtWidgets", &QStackedLayout::staticMetaObject,		     &create_qobject<QStackedLayout> },
	  { "QtWidgets", &QStackedWidget::staticMetaObject,		     &create_qobject<QStackedWidget> },
	  { "QtWidgets", &QStatusBar::staticMetaObject,		     &create_qobject<QStatusBar> },
	  { "QtCore", &QStringListModel::staticMetaObject,	     &create_qobject<QStringListModel> },
	  { "QtWidgets", &QTabBar::staticMetaObject,			     &create_qobject<QTabBar> },
	  { "QtWidgets", &QTabWidget::staticMetaObject,		     &create_qobject<QTabWidget> },
	  { "QtWidgets", &QTableView::staticMetaObject,		     &create_qobject<QTableView> },
	  { "QtWidgets", &QTableWidget::staticMetaObject,		     &create_qobject<QTableWidget> },
	  { "QtCore", &QTemporaryFile::staticMetaObject,		     &create_qobject<QTemporaryFile> },
	  { "QtGui", &QTextDocument::staticMetaObject,		     &create_qobject<QTextDocument> },
	  { "QtWidgets", &QTextEdit::staticMetaObject,		     &create_qobject<QTextEdit> },
	  { "QtCore", &QThread::staticMetaObject,			     &create_qobject<QThread> },
	  { "QtWidgets", &QTimeEdit::staticMetaObject,		     &create_qobject<QTimeEdit> },
	  { "QtCore", &QTimer::staticMetaObject,			     &create_qobject<QTimer> },
	  { "QtWidgets", &QToolBar::staticMetaObject,		     &create_qobject<QToolBar> },
	  { "QtWidgets", &QToolBox::staticMetaObject,		     &create_qobject<QToolBox> },
	  { "QtWidgets", &QToolButton::staticMetaObject,		     &create_qobject<QToolButton> },
	  { "QtCore", &QTranslator::staticMetaObject,		     &create_qobject<QTranslator> },
	  { "QtWidgets", &QTreeView::staticMetaObject,		     &create_qobject<QTreeView> },
	  { "QtWidgets", &QTreeWidget::staticMetaObject,		     &create_qobject<QTreeWidget> },
	  { "QtWidgets", &QVBoxLayout::staticMetaObject,		     &create_qobject<QVBoxLayout> },
	  { "QtGui", &QValidator::staticMetaObject,		     0 },
	  { "QtWidgets", &QWidget::staticMetaObject,			     &create_qobject<QWidget> },
	  { "QtWidgets", &QWidgetAction::staticMetaObject,                0 },

	#if QT_VERSION >= 0x040400
	  { "QtWidgets", &QCommandLinkButton::staticMetaObject,           &create_qobject<QCommandLinkButton> },
	  { "QtWidgets", &QFormLayout::staticMetaObject,		     &create_qobject<QFormLayout> },
	  { "QtWidgets", &QPlainTextEdit::staticMetaObject,		     &create_qobject<QPlainTextEdit> },
	  { "QtWidgets", &QStyledItemDelegate::staticMetaObject,          &create_qobject<QStyledItemDelegate> },
	  { "QtGui", &QWindow::staticMetaObject,          &create_qobject<QWindow> },
	#endif

	  { 0, 0 },
	};

}

