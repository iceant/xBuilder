#ifndef INCLUDED_XAPI_EVALUATOR_H
#define INCLUDED_XAPI_EVALUATOR_H

#ifndef INCLUDED_XAPI_TYPES_H
#include <xApi_Types.h>
#endif /*INCLUDED_XAPI_TYPES_H*/

xApi_Error_T xApi_Evaluator_Init(xApi_Evaluator_T* evaluator, const char* name
                                 , sdk_bool_t (*evaluate)(void* arg), void* arg);

void xApi_Evaluator_Destroy(xApi_Evaluator_T * evaluator);

sdk_bool_t xApi_Evaluator_Evaluate(xApi_Evaluator_T* evaluator);

#endif /* INCLUDED_XAPI_EVALUATOR_H */
