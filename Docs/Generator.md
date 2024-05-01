# Generator.h

This file is the core of the library. It provides macros for generating full generics, or if you prefer, generate
declaration, body and functions separately.

## Macros

### GENERIC_BEGIN(type, name) | Version 1.0.0

Used for declaration of only the struct of the generic.

#### Expands to

```c
struct {name}_{type} {
```

1. Where `{name}` is the name as is.
2. Where `{type}` is the type as is.

#### Usage

So if you want to create a generic named `Box` of type `int`, you should use:

```c
GENERIC_BEGIN(int, Box) GENERIC_END;
``` 

This will expand to:

```c
struct Box_int {};
```

### GENERIC_BEGIN | Version 1.0.0

Used for finishing the declaration of the generic.

#### Expands to

```c
}
```

### GENERATE_GENERIC(type, name, members, functions) | Version 1.0.0

Used for comprehensive declaration of a generic. Where you can specify the members and functions that generic will have.

#### Expands to

```c
GENERATE_BEGIN(type, name) members GENERIC_END; functions
```

1. Where `{name}` is the name as is.
2. Where `{type}` is the type as is.
3. Where `{members}` is the members as is.
4. Where `{functions}` is the functions as is.

#### Usage

So if you want to create a generic named `Box` of type `int`, that has a member and a function that returns the type as
a string, you should use:

```c
GENERATE_GENERIC(int, Box, int aVariable, const char* GENERATE_GENERIC_FUNCTION_NAME_OBJECT(ToString, int, Box)() { return "int"; })
``` 

1. If you pass the name of the function `ToString` as is, the first generic will generate, but the second would try to
   generate a function with the same signature and if in the same translation unit, they will clash and the program
   **will not** compile. This is why *it is recommended* to
   use [GENERATE_GENERIC_FUNCTION_NAME_OBJECT](#generate_generic_function_name_objectfuncname-type-name--version-100)

### GENERATE_GENERIC_NO_FUNCTIONS(type, name, members) | Version 1.0.0

Same as [GENERATE_GENERIC](#generate_generictype-name-members-functions--version-100), however no functions can be
passed to be generated with it.

### GENERATE_GENERIC_FUNCTION_NAME_OBJECT(funcName, type, name) | Version 1.0.0

Used for name generation of functions of a generic type.

#### Expands to

```c
{funcName}_{name}_{type}
```

1. Where `{funcName}` is the members as is.
2. Where `{name}` is the name as is.
3. Where `{type}` is the type as is.

#### Usage

```c
GENERATE_GENERIC_FUNCTION_NAME_OBJECT(ToString, Box, int)
```

### GENERATE_GENERIC_FUNCTION_NAME_STANDALONE(funcName, type) | Version 1.0.0

Used for name generation of generic function. This **should only** be used when you create a generic function that is *
*not** tied to a generic object.

Example:

```c++
template<class T>
T Max<T>(T a, T b) { return a > b ? a : b; }  
```

#### Expands to

```c
{funcName}_{type}
```

1. Where `{funcName}` is the members as is.
2. Where `{type}` is the type as is.

#### Usage

```c
GENERATE_GENERIC_FUNCTION_NAME_STANDALONE(Max, int)
```

### GENERATE_GENERIC_FUNCTION_OBJECT(funcName, type, genericName, returnType, args, body) | Version 1.0.0

This is an all-in-one macro for generic function of a generic object declaration.

#### Expands to

```c
{returnType} GENERATE_GENERIC_FUNCTION_NAME_OBJECT(funcName, type, genericName) ({args}) { {body} }
```

1. Where `{genericName}` is the name of the generic type as is.
2. Where `{type}` is the type as is.
3. Where `{funcName}` is the name of the function as is.
4. Where `{body}` is the code of the body as is.
5. Where `{returnType}` is the return type as is.
6. Where `{args}` is the function arguments as is. ***This must be surrounded with `(` and `)`.***

#### Usage

```c
GENERATE_GENERIC_FUNCTION_OBJECT(ToString, Box, int, const char*, (void), return "int"; )
```

### GENERATE_GENERIC_FUNCTION_STANDALONE(funcName, type, returnType, args, body) | Version 1.0.0

This is an all-in-one macro for generic function declaration.

#### Expands to

```c
{returnType} GENERATE_GENERIC_FUNCTION_NAME_STANDALONE(funcName, type) {args} { {body} }
```

1. Where `{type}` is the type as is.
2. Where `{funcName}` is the name of the function as is.
3. Where `{body}` is the code of the body as is.
4. Where `{returnType}` is the return type as is.
5. Where `{args}` is the function arguments as is. ***This must be surrounded with `(` and `)`.***

#### Usage

```c
GENERATE_GENERIC_FUNCTION_STANDALONE(Max, int, int, (int a, int b), return "int"; )
```

### GENERIC_NAME(type, name) | Version 1.0.0

This is a macro for generating an internal name for a generic type. It *shouldn't* be used.

#### Expands to

```c
{name}_{type}
```

1. Where `{name}` is the name as is.
2. Where `{type}` is the type as is.

#### Usage

```c
GENERIC_NAME(int, Box)
```