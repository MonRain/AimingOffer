
#include <iostream>
#include <stdio.h>

#include "head.h"

//bool solution3(int arr[],int arr_len,int* ans);

using namespace std;
int main(int args, char* argv) {
	// 有效输入 应返回2或3
	int arr3[] = { 2,1,3,5,4,2 };
	int arr3_len = sizeof arr3 / sizeof(int);
	// 无效输入 空指针
	int* arrnull = nullptr;

	int* ans = nullptr;
	if (solution3ex(arr3, arr3_len, ans)) {
		cout << ans;
	}
	else {
		cout << "没有重复值\n";
	}
	
	system("pause");
	return 0;
}

