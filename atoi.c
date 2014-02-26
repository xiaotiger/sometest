#include <stdio.h>

int catoi(char *str, bool r = false) {
	int flag = 1;
	int sum;
	char *c = str;
	if (*c == '+') {
		c++;
	} else if (*c == '-') {
		flag = -1;
		c++;
	}
	while(*c++) {
		if (*c<'0' || *c > '9') {
			if (r) {
			    return -1;
			} else {
				return flag * sum;
			}
		}
		printf("in sum:%d\n", sum);
		sum = (*c-'0') + sum*10;
	}
	return flag * sum;
}

int main(int argc, char** argv) {
	char s[10] = "-1234c45";
	int d = 0;
	d = catoi(s, true);
	printf("%d\n", d);
	return 0;
}
