
#ifndef PBRPC_EXPORT_H
#define PBRPC_EXPORT_H

#ifdef PBRPC_BUILT_AS_STATIC
#  define PBRPC_EXPORT
#  define PBRPC_NO_EXPORT
#else
#  ifndef PBRPC_EXPORT
#    ifdef pbrpc_EXPORTS
        /* We are building this library */
#      define PBRPC_EXPORT 
#    else
        /* We are using this library */
#      define PBRPC_EXPORT 
#    endif
#  endif

#  ifndef PBRPC_NO_EXPORT
#    define PBRPC_NO_EXPORT 
#  endif
#endif

#ifndef PBRPC_DEPRECATED
#  define PBRPC_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef PBRPC_DEPRECATED_EXPORT
#  define PBRPC_DEPRECATED_EXPORT PBRPC_EXPORT PBRPC_DEPRECATED
#endif

#ifndef PBRPC_DEPRECATED_NO_EXPORT
#  define PBRPC_DEPRECATED_NO_EXPORT PBRPC_NO_EXPORT PBRPC_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef PBRPC_NO_DEPRECATED
#    define PBRPC_NO_DEPRECATED
#  endif
#endif

#endif /* PBRPC_EXPORT_H */
