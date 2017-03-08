#include <stdio.h>
#include "quick_sort.h"

int main()
{
    int  i = 0;
    int array[8] = {32, 23, 1, 3, 56, 3, 67, 23};
    printf("the origin data: ");
    for (i = 0; i < 8; ++i)
        printf("%d ", array[i]);
    printf("\n");
    
    quick_sort(array, 0, 7);
    printf("after quick_sort: ");
    for (i = 0; i < 8; ++i)
        printf("%d ", array[i]);
    printf("\n");
}
