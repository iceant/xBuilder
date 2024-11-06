#ifndef INCLUDED_XAPI_PROJECT_H
#define INCLUDED_XAPI_PROJECT_H

#ifndef INCLUDED_XAPI_TYPES_H
#include <xApi_Types.h>
#endif /*INCLUDED_XAPI_TYPES_H*/

#ifndef INCLUDED_XAPI_AGENT_H
#include <xApi_Agent.h>
#endif /*INCLUDED_XAPI_AGENT_H*/

#ifndef INCLUDED_XAPI_ERRORS_H
#include <xApi_Errors.h>
#endif /*INCLUDED_XAPI_ERRORS_H*/


/* -------------------------------------------------------------------------------------------------------------- */
/*  */

typedef struct xApi_Project_S{
    char name[xAPI_NAME_SIZE];
    char description[xAPI_DESCRIPTION_SIZE];
    sdk_vector_t options;
    sdk_vector_t agents;
}xApi_Project_T;

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

xApi_Err_T xApi_Project_Init(xApi_Project_T* project, char* name, char* description);

void xApi_Project_Destroy(xApi_Project_T* project);

#endif /* INCLUDED_XAPI_PROJECT_H */
