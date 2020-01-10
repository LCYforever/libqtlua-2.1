#pragma once

#ifdef qtlua_EXPORTS
	#define QTLUA_API __declspec( dllexport)
#else
	#define QTLUA_API __declspec( dllimport)
#endif
