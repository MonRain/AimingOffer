#pragma once
#include <vector>
#include <string>
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
using namespace std;
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
struct BinTreeNode_binP
{
	BinTreeNode_binP* m_pLeft;
	BinTreeNode_binP* m_pRight;

	int m_nValue;
};
BinTreeNode_binP* reBuildBinTree(int forward[], int middle[], int length);

// solution8
struct BinTreeNode_triP {
	BinTreeNode_triP* m_pFather;
	BinTreeNode_triP* m_pLeft;
	BinTreeNode_triP* m_pRight;

	int m_nValue;
};

// utils
void printArr(int arr[], int num_arr);
vector<vector<string>> printTree(BinTreeNode_binP* root);
std::vector<int>* preOrderRecursion(BinTreeNode_binP* pHead, std::vector<int>* vec);