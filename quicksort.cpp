#include <stdio.h>

int gg_array[10] = {11,21,31,4,13,14,42,32,6,10};
//int gg_array[10] = {1,2,3,4,5,6,7,8,9,10};
void show(int *array, int len) {
    for (int i = 0; i < len; i ++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void swap(int *array, int i, int j) {
    int tmp;
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int mid_func(int *array, int i, int j, int m) {
    if (array[i] < array[j]) {
        if (array[i] > array[m]) {
            return i;
        } else {
            if (array[m] > array[j]) {
                return j;
            } else {
                return m;
            }
        }
    } else {
        if (array[i] < array[m]) {
            return i;
        } else {
            if (array[m] > array[j]) {
                return m;
            } else {
                return j;
            }
        }

    }
}

void adjust(int *g_array, int i, int j) {
    int left = i;
    int right = j;
    int mid = (left + right) / 2;
    int mid_pos = mid_func(g_array, left,right, mid);
    if (mid_pos != left)  {
        swap(g_array, mid_pos, left);
        printf("swap, key::%d\n", g_array[left]);
    }
 
    int key = g_array[left];
    
    while (i < j) {
        while (i < j && g_array[j] >= key) j --;
        if (i < j) {
            g_array[i ++] = g_array[j];
        }
        while (i < j && g_array[i] <= key) i ++;
        if (i < j) {
            g_array[j --] = g_array[i];
        }
    }
    g_array[i] = key;

}
void quick(int *g_array, int i, int j) {
    if (i >= j) {
        return ;
    }
    adjust(g_array, i, j);
    quick(g_array, i+1, right);
    quick(g_array, left, i-1);
}
int main() {
    show(gg_array, 10);
    quick(gg_array, 0, 9);
    show(gg_array, 10);
    return 0;   
}
