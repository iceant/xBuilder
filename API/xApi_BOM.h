#ifndef INCLUDED_XAPI_BOM_H
#define INCLUDED_XAPI_BOM_H

#ifndef INCLUDED_XAPI_TYPES_H
#include <xApi_Types.h>
#endif /*INCLUDED_XAPI_TYPES_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

xApi_Error_T xApi_BOM_Init(xApi_BOM_T* bom, const char* name, const char* description);

void xApi_BOM_Destroy(xApi_BOM_T* bom);

#endif /* INCLUDED_XAPI_BOM_H */
