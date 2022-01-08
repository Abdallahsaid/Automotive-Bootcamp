/**********************************/
/* Author   : Abdalla Abdelhafiz  */
/* Date     : 5/1/2022            */
/* Version  : V01                 */
/**********************************/

#ifndef  STD_TYPES_H
#define STD_TYPES_H

#ifndef STD_ON
#define STD_ON 0x01U /* Standard ON */
#endif
#ifndef STD_OFF
#define STD_OFF 0x00U /* Standard OFF */
#endif
#ifndef STD_HIGH
#define STD_HIGH 0x01U /* Standard HIGH */
#endif
#ifndef STD_LOW
#define STD_LOW 0x00U /* Standard LOW */
#endif

/*
 * Boolean Values
 */
#ifndef FALSE
#define FALSE (0u)
#endif
#ifndef TRUE
#define TRUE (1u)
#endif



typedef unsigned char        bool_t;

typedef unsigned char        u8_t;       /*           0 .. 255             */
typedef signed char          s8_t;         /*        -128 .. +127            */
typedef unsigned short       u16_t;     /*           0 .. 65535           */
typedef signed short         s16_t;       /*      -32768 .. +32767          */
typedef unsigned long        u32_t;      /*           0 .. 4294967295      */
typedef signed long          s32_t;        /* -2147483648 .. +2147483647     */
typedef unsigned long long   u64_t; /*       0..18446744073709551615  */
typedef signed long long     s64_t;
typedef float                f32_t;
typedef double               f64_t;

#endif