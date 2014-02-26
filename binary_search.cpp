#include <stdio.h>
template <typename T>
int binary_search(T *arr, int len, T x, int (*Func)(T m, T n)) {
	if (arr == NULL || len == 0) {
		return -1;
	}
    int low = 0;
	int high = len - 1;
	int mid = (high + low) / 2;
	while (low <= high) {
		mid = (high + low) / 2;
		if ((Func(arr[mid], x)) == 0) {
			return mid;
		} else if ((Func(arr[mid], x)) < 0) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

int int_compare(int x, int y) {
	if (x == y) {
		return 0;
	} else if (x > y) {
		return 1;
	} else {
		return -1;
	}
}
int main(int argc, char** argv) {
	int arr[10] = {1,3,4,5,6,8,9};
	int ret = binary_search(arr, 7, 6, int_compare);
	printf("ret = %d\n",ret);
	return 0;
}
