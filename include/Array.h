#ifndef ANDA_ARRAY_H
#define ANDA_ARRAY_H

#include <stdbool.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include "Generator.h"

#define CREATE_NAMED_ARRAY_TYPE(type, name) GENERATE_GENERIC(type, name, char *type_str; int len; int currIndex; type* data;,   \
            void* GENERATE_GENERIC_FUNCTION_NAME_OBJECT(andaCreateNewArray, type, name) (int length) {                                                                              \
                struct GENERIC_NAME(type, name) *ptr = (struct GENERIC_NAME(type, name)*)malloc(                                \
                                                        sizeof(struct GENERIC_NAME(type, name)));                               \
                ptr->type_str = (char*)malloc(strlen(#type));                                                                   \
                sprintf(ptr->type_str, "%s", #type);                                                                            \
                ptr->len = length;                                                                                              \
                ptr->data = (type*)malloc(length * sizeof(type));                                                               \
                ptr->currIndex = 0;                                                                                             \
                return (void*)ptr;                                                                                              \
            }                                                                                                                   \
                                                                                                                                \
            void GENERATE_GENERIC_FUNCTION_NAME_OBJECT(andaDeleteArray, type, name)(void* array) {                                                  \
                assert(strcmp(andaGetArrayType(array), #type) == 0);                                                            \
                free(((struct GENERIC_NAME(type, name)*)array)->data);                                                          \
                ((struct GENERIC_NAME(type, name)*)array)->data = NULL;                                                         \
                ((struct GENERIC_NAME(type, name)*)array)->len = 0;                                                             \
                ((struct GENERIC_NAME(type, name)*)array)->currIndex = -1;                                                      \
                ((struct GENERIC_NAME(type, name)*)array)->type_str = "DELETED";                                                \
            }                                                                                                                   \
                                                                                                                                \
            type GENERATE_GENERIC_FUNCTION_NAME_OBJECT(andaGetElementArray, type, name)(void* array, int index) {                                   \
                assert(strcmp(andaGetArrayType(array), #type) == 0);                                                            \
                assert(((struct GENERIC_NAME(type, name)*)array)->currIndex >= index);                                          \
                assert(index >= 0);                                                                                             \
                assert(index < ((struct GENERIC_NAME(type, name)*)array)->len);                                                 \
                return ((struct GENERIC_NAME(type, name)*)array)->data[index];                                                  \
            }                                                                                                                   \
                                                                                                                                \
            void GENERATE_GENERIC_FUNCTION_NAME_OBJECT(andaAddElementArray, type, name)(void* array, type element) {                                \
                assert(strcmp(andaGetArrayType(array), #type) == 0);                                                            \
                assert(((struct GENERIC_NAME(type, name)*)array)->currIndex <                                                   \
                        ((struct GENERIC_NAME(type, name)*)array)->len);                                                        \
                ((struct GENERIC_NAME(type, name)*)array)->data[((struct GENERIC_NAME(type, name)*)array)->currIndex++] = element;              \
            })

#define CREATE_ARRAY_TYPE(type) CREATE_NAMED_ARRAY_TYPE(type, staticArray)

// Format:
// type  | len | currIndex | data
// char* | int | int       | type*

const char *andaGetArrayType(void *array)
{
    assert(array);
    assert(strcmp(*(char **) array, "DELETED") != 0);

    return (*(const char **) array);
}

int andaGetArrayLength(void *array)
{
    assert(array);

    char *conv = (char *) array;
    while (*(conv++) != '\0');

    return *(conv);
}

#endif //ANDA_ARRAY_H
