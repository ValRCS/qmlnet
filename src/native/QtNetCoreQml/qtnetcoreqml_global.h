#ifndef QTNETCOREQML_GLOBAL_H
#define QTNETCOREQML_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTNETCOREQML_LIBRARY)
#  define QTNETCOREQMLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTNETCOREQMLSHARED_EXPORT Q_DECL_IMPORT
#endif

#define GoAddr int
#define GoTypeInfo int
#define GoTypeSpec_ int
#endif // QTNETCOREQML_GLOBAL_H