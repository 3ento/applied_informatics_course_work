
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int array[], int low, int high)
{
	int pivotValue = array[high];
	int i = low;

	for (int j = low; j < high; j++) {
		if (array[j] <= pivotValue) {
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);

	return i;
}

void qsort_recursion(int array[], int low, int high)
{
	if (low < high) {
		int pivotIdx = partition(array, low, high);
		qsort_recursion(array, low, pivotIdx-1);
		qsort_recursion(array, pivotIdx+1, high);
	}
}

void qsort_wrapper(int array[], int len)
{
	if (len == 2) {
		if (array[0] > array[1]) {
			swap(array, array+1);
			return;
		} else {
			return;
		}
	} else if (len == 1) {
		return;
	} else {
		qsort_recursion(array, 0, len);
	}
}