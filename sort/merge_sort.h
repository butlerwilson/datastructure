#include <stdio.h>

#define N 10

int merge_set(int tmp[], int low, int mid, int hight, int dst[]);
int merge_sort(int array[], int low, int high, int dst[]);

int merge_set(int tmp[], int low, int mid, int high, int dst[])
{
	int index = low;
	int first_index = low;
	int second_index = mid + 1;

	if (low < 0 || high > N - 1 || mid < 0 || mid > N - 1)
		return -1;

	while (first_index <= mid && second_index <= high) {
		if (tmp[first_index] > tmp[second_index]) {
			dst[index] = tmp[first_index];
			++first_index;
		} else {
			dst[index] = tmp[second_index];
			++second_index;
		}
		++index;
	}
	while (first_index <= mid) {
		dst[index] = tmp[first_index++];
		++index;
	}
	while (second_index <= high) {
		dst[index] = tmp[second_index++];
		++index;
	}

	return 0;
}

int merge_sort(int array[], int low, int high, int dst[])
{
	int tmp[N];

	if (low == high) dst[low] = array[low];
	else {
		int mid = (low + high) / 2;
		merge_sort(array, low, mid, tmp);
		merge_sort(array, mid + 1, high, tmp);
		merge_set(tmp, low, mid, high, dst);
	}

	return 0;
}
