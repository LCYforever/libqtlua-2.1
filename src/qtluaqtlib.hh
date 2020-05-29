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

#ifndef QTLUAQTLIB_HH_
#define QTLUAQTLIB_HH_

#include <QObject>
#include <QSizePolicy>
#include <internal/QMetaObjectWrapper>
#include <QtLua/QHashProxy>
#include <qtluaconfig.hh>

namespace QtLua {

	class State;

	QTLUA_API void qtluaopen_qt(State *ls);

	/** Fake QSizePolicy class needed to expose Policy enum */
	class QTLUA_API SizePolicy
		: public QObject
	{
		Q_OBJECT;

		Q_ENUMS(Policy);
	public:
		enum Policy
		{
			Fixed = ::QSizePolicy::Fixed,
			Minimum = ::QSizePolicy::Minimum,
			Maximum = ::QSizePolicy::Maximum,
			Preferred = ::QSizePolicy::Preferred,
			Expanding = ::QSizePolicy::Expanding,
			MinimumExpanding = ::QSizePolicy::MinimumExpanding,
			Ignored = ::QSizePolicy::Ignored,
		};
	};

	typedef QMap<String, QMetaObjectWrapper > qmetaobject_table_t;
	typedef QMap<String, QModuleClassWrapper > qmoduleclass_table_t;

	class QTLUA_API QMetaObjectTable
		: public QHashProxyRo<qmetaobject_table_t>
		, public QObject
	{
	public:
		QMetaObjectTable()
			: QHashProxyRo<qmetaobject_table_t>(_mo_table)
		{
			for (const meta_object_table_s *me = meta_object_table; me->_mo; me++)
			{
				String name(me->_mo->className());
				name.replace("QtLua::", "");
				_mo_table.insert(name, QMetaObjectWrapper(me->_mo, me->_creator));
			}
		}

		QMetaObjectWrapper::ptr findMetaObjWrapper(String name)
		{
			QMetaObjectWrapper::ptr _mow;
			qmetaobject_table_t::Iterator iter = _mo_table.find(name);
			
			if (iter != _mo_table.end())
				_mow = iter.value();

			return _mow;
		}

		static QMetaObjectTable& Instance();

	public:
		qmetaobject_table_t _mo_table;
	};

	class QTLUA_API QModuleObject
		: public QHashProxyRo<qmoduleclass_table_t>
		, public QObject
	{
	public:
		QTLUA_REFTYPE(QModuleObject);

		QModuleObject()
			: QHashProxyRo<qmoduleclass_table_t>(_mo_table)
		{
		}

		QModuleObject(String name, const QModuleClassWrapper &obj)
			: QHashProxyRo<qmoduleclass_table_t>(_mo_table)
		{
			_mo_table.insert(name, obj);
		}

		inline void append(String name, const QModuleClassWrapper &obj)
		{
			_mo_table.insert(name, obj);
		}

		qmoduleclass_table_t _mo_table;
	};

	typedef QMap<String, QModuleObject::ptr> qmodule_table_t;
	class QTLUA_API QModuleTable: public QObject
	{
	public:
		QModuleTable();
		void registerQtModules(State *ls);

		static QModuleTable& Instance()
		{
			static QModuleTable _inst;
			return _inst;
		}

	public:
		qmodule_table_t _mo_table;
	};

}

#endif

