#include <iostream>

//stable sort
int insert_sort(int array[], int N)
{
    int forward = 0;
    int backward = forward - 1;
    int tmp = array[forward];

    for (; forward < N; ++forward) {
        tmp = array[forward];
        backward = forward - 1;
        while (backward >= 0 && tmp < array[backward]) {
            array[backward + 1] = array[backward];
            --backward;
        }
        if (backward < 0)
            array[backward + 1] = tmp;
    }
}
