#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*爬楼梯的问题，解决重复计算，采用数据保存方法*/

int helper(int n, int *value) {
	if (value[n] != 0) {
		return value[n];
	}
	value[n] = helper(n - 1, value) + helper(n - 2, value);
	return value[n];
}

int climbStairs(int n) {
	int *value = NULL;
	int res = 0;

	value = (int *)malloc(sizeof(int)*(n + 1));
	if (value == NULL) {
		return -1;
	}

	memset(value, 0, sizeof(int)*(n + 1));
	value[0] = 0;
	value[1] = 1;
	value[2] = 2;
	res = helper(n, value);
	free(value);

	return res;
}


int main() {
	printf("building height:%d, methods:%d\n", 5, climbStairs(5));
	printf("building height:%d, methods:%d\n", 6, climbStairs(6));
	printf("building height:%d, methods:%d\n", 7, climbStairs(7));
	return 0;
}
