#pragma once
#include <QtCore/qglobal.h>

#if defined(STORESLIB_STATIC)
#  define STORES_LOGIN_EXPORT
#elif defined(STORESLIB_BUILD)
#  define STORES_LOGIN_EXPORT Q_DECL_EXPORT
#else
#  define STORES_LOGIN_EXPORT Q_DECL_IMPORT
#endif
