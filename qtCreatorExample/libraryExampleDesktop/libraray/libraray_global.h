#ifndef LIBRARAY_GLOBAL_H
#define LIBRARAY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBRARAY_LIBRARY)
#  define LIBRARAY_EXPORT Q_DECL_EXPORT
#else
#  define LIBRARAY_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBRARAY_GLOBAL_H
