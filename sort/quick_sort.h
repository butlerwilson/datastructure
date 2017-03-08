int quick_sort(int array[], int low, int high)
{
	int i = low;
	int j = high;

    //取一个参考值，小于该值的放在该值的左边，大于该值的放到该值的右边
	int tmp = array[low];

	if (low < 0 || low > N - 1 || high < 0 || high > N -1)
		return -1;
	
	if (i < j) {
		while (i < j) {
            //该值和后面的值比较，如果后面的值大于该值使下标j减1，直到后面的值小于该值停止
			while (i < j && tmp <= array[j]) --j;
            //交换两个值，然后使i加1
			if (i < j) {
                int value = array[i];
				array[i] = array[j];
                array[j] = value;
				++i;
			}
            //该值和前面的值比较，如果前面的值小于该值使下标i加1，直到前面的值大于该值停止
			while (i < j && tmp > array[i]) ++i;
            //交换两个值，然后使j减1
			if (i < j) {
                int value = array[j];
				array[j] = array[i];
                array[i] = value;
				--j;
			}
		}
        //将该值放到合适的位置
		array[i] = tmp;
        //对前一半数据递归做类似操作
		quick_sort(array, low, i -1);
        //对后一半数据递归做类似操作
		quick_sort(array, i + 1, high);
	}

	return 0;
}
