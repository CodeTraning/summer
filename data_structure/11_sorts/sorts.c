#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b) \
do {\
	(a) ^= (b);\
	(b) ^= (a);\
	(a) ^= (b);\
} while (0)

/*冒泡排序*/
void bubble_sort(int a[], int size) {
	int i = 0;
	int j = 0;
	int swap_flg = 0;

	if (size < 1) {
		return;
	}

	for (i = size - 1; i > 0; --i) { // 排序的趟数
		swap_flg = 0; // 每次设置交换标识为true
		for (j = 0; j < i; ++j) {
			if (a[j] > a[j+1]) {
				SWAP(a[j], a[j+1]);
				swap_flg = 1;
			}
		}
		// 本趟数无数据交换的话，说明已经有序，直接退出
		if (swap_flg == 0) {
			break;
		}
	}
	return;
}

/*插入排序*/
void insert_sort(int a[], int size) {
	int i = 0;
	int j = 0;
	int key = 0;

	for (i = 1; i < size; ++i) {
		key = a[i];
		for (j = i-1; j >= 0 && a[j] > key; --j) {
			a[j+1] = a[j];
		}
		a[j+1] = key;
	}
	return;
}

/*选择排序*/
void select_sort(int a[], int size) {
	int i = 0;
	int j = 0;
	int min = 0;

	for (i = 0; i < size-1; ++i) {
		min = i;
		for (j = i+1; j < size; ++j) {
			if (a[j] < a[min]) {
				min = j;
			}
		}

		if (min != i) {
			SWAP(a[i], a[min]);
		}
	}
	return;
}

void dump(int a[], int size) {
	int i = 0;

	printf("\r\n");
	for (i = 0; i < size; ++i) {
		printf("%d ", a[i]);
	}
	printf("\r\n");
	return;
}

int main() {
	int a[10] = {9, 11, 3, 4, 15, 22, 5, 10, 44, 20};

	bubble_sort(a,sizeof(a)/sizeof(int));
    //insert_sort(a,sizeof(a)/sizeof(int));
    //select_sort(a,sizeof(a)/sizeof(int));
    
    dump(a,sizeof(a)/sizeof(int));
    return 0;
}