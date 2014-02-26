#include <stdio.h>
#include <vector>
using namespace std;
int maxsum(int *arr, int len) {
	int max_sum = arr[0];
	int curr_sum  = 0;
    int tmp;
	vector<int> sumv;
	vector<int> extv;
	for (int i = 0; i < len; ++ i) {
		tmp = curr_sum + arr[i];
		if (tmp < 0) {
			curr_sum = 0;
			extv.clear();
			sumv.clear();
		} else {
			curr_sum = tmp;
			extv.push_back(arr[i]);
		}
		if (curr_sum > max_sum) {
			max_sum = curr_sum;
			for(int j = 0; j < extv.size(); j ++) {
				sumv.push_back(extv[j]);
			}
			extv.clear();
		} else {
		}
	}
	printf("sum_max arr:\n");
	for (vector<int>::iterator it = sumv.begin(); it != sumv.end(); ++it ) {
		printf("%d\t", *it);
	}
	printf("end\n");
	return max_sum;
}

int main(int argc, char** argv) {
	int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int sum = maxsum(a, 8);
	printf("max_sum:%d\n", sum);
	return 0;
}
