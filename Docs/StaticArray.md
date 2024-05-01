# Static Array

This a generic type for representing a static array. It was created to simplify the passing around the default static
arrays in C, such as:

```c
char str1[5];
char* str2 = (char*)malloc(5);

f(str1);

...

void f(char* str) {...}
```

Where in `f` we know because it is a string that it should be null terminated. However, if the developer forgot? It will
try to look outside its bounds, thus it may access memory that isn't ours.

The Static Array generic solves that by having a `len` variable. It also keeps track of how much it is written to it, so
it doesn't run out of bounds when writing. 

## Usage

Just include `include/Array.h` and paste this:

```c
CREATE_ARRAY_TYPE(int) // This will create a static array generic of type int.

CREATE_NAMED_ARRAY_TYPE(int, myCustomStaticArrayType) // This will also create a static array generic type of type int, however the struct will have the name: `myCustomStaticArrayType`.
```

You choose which to use by following these:
* If you just want the static array generic, use `CREATE_ARRAY_TYPE`.
* If you want to be able to control the inner struct and pass it around, use `CREATE_NAMED_ARRAY_TYPE`. This is useful if you create it with custom type, ex.: string.

## Generated Functions

> Note: The `^` in these function declaration is a replacement for this: `{genericTypeName}_{selectedType}`. Example: if you invoked CREATE_ARRAY_TYPE(int), `^` will be `staticArray_int`.

### andaCreateNewArray_^(int length)

Creates a new array object of the specified type and specified length.

### andaDeleteArray_^(void* array)

Deletes a created array.

### andaGetElementArray_^(void* array, int index)

Gets an element from the array.

If `index` is < 0 or >= current index, this will fail, because you will try to get an item, that isn't yet added.

### andaAddElementArray_^(void* array, type element)

Adds an element to the array.

If the current index of the array is >= length of the array, this will fail, because you would write out of the array.

