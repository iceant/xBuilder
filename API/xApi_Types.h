#ifndef INCLUDED_XAPI_TYPES_H
#define INCLUDED_XAPI_TYPES_H

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

#ifndef INCLUDED_SDK_TYPES_H
#include <sdk_types.h>
#endif /*INCLUDED_SDK_TYPES_H*/

#ifndef INCLUDED_SDK_VECTOR_H
#include <sdk_vector.h>
#endif /*INCLUDED_SDK_VECTOR_H*/

#ifndef INCLUDED_XAPI_ERRORS_H
#include <xApi_Errors.h>
#endif /*INCLUDED_XAPI_ERRORS_H*/


/* -------------------------------------------------------------------------------------------------------------- */
/*  */

typedef enum xApi_Type_enum{
    kXApi_Type_UNKNOWN = 0,
    kXApi_Type_CHAR = 1,
    kXApi_Type_BOOLEAN,
    kXApi_Type_INT8,
    kXApi_Type_INT16,
    kXApi_Type_INT32,
    kXApi_Type_INT64,
    kXApi_Type_UINT8,
    kXApi_Type_UINT16,
    kXApi_Type_UINT32,
    kXApi_Type_UINT64,
    kXApi_Type_FLOAT,
    kXApi_Type_DOUBLE,
    kXApi_Type_STRING,
    kXApi_Type_ENUM,
    kXApi_Type_UNION,
    kXApi_Type_STRUCT,
    kXApi_Type_ARRAY,
    kXApi_Type_VOID_P,
}xApi_Type_T;

typedef struct xApi_String_S{
    char* raw_value;
    sdk_size_t  size;
}xApi_String_T;

typedef struct xApi_Char_S{
    char raw_value;
}xApi_Char_T;

typedef struct xApi_Bool_S{
    bool raw_value;
}xApi_Bool_T;

typedef struct xApi_UInt8_S{
    uint8_t raw_value;
}xApi_UInt8_T;

typedef struct xApi_UInt16_S{
    uint16_t raw_value;
}xApi_UInt16_T;

typedef struct xApi_UInt32_S{
    uint32_t raw_value;
}xApi_UInt32_T;

typedef struct xApi_UInt64_S{
    uint64_t raw_value;
}xApi_UInt64_T;

typedef struct xApi_Int8_S{
    int8_t raw_value;
}xApi_Int8_T;

typedef struct xApi_Int16_S{
    int16_t raw_value;
}xApi_Int16_T;

typedef struct xApi_Int32_S{
    int32_t raw_value;
}xApi_Int32_T;

typedef struct xApi_Int64_S{
    int64_t raw_value;
}xApi_Int64_T;

typedef struct xApi_Float_S{
    float raw_value;
}xApi_Float_T;

typedef struct xApi_Double_S{
    double raw_value;
}xApi_Double_T;

typedef struct xApi_EnumItem_S{
    char* name;
    sdk_int_t value;
}xApi_EnumItem_T;

typedef struct xApi_Enum_S{
    char* name;
    sdk_vector_t items;
}xApi_Enum_T;

typedef struct xApi_FieldItem_S{
    char* type_name;
    char* field_name;
}xApi_FieldItem_T;

typedef struct xApi_Union_S{
    char* name;
    sdk_vector_t fields;
}xApi_Union_T;

typedef struct xApi_Struct_S{
    char* name;
    sdk_vector_t fields;
}xApi_Struct_T;

typedef struct xApi_Array_S{
    size_t size;
    sdk_vector_t items;
}xApi_Array_T;

typedef struct xApi_VoidP_S{
    void* raw_value;
}xApi_VoidP_T;
/* -------------------------------------------------------------------------------------------------------------- */
/*  */

typedef struct xApi_VariableType_S{
    xApi_Type_T type;
    char* name;
    union {
        xApi_Char_T char_value;
        xApi_Bool_T bool_value;
        xApi_Int8_T int8_value;
        xApi_Int16_T int16_value;
        xApi_Int32_T int32_value;
        xApi_Int64_T int64_value;
        xApi_UInt8_T uint8_value;
        xApi_UInt16_T uint16_value;
        xApi_UInt32_T uint32_value;
        xApi_UInt64_T uint64_value;
        xApi_Float_T float_value;
        xApi_Double_T double_value;
        xApi_String_T string_value;
        xApi_Enum_T   enum_value;
        xApi_Union_T  union_value;
        xApi_Struct_T  struct_value;
        xApi_Array_T  array_value;
        xApi_VoidP_T  voidp_value;
    } value;
}xApi_VariableType_T;

/* -------------------------------------------------------------------------------------------------------------- */
/*  */

/*
 * OptionValue like Enum key=value
 */
typedef struct xApi_OptionValue_S{
    char *      key;
    sdk_int_t   value;
}xApi_OptionValue_T;

/*
 * {
 *      option_id: "NColor",
 *      description: "Color",
 *      values:[
 *          {key:"BLACK", value=1},
 *          {key:"WHITE", value=2},
 *          {key:"GREY", value=3},
 *          {key:"PINK", value=4},
 *          {key:"WHITE_Pop_Art", value=5},
 *      ]
 * }
 */

typedef struct xApi_Option_S{
    char * option_id;
    char * description;
    char *  value;
    sdk_vector_t values; /* OptionValue[] */
}xApi_Option_T;

typedef struct xApi_Evaluator_S{
    char* name;
    sdk_bool_t (*evaluate)(void* arg);
    void* arg;
}xApi_Evaluator_T;

typedef enum xApi_Part_State_Enum{
    kxApi_Part_State_EXCLUDED = -1,
    kxApi_Part_State_ENABLED = 0,
    kxApi_Part_State_INCLUDED = 1,
}xApi_Part_State_T;

typedef struct xApi_Part_S{
    int   type;
    char* part_id;
    char* description;
    sdk_size_t  quantity;
    sdk_vector_t sub_parts;
    xApi_Part_State_T   state; /* -1:excluded, 0:enable, 1:included */
    xApi_Evaluator_T* enable_evaluator;
    xApi_Evaluator_T* include_evaluator;
    xApi_Evaluator_T* exclude_evaluator;
}xApi_Part_T;

typedef struct xApi_BOM_S{
    char* name;
    char* description;
    sdk_vector_t parts;
}xApi_BOM_T;

typedef struct xApi_Project_S{
    char * name;
    sdk_vector_t BOMs;
    sdk_vector_t options;
    sdk_vector_t evaluators;
}xApi_Project_T;

#endif /*INCLUDED_XAPI_TYPES_H*/
