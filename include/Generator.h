#ifndef ANDA_GENERATOR_H
#define ANDA_GENERATOR_H

#define GENERIC_NAME(type, name) name##_##type

#define GENERATE_GENERIC_FUNCTION_NAME_OBJECT(funcName, type, name) funcName ## _ ## name ## _ ## type
#define GENERATE_GENERIC_FUNCTION_NAME_STANDALONE(funcName, type) funcName ## _ ## type

#define GENERATE_GENERIC_FUNCTION_OBJECT(funcName, type, genericName, returnType, args, body) returnType GENERATE_GENERIC_FUNCTION_NAME_OBJECT(funcName, type, genericName) (args) { body }
#define GENERATE_GENERIC_FUNCTION_STANDALONE(funcName, type, returnType, args, body) returnType GENERATE_GENERIC_FUNCTION_NAME_STANDALONE(funcName, type) (args) { body }

#define GENERIC_BEGIN(type, name) struct GENERIC_NAME(type, name) {
#define GENERIC_END }

#define GENERATE_GENERIC(type, name, members, functions) GENERIC_BEGIN(type, name) members GENERIC_END; functions
#define GENERATE_GENERIC_NO_FUNCTIONS(type, name, members) GENERIC_BEGIN(type, name) members GENERIC_END

#endif //ANDA_GENERATOR_H
