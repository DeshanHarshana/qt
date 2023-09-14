#ifndef TCP_LIB_GLOBAL_H
#define TCP_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TCP_LIB_LIBRARY)
#  define TCP_LIB_EXPORT Q_DECL_EXPORT
#else
#  define TCP_LIB_EXPORT Q_DECL_IMPORT
#endif

#endif // TCP_LIB_GLOBAL_H
