//#include "Platforms_Types.h"
#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_

/* ------------------------------------------------------------ */

#define ZERO_INIT 0
/* --------------------------------- */
#ifndef FALSE
#define FALSE 0
#endif
/* --------------------------------- */
#ifndef TRUE
#define TRUE  1
#endif
/* --------------------------------- */
#define CPU_TYPE_8  8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

/* ------------------------------------------------------------ */

#define CPU_TYPE (CPU_TYPE_64)

/* ------------------------------------------------------------ */

/* -----------CPU_TYPE_64----------- */
#if (CPU_TYPE == (CPU_TYPE_64))

typedef unsigned char      uint8  ;
typedef unsigned short     uint16 ;
typedef unsigned int       uint32 ;
typedef unsigned long long uint64 ;

typedef signed char        sint8  ;
typedef signed short       sint16 ;
typedef signed int         sint32 ;
typedef signed long long   sint64 ;

typedef float              float32 ;
typedef double             float64 ;

typedef volatile uint8     vuint8_t ;
typedef volatile uint16    vuint16_t;
typedef volatile uint32    vuint32_t;
typedef volatile uint64    vuint64_t;

typedef volatile sint8     vint8_t  ;
typedef volatile sint16    vint16_t ;
typedef volatile sint32    vint32_t ;
typedef volatile sint64    vint64_t ;


/* -----------CPU_TYPE_32----------- */
#elif (CPU_TYPE == (CPU_TYPE_32))

typedef unsigned char      uint8  ;
typedef unsigned short     uint16 ;
typedef unsigned long      uint32 ;
typedef unsigned long long uint64 ;

typedef signed char        sint8  ;
typedef signed short       sint16 ;
typedef signed long        sint32 ;
typedef signed long long   sint64 ;

typedef float              float32 ;
typedef double             float64 ;

typedef volatile uint8     vuint8_t ;
typedef volatile uint16    vuint16_t;
typedef volatile uint32    vuint32_t;
typedef volatile uint64    vuint64_t;

typedef volatile sint8     vint8_t  ;
typedef volatile sint16    vint16_t ;
typedef volatile sint32    vint32_t ;
typedef volatile sint64    vint64_t ;


/* -----------CPU_TYPE_16----------- */
#elif (CPU_TYPE == (CPU_TYPE_16))

typedef unsigned char      uint8  ;
typedef unsigned short     uint16 ;
typedef unsigned long      uint32 ;
typedef unsigned long long uint64 ;

typedef signed char        sint8  ;
typedef signed short       sint16 ;
typedef signed long        sint32 ;
typedef signed long long   sint64 ;

typedef float              float32 ;
typedef double             float64 ;

typedef volatile uint8     vuint8_t ;
typedef volatile uint16    vuint16_t;
typedef volatile uint32    vuint32_t;
typedef volatile uint64    vuint64_t;

typedef volatile sint8     vint8_t  ;
typedef volatile sint16    vint16_t ;
typedef volatile sint32    vint32_t ;
typedef volatile sint64    vint64_t ;


/* ------------CPU_TYPE_8----------- */
#elif (CPU_TYPE == (CPU_TYPE_8))

typedef unsigned char      uint8  ;
typedef unsigned short     uint16 ;
typedef unsigned long      uint32 ;

typedef signed char        sint8  ;
typedef signed short       sint16 ;
typedef signed long        sint32 ;

typedef float              float32 ;

typedef volatile uint8     vuint8_t ;
typedef volatile uint16    vuint16_t;
typedef volatile uint32    vuint32_t;

typedef volatile sint8     vint8_t  ;
typedef volatile sint16    vint16_t ;
typedef volatile sint32    vint32_t ;


#endif

/* ------------------------------------------------------------ */

#endif // _PLATFORM_TYPES_H_