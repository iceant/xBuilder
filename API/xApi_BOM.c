#include <xApi_BOM.h>
#include <assert.h>
#include <sdk_str.h>
#include <sdk_memory.h>
#include <xApi_Part.h>

xApi_Error_T xApi_BOM_Init(xApi_BOM_T* bom, const char* name, const char* description){
    assert(bom);
    assert(name);
    
    bom->name = sdk_str_dup(name, 1, 0, 1);
    if(description){
        bom->description = sdk_str_dup(description, 1, 0, 1);
    }else{
        bom->description = 0;
    }
    sdk_vector_init(&bom->parts, 0);
    return xAPI_EOK;
}

void xApi_BOM_Destroy(xApi_BOM_T* bom){
    SDK_FREE(bom->name);
    SDK_FREE(bom->description);
    while(bom->parts.size){
        xApi_Part_T * part = sdk_vector_get(&bom->parts, 0);
        xApi_Part_Destroy(part);
        sdk_vector_resize_remove(&bom->parts, 0);
    }
    sdk_vector_destroy(&bom->parts);
}

