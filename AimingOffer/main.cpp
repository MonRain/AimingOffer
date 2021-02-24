
#include <iostream>
#include <stdio.h>

#include "head.h"

//bool solution3(int arr[],int arr_len,int* ans);

using namespace std;
int main(int args, char* argv) {
	char str1[] = "hello new world!";
	char str2[] = "hello_new_world!";
	char* str11 = solution5(str1);
	char* str22 = solution5(str2);

	int i = 0;

	cout << "blank: ";
	while (str11[i] != '\0') {
		cout << str11[i];
		i++;
	}
	cout << endl;

	cout << "no blank: ";
	i = 0;
	while (str22[i] != '\0') {
		cout << str22[i];
		i++;
	}
	cout << endl;

	return 0;
}

