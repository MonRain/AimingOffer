#include <stdio.h>
void printArr(int arr[], int num_arr) {
	if (arr == nullptr || num_arr <= 0)
		return;
	for (short i = 0; i < num_arr; i++)
		printf("%d,", arr[i]);
}