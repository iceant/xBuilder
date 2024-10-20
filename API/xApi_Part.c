#include <xApi_Part.h>
#include <sdk_memory.h>
#include <xApi_Evaluator.h>
#include <assert.h>
#include <sdk_str.h>


xApi_Error_T xApi_Part_Init(xApi_Part_T* part, const char* id, const char* description){
    assert(part);
    assert(id);
    part->type = 0;
    part->part_id = sdk_str_dup(id, 1, 0, 1);
    assert(part->part_id);
    if(description){
        part->description = sdk_str_dup(description, 1, 0, 1);
        assert(part->description);
    }
    part->quantity = 1;
    sdk_vector_init(&part->sub_parts, 0);
    part->state = 0;
    part->enable_evaluator = 0;
    part->include_evaluator = 0;
    part->exclude_evaluator = 0;
    return xAPI_EOK;
}

void xApi_Part_Destroy(xApi_Part_T* part){
    xApi_Part_T * sub_part;
    SDK_FREE(part->part_id);
    SDK_FREE(part->description);
    while(part->sub_parts.size){
        sub_part = sdk_vector_get(&part->sub_parts, 0);
        xApi_Part_Destroy(sub_part);
        sdk_vector_resize_remove(&part->sub_parts, 0);
    }
    sdk_vector_destroy(&part->sub_parts);
    xApi_Evaluator_Destroy(part->enable_evaluator);
    xApi_Evaluator_Destroy(part->exclude_evaluator);
    xApi_Evaluator_Destroy(part->include_evaluator);
}
