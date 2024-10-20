#ifndef INCLUDED_XAPI_PART_H
#define INCLUDED_XAPI_PART_H

#ifndef INCLUDED_XAPI_TYPES_H
#include <xApi_Types.h>
#endif /*INCLUDED_XAPI_TYPES_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

xApi_Error_T xApi_Part_Init(xApi_Part_T* part, const char* id, const char* description);

void xApi_Part_Destroy(xApi_Part_T* part);

#endif /* INCLUDED_XAPI_PART_H */
