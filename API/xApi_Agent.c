#include <xApi_Agent.h>
#include <assert.h>
#include <xApi_Macros.h>

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

xApi_Err_T xApi_Agent_Init(xApi_Agent_T* self, const char* name, const char* description)
{
    assert(self);
    assert(name);
    
    size_t name_size = strlen(name);
    name_size = xAPI_MIN(name_size, xAPI_NAME_SIZE-1);
    memcpy(self->name, name, name_size);
    self->name[name_size] = '\0';
    
    if(description){
        size_t description_size = strlen(description);
        description_size = xAPI_MIN(description_size, xAPI_DESCRIPTION_SIZE-1);
        memcpy(self->description, description, description_size);
        self->description[description_size] = '\0';
    }
    
    sdk_err_t err;
    err = sdk_vector_init(&self->actions, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    err = sdk_vector_init(&self->attributes, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    err = sdk_vector_init(&self->evaluators, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    err = sdk_vector_init(&self->events, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    err = sdk_vector_init(&self->states, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    err = sdk_vector_init(&self->transitions, 0);
    if(err!=SDK_ERR_OK){
        return xAPI_ERROR;
    }
    
    self->fsm = 0;
    self->decision_tree = 0;
    self->behavior_tree = 0;
    self->blackboard = 0;
    
    return xAPI_OK;
}

void xApi_Agent_Destroy(xApi_Agent_T* self){
    assert(self);
    
    sdk_vector_destroy(&self->attributes);
    sdk_vector_destroy(&self->actions);
    sdk_vector_destroy(&self->evaluators);
    sdk_vector_destroy(&self->events);
    sdk_vector_destroy(&self->states);
    sdk_vector_destroy(&self->transitions);
    
    if(self->fsm){
        gai_fsm_destroy(self->fsm);
        self->fsm = 0;
    }
    
    if(self->decision_tree){
        gai_decisiontree_destroy(self->decision_tree);
        self->decision_tree = 0;
    }
    
    if(self->behavior_tree){
        gai_behaviortree_destroy(self->behavior_tree);
        self->behavior_tree = 0;
    }
}