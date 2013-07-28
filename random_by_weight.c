#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//转盘算法
unsigned int rand_range(unsigned int min, unsigned int max) {
    if (min > max) {
        fprintf(stderr, "rand_range min smaller than max!");
        return 0;
    }
    if (min == max) {
        return min;
    }
    double scaled = (double) rand() / (RAND_MAX);
    return (max - min + 1) * scaled + min;
}

int rws(unsigned int* array, int len) {
    unsigned int m = 0;
    unsigned int sum = 0;
    for (int i = 0; i < len; i ++) {
        sum += array[i];
    }
//    fprintf(stderr,"sum:%d\n", sum);
    unsigned int r = rand_range(0, sum);
//    fprintf(stderr,"random_r:%d\n", r);
    for (int i = 0; i < len; i ++) {
        m = m + array[i];
        if (r <= m) return i;
    }
}
int main() {
    srand(time(NULL));
    const char *name[] = {
        "beijing",
        "shanghai",
        "shenzhen",
        "xi'an",
        "guangzhou"
    };
    unsigned int p[] = {15,8,3,6,5};
    for (int k = 0; k < 100; k ++) {
        int i = rws(p, 5);
        printf("random:%d:pos:%d\n", p[i], i);
        printf("random key:%s\n", name[i]);
    }
    return 0;
}
