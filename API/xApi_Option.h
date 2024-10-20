#ifndef INCLUDED_XAPI_OPTION_H
#define INCLUDED_XAPI_OPTION_H

#ifndef INCLUDED_XAPI_TYPES_H
#include <xApi_Types.h>
#endif /*INCLUDED_XAPI_TYPES_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

xApi_Error_T xApi_Option_Init(xApi_Option_T* option, const char* id, const char* description);

void xApi_Option_Destroy(xApi_Option_T* option);

xApi_Error_T xApi_OptionValue_Init(xApi_OptionValue_T* ov, const char* name, int value);

void xApi_OptionValue_Destroy(xApi_OptionValue_T* ov);

xApi_Error_T xApi_Option_AppendValue(xApi_Option_T* option, xApi_OptionValue_T* value);

void xApi_Option_SetValue(xApi_Option_T* option, xApi_OptionValue_T* value);

#endif /* INCLUDED_XAPI_OPTION_H */
