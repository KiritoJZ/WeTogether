#pragma once

#include <QtCore/qglobal.h>

#if defined(NETWORKLIB_STATIC)
#  define NETWORK_EXPORT
#elif defined(NETWORKLIB_BUILD)
#  define NETWORK_EXPORT Q_DECL_EXPORT
#else
#  define NETWORK_EXPORT Q_DECL_IMPORT
#endif
