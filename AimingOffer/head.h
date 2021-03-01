#pragma once

//// solution1
/*
* 题目：为如下CMyString类型的生命，添加赋值运算符函数
*/
//class CMyString {
//public:
//	CMyString(char* pData = nullptr);
//	CMyString(const CMyString& str);
//	~CMyString(void);
//private:
//	char* m_pData;
//};

// solution3
bool solution3(int arr[], int arr_len, int* ans);
bool solution3ex(int arr[], int arr_len, int* ans);
bool duplicate(int numbers[], int length, int* duplication);

// solution4
bool solution4(int* arr, int col, int row, int value);

// solution5
void ifSame(); 
char* solution5(char str[]);

// solution6
// 命名习惯
//Non - public, non - static field names start with m.
//
//Static field names start with s.
//
//Other fields start with a lower case letter.
//
//Public static final fields(constants) are ALL_CAPS_WITH_UNDERSCORES.
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
void addToTail(ListNode** pHead, int value);
void getTail(ListNode**, int*);
void printList(ListNode** pHead);
void printListRevStack(ListNode**);
void printListRevRecursively(ListNode**);
void findDelNode(ListNode** pHead, int value);

// solution7
struct BinTreeNode
{
	BinTreeNode* m_pLeft;
	BinTreeNode* m_pRight;

	int m_nValue;
};
// utils
void printArr(int arr[], int num_arr);