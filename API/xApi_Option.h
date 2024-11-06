#ifndef INCLUDED_XAPI_OPTION_H
#define INCLUDED_XAPI_OPTION_H

#ifndef INCLUDED_XAPI_TYPES_H
#include <xApi_Types.h>
#endif /*INCLUDED_XAPI_TYPES_H*/

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

typedef struct xApi_OptionValue_S{
    char key[xAPI_OPTION_VALUE_KEY_SIZE];
    char value[xAPI_OPTION_VALUE_VAL_SIZE];
}xApi_OptionValue_T;

typedef struct xApi_Option_S{
    char name[xAPI_NAME_SIZE];
    char description[xAPI_DESCRIPTION_SIZE];
    sdk_vector_t values;
}xApi_Option_T;


#endif /* INCLUDED_XAPI_OPTION_H */
