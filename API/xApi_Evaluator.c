#include <xApi_Evaluator.h>
#include <sdk_memory.h>
#include <assert.h>
#include <sdk_str.h>

xApi_Error_T xApi_Evaluator_Init(xApi_Evaluator_T* evaluator, const char* name
                                 , sdk_bool_t (*evaluate)(void* arg), void* arg)
{
    assert(evaluator);
    evaluator->name = sdk_str_dup(name, 1, 0, 1);
    assert(evaluator->name);
    evaluator->evaluate = evaluate;
    evaluator->arg = arg;
    return xAPI_EOK;
}

void xApi_Evaluator_Destroy(xApi_Evaluator_T * evaluator){
    if(evaluator){
        SDK_FREE(evaluator->name);
    }
}

sdk_bool_t xApi_Evaluator_Evaluate(xApi_Evaluator_T* evaluator){
    evaluator->evaluate(evaluator->arg);
}
