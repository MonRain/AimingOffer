/*�ַ���*/
#include <stdio.h>

// ֪ʶ�㣺�������ڴ��д洢�ķ�ʽ
void ifSame() {
	char str1[] = "hello world";
	char str2[] = "hello world";

	const char* str3 = "hello world";
	const char* str4 = "hello world";

	if (str1 == str2)
		printf("str1 and str2 are same.\n");
	else
		printf("str1 and str2 are not same.\n");

	if (str3 == str4)
		printf("str3 and str4 are same.\n");

	else
		printf("str4 and str4 are not same.\n");
	/*
	* ���������Ϊ
	* str1 and str2 are not same.
	* str3 and str4 are same.
	* str1��str2����Ϊ�ַ������飬C��Ϊ���Ƿ����Ӧ���ȵ��ڴ�ռ�洢���Ե��ַ������ݡ�
	* ��ˣ����ߵ��ڴ��ַ��Ȼ�ǲ�һ���ġ�
	* str3��str4��const�ַ�����ָ�룬����ֻ��Ҫ��¼��Ӧ��const�ַ������ڴ��еĵ�ַ��
	* ��ˣ����Ǽ�¼ͬһ��const�ַ������ڴ��ַ��
	*/
}

/* ������5���滻�ո�
* ��Ŀ��ʵ��һ�����������ַ���ÿ���ո��滻��%20��
* �磺
* 	����"We are happy."
*	���"We%20are%20happy."	
*/

char* solution5(char str[]) {
	if (str == nullptr)
		return nullptr;


	/*
	* ����Ӧ���뵽�ģ�
	* ԭ����һ���ַ�' '���滻֮����������ַ�'%', '2', '0'��
	* ��ˣ��ַ������Ȼ�ı�
	* ���ִ��ԭ���㷨�����ܻḲ�Ǻ󷽵��ڴ�����
	* �����ִ��ԭ���㷨����ҪԤ�����㹻�ռ�
	* ��������������
	*/
	/* �����ĵ�һ������ 
	* ��η��ʺͱ����ַ����ڲ�Ԫ��
	*/
	/* 
	* ��һ���뷨���Ȳ��Ҵ��ڿո����������¼���ٴ���/��չ�㹻�ڴ桪��ʵ�����Ӷ�O(n)
	* ���ϲο���
	*/

	//��һ���£������ַ�������
	int length = 0;
	while (str[length] != '\0')
	{
		length++;  
	}
	int n_blank = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] == ' ')
			n_blank++;
	}

	int idx_end = length;// ���ﲻ��-1 ��Ϊ�˰�\0Ҳ���뵽���Ʋ����С�
	int idx_new_end = idx_end + n_blank * 2;// ÿ���һ���滻��' '�滻��'%20'����������2����λ

	//char new_str[] = new char[idx_new_end];
	while (idx_end >= 0 && idx_new_end > idx_end) {
		if (str[idx_end] != ' ') {
			str[idx_new_end--] = str[idx_end-1];
		}
		else {
			//str[idx_new_end] = '%20'; �����ᵼ�·���ת�� ����%2
			str[idx_new_end--] = '0';
			str[idx_new_end--] = '2';
			str[idx_new_end--] = '%';
		}
		idx_end--;
	}

	return str;
	//�ܽ᣺C������ �ַ�����߶���һ��'\0'������
}

// ��˼��������whileѭ��

// �����Ѿ�ʵ�֣��������ջ��������ڿ�������������л����������쳣
