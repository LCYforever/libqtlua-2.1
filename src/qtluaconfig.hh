#pragma once

#ifdef qtlua_EXPORTS
	#define QTLUA_API __declspec( dllexport)
#else
	#define QTLUA_API __declspec( dllimport)
#endif

#define QTLUA_NS_BEGINE namespace QtLua{
#define QTLUA_NS_END }
