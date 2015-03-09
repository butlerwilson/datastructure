#include <stdio.h>

#define N 20

int quick_sort(int array[], int low, int high)
{
	int i = low;
	int j = high;
	int tmp = array[low];

	if (low < 0 || low > N - 1 || high < 0 || high > N -1)
		return -1;
	
	if (i < j) {
		while (i < j) {
			while (i < j && tmp <= array[j]) --j;
			if (i < j) {
				array[i] = array[j];
				++i;
			}
			while (i < j && tmp > array[i]) ++i;
			if (i < j) {
				array[j] = array[i];
				--j;
			}
		}
		array[i] = tmp;
		quick_sort(array, low, i -1);
		quick_sort(array, i + 1, high);
	}

	return 0;
}

int main(int argc, char **argv)
{
	int i = 0;
	int array[N];

	for (i = 0; i < N; ++i) {
		array[i] = rand() % 99;
		printf("%d ", array[i]);
	}
	printf("\n");

	quick_sort(array, 0, N - 1);

	for (i = 0; i < N; ++i)
		printf("%d ", array[i]);

	return 0;
}
