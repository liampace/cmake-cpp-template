
#ifndef MYLIBRARY_EXPORT_H
#define MYLIBRARY_EXPORT_H

#ifdef MYLIBRARY_STATIC_DEFINE
#  define MYLIBRARY_EXPORT
#  define MYLIBRARY_NO_EXPORT
#else
#  ifndef MYLIBRARY_EXPORT
#    ifdef mylibrary_EXPORTS
        /* We are building this library */
#      define MYLIBRARY_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define MYLIBRARY_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef MYLIBRARY_NO_EXPORT
#    define MYLIBRARY_NO_EXPORT 
#  endif
#endif

#ifndef MYLIBRARY_DEPRECATED
#  define MYLIBRARY_DEPRECATED __declspec(deprecated)
#endif

#ifndef MYLIBRARY_DEPRECATED_EXPORT
#  define MYLIBRARY_DEPRECATED_EXPORT MYLIBRARY_EXPORT MYLIBRARY_DEPRECATED
#endif

#ifndef MYLIBRARY_DEPRECATED_NO_EXPORT
#  define MYLIBRARY_DEPRECATED_NO_EXPORT MYLIBRARY_NO_EXPORT MYLIBRARY_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MYLIBRARY_NO_DEPRECATED
#    define MYLIBRARY_NO_DEPRECATED
#  endif
#endif

#endif /* MYLIBRARY_EXPORT_H */
