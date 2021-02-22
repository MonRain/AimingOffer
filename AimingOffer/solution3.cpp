#include <iostream>
#include "head.h"

using namespace std;

int countRange(const int* numbers, int length, int min, int max);

bool solution3(int arr[], int arr_len, int* ans) {
	if (arr == nullptr || arr_len <= 0) {
		return false;
	}
	for (int i = 0; i < arr_len; i++) {
		cout << "��ǰ���飺";
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
		printf("\nû���ظ�����");
		return false;
	}
	else {
		printf("\n�ظ�����Ϊ��%d", *ans);
		return true;
	}
}

/*�ο���*/
bool duplicate(int numbers[], int length, int* duplication) {
	// �ж���Ч����
	if (numbers == nullptr || length <= 0) {
		return false;
	}
	for (int i = 0; i < length; ++i) {
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}

	//����
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
* ��˼��
* 1. ��Ч���룺����������õ�����Ч����
*	1.1 û����������룺���ָ��
*	1.2 ��������������룺��û���ظ�ֵ���ڲ�ֵ�����ϸ���Ҫ��
* 2. ָ�봫�ݴ𰸣�����Ҫ�ڲ��������֮��return
* 3. ʹ��bool���庯��
* 4. Ԫ�ػ���ʱ��idx�仯
* 5. ����ʹ�ø���ѭ������while
* 6. ����ʹ��python���޷�Ӧ����˵ײ�Ĳ���
*/

// �������Ա���Щ��pass���ķ���

// ���ף����޸������ҳ��ظ�Ԫ�ء����������
bool solution3ex(int numbers[], int length, int* duplication) {
	//int* dict = new int*(numbers);
	//ǰ�᣺����Ϊn+1, ��ֵ��Χ��1~n

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
			// �����ظ�
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

/*�ο���*/
// ������const��֤���޸�ԭ����
int getDuplication(const int* numbers, int length) {
	if (numbers == nullptr || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;

	while(end>=start)
	{
		// ����������������1λ ʵ�ֵذ��
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
* ��˼��
* 1. ���޸�ԭ����ʹ��const��֤
* 2. ��λ����ʵ�ֵذ��2
* 3. ���ֲ���ʵ��
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