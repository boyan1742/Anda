#include <stdio.h>

#include "include/Array.h"

#define ARR_MAX 24

CREATE_ARRAY_TYPE(int)

int main(void)
{
    void *arr = andaCreateNewArray_staticArray_int(ARR_MAX);
    for (int i = 1; i <= ARR_MAX; ++i)
        andaAddElementArray_staticArray_int(arr, i * 2);

    printf("| ");

    for (int i = 0; i < ARR_MAX; ++i)
        printf("%d | ", andaGetElementArray_staticArray_int(arr, i));

    return 0;
}
