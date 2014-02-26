#include <stdio.h>
#include <stdlib.h>
/*
 * f(n) = f(n-1) + f(n-2) + ... + f(n-k)
 * f(1) = f(2) = ... =  f(k) = 1
 */

int print(int *arr, int len) {
	for (int i = 0; i < len; i ++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}
int cal_n_k(int n, int k) {
	if (n < k + 1) {
		printf("n must large than k+1\n");
		return -1;
	}
	int i = 0;
	int *arr = new int[k+1];
	for(i = 1; i <=k; ++ i) {
		arr[i] = 1;
	}
	print(arr, k+1);
	for(i = k+1; i <= n; ++ i) {
		int sum = 0;
		for (int j = 1; j < k+1; j ++) {
			sum += arr[j];
		}
		for (int m = 1; m < k; ++ m) {
			arr[m] = arr[m+1];
		}
		arr[k] = sum;
		print(arr, k+1);
		printf("sum %d\n", sum);
	}
	printf("res:%d\n",arr[k]);
	return arr[k];

}

int main(int argc, char **argv) {
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	int ret = cal_n_k(n, k);
	printf("ret %d\n", ret);
	return 0;
}
