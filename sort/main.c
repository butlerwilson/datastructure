#include <stdio.h>
#include "insert_sort.h"

int main()
{
    int  i = 0;
    int array[8] = {32, 23, 1, 3, 56, 3, 67, 23};
    printf("the origin data: ");
    for (i = 0; i < 8; ++i)
        printf("%d ", array[i]);
    printf("\n");
    
    direct_insert_sort(array, 8);
    printf("after sort: ");
    for (i = 0; i < 8; ++i)
        printf("%d ", array[i]);
    printf("\n");
}
