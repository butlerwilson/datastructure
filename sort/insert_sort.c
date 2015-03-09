/*

original array:
  a[] = { 23, 39, 2, 15, 67, 34 }
We depart this array into two parts, one is already sorted,and the another
part is not sort. Then we select a element from unsorted part and insert
into the sorted part properly.

we depart it as {23} and {39, 2, 15, 67, 34}.
  slecte 39, insert into {23} set. 39 > 23 ==>  {23, 39}
  ------ 2,  ----------- {23, 39}. 2 < 39 ==> {23, 2, 39}
				   23 > 2 ==> {2, 23, 39}
  ------ 15, ----------- {2, 23, 39}. 15 > 39, 15 > 23
				   15 < 2 ==>  {2, 15, 23, 39}
	..................................
  finally, we got a[] = {2, 15, 23, 34, 39, 67}
We define the last element index is i from sorted part.
It just use an array to store this elements. Everytime we select a element
from unsorted part, we compare this element with the last element sorted
part. If this element less than the last element, move the element[i] to
element[i + 1], then compare it with the element[i - 1] untill condition
is false. Then insert this elemnt into element[i].
*/

#include <stdio.h>

#define ELENUM	100

int direct_insert_sort(int array[], int num)
{
	int i = 0;
	int j = 0;
	int tmp = 0;

	//a[] = { 23, 39, 2, 15, 67, 34 }
	for (i = 0; i < num - 1; i++) {
		tmp = array[i + 1];
		j = i;
		while (j >= 0 && tmp < array[j]) {
			array[j + 1] = array[j];
			--j;
		}
		if (j < 0) array[j + 1] = tmp;
	}

	return 0;
}

int binary_search_pos(int array[], int elem, int start, int end)
{
	int i = 0;
	int mid = (start + end) / 2;

	//a[] = {2, 5, 12} <--- 13
	while (start < end) {
		if (elem > array[mid])
			start = mid + 1;
		else if (elem < array[mid])
			end = mid - 1;
		else
			return mid;
		mid = (start + end) / 2;
	}

	if (start > end && end >= 0)
		if (array[end] <= elem);
			return end;
	if (start == end)
		if (array[start] <= elem)
			return start;
		else
			return start - 1;
	return end;
}

int binary_insert_sort(int array[], int num)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int index = 0;

	for (i = 0; i < num; ++i) {
		j = i;
		tmp = array[i + 1];
		index = binary_search(array, tmp, 0, i);
		//j != i should move elements
		while ( j != i && j > index) {
				array[j + 1] = array[j];
				--j;
		}
		array[index + 1] = tmp;
	}
}

int binary_search(int array[], int low, int high, int num, int elem)
{
	int mid = (low + high) / 2;

	while (low <= high) {
		if (elem < array[mid]) high = mid - 1;
		else if (elem > array[mid]) low = mid + 1;
		else return mid;
		mid = (low + high) / 2;
	}

	return -1;
}

int main(int argc, char **argv)
{
	int i = 0;
	int array[ELENUM] = {23, 45, 2, 67, 23, 1, 89};
	int array0[ELENUM] = {1, 3, 45, 56, 67, 78, 89,90};
	for (i = 0; i < 7; i++)
		printf("%d ", array0[i]);
	printf("\n");

//	direct_insert_sort(array, 7);
//	binary_insert_sort(array, 7);
	i = binary_search(array0, 0, 7, 8, 1);
	if (i < 0) printf("Not found\n");
	else
		printf("index:%d\n", i);
	for (i = 0; i < 7; i++)
		printf("%d ", array[i]);

	return 0;
}
