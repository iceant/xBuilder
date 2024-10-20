#include <xApi_Option.h>
#include <sdk_memory.h>
#include <assert.h>
#include <sdk_str.h>


xApi_Error_T xApi_Option_Init(xApi_Option_T* option, const char* id, const char* description){
    assert(option);
    assert(id);
    option->option_id = sdk_str_dup(id, 1 ,0, 1);
    assert(option->option_id);
    if(description){
        option->description = sdk_str_dup(description, 1, 0, 1);
        assert(option->description);
    }
    option->value = 0;
    
    sdk_vector_init(&option->values, 0);
    
    return xAPI_EOK;
}

void xApi_Option_Destroy(xApi_Option_T* option){
    assert(option);
    SDK_FREE(option->option_id);
    SDK_FREE(option->description);
    SDK_FREE(option->value);
    while(option->values.size){
        xApi_OptionValue_T * p = sdk_vector_get(&option->values, 0);
        xApi_OptionValue_Destroy(p);
        sdk_vector_resize_remove(&option->values, 0);
    }
    sdk_vector_destroy(&option->values);
}

xApi_Error_T xApi_OptionValue_Init(xApi_OptionValue_T* ov, const char* name, int value){
    assert(ov);
    assert(name);
    ov->key = sdk_str_dup(name, 1, 0, 1);
    assert(ov->key);
    ov->value = value;
    return xAPI_EOK;
}

void xApi_OptionValue_Destroy(xApi_OptionValue_T* ov){
    assert(ov);
    SDK_FREE(ov->key);
}

xApi_Error_T xApi_Option_AppendValue(xApi_Option_T* option, xApi_OptionValue_T* value)
{
    assert(option);
    assert(value);
    sdk_vector_resize_append(&option->values, value);
    return xAPI_EOK;
}

xApi_Error_T xApi_Option_RemoveValue(xApi_Option_T * option, const char* value){
    assert(option);
    assert(value);
    xApi_OptionValue_T * p;
    for(sdk_size_t i=0; i<option->values.size; i++){
        p = sdk_vector_get(&option->values, i);
        if(sdk_str_cmp(p->key, 1, 0, value, 1, 0)==0){
            sdk_vector_resize_remove(&option->values, i);
            break;
        }
    }
    
    return xAPI_EOK;
}

void xApi_Option_SetValue(xApi_Option_T* option, xApi_OptionValue_T* value)
{
    assert(option);
    assert(value);
    
    option->value = sdk_str_dup(value->key, 1, 0, 1);
    
}
