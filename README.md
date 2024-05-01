# Anda

A library for generation of generic types in C.

## How to use it?
It is simple. The "meat" of the library is [Generator.h](include/Generator.h). It contains macros for creating the generics.
However, the library has other built-in generic types, such as: static array, etc.

## How does it work?
For example (in built-in type), `CREATE_ARRAY_TYPE`/`CREATE_NAMED_ARRAY_TYPE` macros create a struct and functions tailored for the type specified.
For example (using the generator), `GENERIC_BEGIN` macro creates the declaration of the generic and `GENERIC_END` ends it. Everything in between is the inners of the generic struct.
There are more macros, check [Generator.h](include/Generator.h) or [Generator.md](Docs/Generator.md)
For the built-in types, check [here](Docs).

## TODO List / Feature Checklist

|       Name       |                           Description                            | Added |   Page   |
|:----------------:|:----------------------------------------------------------------:|:-----:|:--------:|
| (Static) Arrays  |                  A wrapper for a default array.                  |   ✅   | [Link]() |
| (Dynamic) Arrays |   Creates a type for representing a dynamically resized array.   |   ❌   | [Link]() |
|      Stack       | Creates a type for representing a stack with fixed/dynamic size. |   ❌   | [Link]() |
|      Queue       | Creates a type for representing a stack with fixed/dynamic size. |   ❌   | [Link]() |
