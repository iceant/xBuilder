#ifndef INCLUDED_XAPI_AGENT_H
#define INCLUDED_XAPI_AGENT_H

#ifndef INCLUDED_XAPI_TYPES_H
#include <xApi_Types.h>
#endif /*INCLUDED_XAPI_TYPES_H*/

#ifndef INCLUDED_XAPI_OPTION_H
#include <xApi_Option.h>
#endif /*INCLUDED_XAPI_OPTION_H*/

#ifndef INCLUDED_GAI_FSM_H
#include <gai_fsm.h>
#endif /*INCLUDED_GAI_FSM_H*/

#ifndef INCLUDED_GAI_DECISIONTREE_H
#include <gai_decisiontree.h>
#endif /*INCLUDED_GAI_DECISIONTREE_H*/

#ifndef INCLUDED_GAI_BEHAVIORTREE_H
#include <gai_behaviortree.h>
#endif /*INCLUDED_GAI_BEHAVIORTREE_H*/

#ifndef INCLUDED_GAI_BLACKBOARD_H
#include <gai_blackboard.h>
#endif /*INCLUDED_GAI_BLACKBOARD_H*/


#ifndef INCLUDED_XAPI_ERRORS_H
#include <xApi_Errors.h>
#endif /*INCLUDED_XAPI_ERRORS_H*/




/* -------------------------------------------------------------------------------------------------------------- */
/*  */

typedef struct xApi_AgentAttribute_S{
    char name[xAPI_NAME_SIZE];
    char description[xAPI_DESCRIPTION_SIZE];
    char value[xAPI_OPTION_VALUE_VAL_SIZE];
    sdk_vector_t options;
}xApi_AgentAttribute_T;

typedef struct xApi_AgentAction_S{
    char name[xAPI_NAME_SIZE];
    char description[xAPI_DESCRIPTION_SIZE];
    char* lua_script_path;
}xApi_AgentAction_T;

typedef struct xApi_AgentEvaluator_S{
    char name[xAPI_NAME_SIZE];
    char description[xAPI_DESCRIPTION_SIZE];
    char* lua_script_path;
}xApi_AgentEvaluator_T;

typedef struct xApi_AgentEvent_S{
    char name[xAPI_NAME_SIZE];
    char description[xAPI_DESCRIPTION_SIZE];
}xApi_AgentEvent_T;

typedef struct xApi_AgentState_S{
    char name[xAPI_NAME_SIZE];
    char description[xAPI_DESCRIPTION_SIZE];
}xApi_AgentState_T;

typedef struct xApi_AgentStateTransition_S{
    char name[xAPI_NAME_SIZE];
    char description[xAPI_DESCRIPTION_SIZE];
    char from_state_name[xAPI_NAME_SIZE];
    char to_state_name[xAPI_NAME_SIZE];
}xApi_AgentStateTransition_T;

typedef struct xApi_Agent_S{
    char name[xAPI_NAME_SIZE];
    char description[xAPI_DESCRIPTION_SIZE];
    sdk_vector_t attributes;
    sdk_vector_t actions;
    sdk_vector_t evaluators;
    sdk_vector_t events;
    sdk_vector_t states;
    sdk_vector_t transitions;
    gai_fsm_t* fsm;
    gai_decisiontree_t* decision_tree;
    gai_behaviortree_t* behavior_tree;
    gai_blackboard_t* blackboard;
}xApi_Agent_T;

/* -------------------------------------------------------------------------------------------------------------- */
/*  */
xApi_Err_T xApi_Agent_Init(xApi_Agent_T* agent, const char* name, const char* description);

void xApi_Agent_Destroy(xApi_Agent_T* agent);


#endif /* INCLUDED_XAPI_AGENT_H */
