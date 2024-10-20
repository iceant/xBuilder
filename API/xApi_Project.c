#include <xApi_Project.h>
#include <assert.h>
#include <sdk_memory.h>
#include <sdk_fmt.h>
#include <sdk_str.h>

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

xApi_Error_T xApi_Project_Init(xApi_Project_T * project, const char* name){
    sdk_err_t err = SDK_ERR_OK;
    
    assert(project);
    project->name = sdk_str_dup(name, 1, 0, 1);
    assert(project->name);
    
    err = sdk_vector_init(&project->BOMs, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    err = sdk_vector_init(&project->options, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    err = sdk_vector_init(&project->evaluators, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    return xAPI_EOK;
}
