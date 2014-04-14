#include <stdio.h>
int print(int a[][4], int n);
int swap(int &x, int &y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
	return 0;
}

int rdiag(int a[][4], int n) {
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n-i; ++ j) {
			swap(a[i][j], a[n-1-j][n-1-i]);
		}
	}
}


int diag(int a[][4], int n) {

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < i; ++ j) {
			swap(a[i][j], a[j][i]);
		}
	}
}

int trans_90(int a[][4], int n) {
	rdiag(a, n);
	for (int i = 0; i < n/2; ++ i) {
		for (int j = 0; j < n; ++ j) {
			swap(a[i][j], a[n-1-i][j]);
		}
	}

}

int trans_90_2(int a[][4], int n) {
	int b[4][4] = {};
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			swap(b[i][j], a[n-1-j][i]);
		}
	}
	print(b, 4);
}



int print(int a[][4], int n) {
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < n; ++ j) {
			printf("\t%d", a[i][j]);
		}
		printf("\n");
	}
}

int rprint(int a[][4], int n) {
	for (int i = 0; i < n/2; ++ i) {
		for (int j = i; j < n - i; ++ j) {
			printf("\t%d", a[i][j]);
		}
		for (int j = i + 1; j < n - i; ++ j ) {
			printf("\t%d", a[j][n-i-1]);
		}
		for (int j = n-i-2; j >= i; -- j) {
			printf("\t%d", a[n-1-i][j]);
		}
		for (int j = n-i-2; j > i; -- j) {
			printf("\t%d", a[j][i]);
		}
	}
	printf("\n");
}
int main(int argc, char** argv) {
	int a[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	print(a, 4);
	rprint(a, 4);
	//trans_90_2(a, 4);
	diag(a, 4);
	print(a, 4);
	return 0;

}
