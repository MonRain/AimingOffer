#include <iostream>
#include "head.h"

using namespace std;

int countRange(const int* numbers, int length, int min, int max);

bool solution3(int arr[], int arr_len, int* ans) {
	if (arr == nullptr || arr_len <= 0) {
		return false;
	}
	for (int i = 0; i < arr_len; i++) {
		cout << "当前数组：";
		printArr(arr, arr_len);
		cout << endl;

		if (arr[i] == i) {
			continue;
		}
		else {
			if (arr[i] == arr[arr[i]]) {
				*ans = arr[i];
				break;
			}
			else {
				int tmp = arr[i];
				arr[i] = arr[arr[i]];
				arr[tmp] = tmp;
				i--;
			}
		}
		system("pause");
	}
	if (ans == nullptr) {
		printf("\n没有重复数字");
		return false;
	}
	else {
		printf("\n重复数字为：%d", *ans);
		return true;
	}
}

/*参考答案*/
bool duplicate(int numbers[], int length, int* duplication) {
	// 判断无效输入
	if (numbers == nullptr || length <= 0) {
		return false;
	}
	for (int i = 0; i < length; ++i) {
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}

	//正文
	for (int i = 0; i < length; ++i) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[numbers[i]];
			numbers[temp] = temp;
		}
	}

	return false;

}

/*
* 反思：
* 1. 无效输入：囊括所有想得到的无效输入
*	1.1 没有意义的输入：如空指针
*	1.2 不符合题意的输入：如没有重复值，内部值不符合各种要求
* 2. 指针传递答案，不需要内部定义变量之后return
* 3. 使用bool定义函数
* 4. 元素互换时的idx变化
* 5. 合理使用各种循环，如while
* 6. 长期使用python后无法应对如此底层的操作
*/

// 后续：对比那些被pass掉的方案

// 进阶：不修改数组找出重复元素——代码错误
bool solution3ex(int numbers[], int length, int* duplication) {
	//int* dict = new int*(numbers);
	//前提：长度为n+1, 数值范围在1~n

	if (numbers == nullptr || length <= 0) {
		return false;
	}

	for (int i = 0; i < length; i++) {
		if (numbers[i]<1 || numbers[i] > length - 1){
			return false;
		}
	}


	int min = 1;
	int max = length;
	
	int l_min;
	int l_max;

	while (max > min) {
		l_min = min;
		l_max = max;
		if (countRange(numbers, length, min, max) >= max - min + 1) {
			// 发现重复
			max = ceil((max - min + 1) / 2);
		}
		else {
			min = max;
			max = l_max;
		}

		if (max == min) {
			if (countRange(numbers, length, min, max) >= 2) {
				*duplication = min;
				return true;
			}
		}
	}
	return false;
}

/*参考答案*/
// 点评：const保证不修改原数组
int getDuplication(const int* numbers, int length) {
	if (numbers == nullptr || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;

	while(end>=start)
	{
		// 点评：二进制左移1位 实现地板除
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, length, start, middle);
		
		if (end == start) {
			if (count > 1)
				return start;
			else
				break;
		}

		if (count > (middle - start + 1)) {
			end = middle;
		}
		else {
			start = middle + 1;
		}
	}
	return -1;
}
/*
* 反思：
* 1. 不修改原数组使用const保证
* 2. 移位操作实现地板除2
* 3. 二分查找实现
*/
int countRange(const int* numbers, int length, int min, int max) {
	if (numbers == nullptr || length <= 0 || max < min) {
		return false;
	}
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (min <= numbers[i] && numbers[i] <= max) {
			counter++;
		}
	}
	return counter;
}