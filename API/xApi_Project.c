#include <xApi_Project.h>
#include <assert.h>
#include <xApi_Macros.h>

xApi_Err_T xApi_Project_Init(xApi_Project_T* project, char* name, char* description)
{
    assert(project);
    assert(name);
    
    size_t name_size = strlen(name);
    name_size = xAPI_MIN(name_size, xAPI_NAME_SIZE-1);
    memcpy(project->name, name, name_size);
    project->name[name_size] = '\0';
    
    if(description){
        size_t description_size = strlen(description);
        description_size = xAPI_MIN(description_size, xAPI_DESCRIPTION_SIZE-1);
        memcpy(project->description, description, description_size);
        project->description[description_size] = '\0';
    }
    
    sdk_err_t err = sdk_vector_init(&project->agents, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    return xAPI_OK;
}

void xApi_Project_Destroy(xApi_Project_T* project){
    assert(project);
    xApi_Agent_T* p;
    size_t i;
    for(i=0; i<project->agents.size; i++){
        p = sdk_vector_get(&project->agents, 0);
        sdk_vector_resize_remove(&project->agents, 0);
        xApi_Agent_Destroy(p);
    }
    sdk_vector_destroy(&project->agents);
}