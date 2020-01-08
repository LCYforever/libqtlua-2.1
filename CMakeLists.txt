# Copyright (C) 2007-2009 LuaDist.
# Created by Peter Kapec, modified by Alexandre Becoulet for qtlua mainstream

# Redistribution and use of this file is allowed according to the terms of the MIT license.
# For details see the COPYRIGHT file distributed with LuaDist.
# Please note that the package source code is licensed under its own license.

PROJECT(qtlua)
CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)

SET(INSTALL_BIN bin CACHE PATH "Where to install binaries to.")
SET(INSTALL_LIB lib CACHE PATH "Where to install libraries to.")
SET(INSTALL_INC include CACHE PATH "Where to install headers to.")

# Find Qt5
	# set(CMAKE_AUTOMOC ON)
	# set(CMAKE_AUTORCC ON)
	# set(CMAKE_AUTOUIC ON)

	if(CMAKE_VERSION VERSION_LESS "3.7.0")
		set(CMAKE_INCLUDE_CURRENT_DIR ON)
	endif()

	find_package(Qt5 COMPONENTS Widgets REQUIRED)
	find_package(Qt5 COMPONENTS Core REQUIRED)
	find_package(Qt5 COMPONENTS Xml REQUIRED)

# Find Lua
	FIND_PACKAGE (Lua REQUIRED)
	INCLUDE_DIRECTORIES (${LUA_INCLUDE_DIR})

###########################################################################

MESSAGE("Configure: qtlua - generating config.hh:")
INCLUDE (CheckIncludeFiles)
INCLUDE (CheckFunctionExists)
INCLUDE (CheckSymbolExists)
INCLUDE(CheckLibraryExists)

# --- avoid warnings
IF(POLICY CMP0075)
	CMAKE_POLICY(SET CMP0075 OLD)
ENDIF()

CHECK_INCLUDE_FILES (dlfcn.h HAVE_DLFCN_H)
CHECK_INCLUDE_FILES (inttypes.h HAVE_INTTYPES_H)
CHECK_INCLUDE_FILES (memory.h HAVE_MEMORY_H)
CHECK_INCLUDE_FILES (stdint.h HAVE_STDINT_H)
CHECK_INCLUDE_FILES (stdlib.h HAVE_STDLIB_H)
CHECK_INCLUDE_FILES (strings.h HAVE_STRINGS_H)
CHECK_INCLUDE_FILES (string.h HAVE_STRING_H)
CHECK_INCLUDE_FILES ("sys/stat.h" HAVE_SYS_STAT_H)
CHECK_INCLUDE_FILES ("sys/types.h" HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILES (unistd.h HAVE_UNISTD_H)

SET(CMAKE_REQUIRED_INCLUDES ${LUA_INCLUDE_DIR})
SET(CMAKE_REQUIRED_LIBRARIES ${LUA_LIBRARIES})
CHECK_FUNCTION_EXISTS(lua_gc HAVE_LUA_GC)
CHECK_FUNCTION_EXISTS(luaL_openlib HAVE_LUA_OPENLIBS)
CHECK_FUNCTION_EXISTS(luaopen_os HAVE_LUA_OSLIB)
CHECK_FUNCTION_EXISTS(luaopen_package HAVE_LUA_PACKAGELIB)
CHECK_FUNCTION_EXISTS(luaopen_jit HAVE_LUA_JITLIB)
CHECK_FUNCTION_EXISTS(luaopen_ffi HAVE_LUA_FFILIB)

CHECK_INCLUDE_FILES("stdlib.h;stdarg.h;string.h;float.h" STDC_HEADERS)
SET(SHLIBEXT ${CMAKE_SHARED_LIBRARY_SUFFIX})

# LT_OBJDIR

SET(PACKAGE_NAME "\"libqtlua\"")
SET(PACKAGE_TARNAME "\"libqtlua\"")
SET(PACKAGE_VERSION "\"2.1\"")
SET(PACKAGE_STRING "\"libqtlua 2.1\"")
SET(PACKAGE_BUGREPORT "\"\"")
SET(PACKAGE_URL "\"http://www.nongnu.org/libqtlua/\"")

# all is defined, so generate config.hh
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/config.hh.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.hh)

MESSAGE("Configure: qtlua - done.")
# end of generating config.hh file

###########################################################################

ADD_DEFINITIONS(-DHAVE_CONFIG_H)
ADD_DEFINITIONS(-DQT_NO_CAST_FROM_BYTEARRAY)
ADD_DEFINITIONS(-DQTLUAREF_DEBUG)
ADD_DEFINITIONS(-DHAVE_QT_UITOOLS)
ADD_DEFINITIONS(-DLUA_COMPAT_5_1)
ADD_DEFINITIONS(-DLUA_COMPAT_5_2)

INCLUDE_DIRECTORIES (${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES( src )

ADD_SUBDIRECTORY( src )
ADD_SUBDIRECTORY( tools )

