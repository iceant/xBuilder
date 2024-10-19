#ifndef INCLUDED_UITOOLKIT_TYPES_H
#define INCLUDED_UITOOLKIT_TYPES_H

#ifndef INCLUDED_STDINT_H
#define INCLUDED_STDINT_H
#include <stdint.h>
#endif /*INCLUDED_STDINT_H*/

#ifndef INCLUDED_STDDEF_H
#define INCLUDED_STDDEF_H
#include <stddef.h>
#endif /*INCLUDED_STDDEF_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

typedef struct uiPoint_S{
    size_t x;
    size_t y;
}uiPoint_T;

typedef struct uiSize_S{
    size_t width;
    size_t height;
}uiSize_T;

typedef struct uiRect_S{
    size_t top;
    size_t left;
    size_t right;
    size_t bottom;
}uiRect_T;

#endif /*INCLUDED_UITOOLKIT_TYPES_H*/
