
#include <iostream>
#include <stdio.h>

#include "head.h"

//bool solution3(int arr[],int arr_len,int* ans);

using namespace std;
int main(int args, char* argv) {
	// ��Ч���� Ӧ����2��3
	int arr3[] = { 2,1,3,5,4,2 };
	int arr3_len = sizeof arr3 / sizeof(int);
	// ��Ч���� ��ָ��
	int* arrnull = nullptr;

	int* ans = nullptr;
	if (solution3ex(arr3, arr3_len, ans)) {
		cout << ans;
	}
	else {
		cout << "û���ظ�ֵ\n";
	}
	
	system("pause");
	return 0;
}

