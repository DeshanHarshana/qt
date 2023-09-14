#ifndef ECCLIB_GLOBAL_H
#define ECCLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ECCLIB_LIBRARY)
#  define ECCLIB_EXPORT Q_DECL_EXPORT
#else
#  define ECCLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // ECCLIB_GLOBAL_H
