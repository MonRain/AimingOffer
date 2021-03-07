#include <stdio.h>
#include <vector>
#include "head.h"

//打印数组
void printArr(int arr[], int num_arr) {
	if (arr == nullptr || num_arr <= 0)
		return;
	for (short i = 0; i < num_arr; i++)
		printf("%d,", arr[i]);
}


// 遍历二叉树
// 基本思路：
// 1. 递归 
// 2. 循环：利用栈

// 递归方式
using namespace std;

std::vector<int>* preOrderRecursion(BinTreeNode_binP* pHead, std::vector<int>* vec) {

	int counter = 0;
	while (pHead != nullptr)
	{
		vec->push_back(pHead->m_nValue);
		preOrderRecursion(pHead->m_pRight, vec);
		preOrderRecursion(pHead->m_pLeft, vec);
	}

	return vec;
}
std::vector<int>* inOrderRecursion(BinTreeNode_binP* pHead, std::vector<int>* vec) {

	int counter = 0;
	while (pHead != nullptr)
	{
		preOrderRecursion(pHead->m_pRight, vec);
		vec->push_back(pHead->m_nValue);
		preOrderRecursion(pHead->m_pLeft, vec);
	}

	return vec;
}
int* postOrderRecursion(BinTreeNode_binP* pHead) {
	return nullptr;
}

int* boardOrderRecursion(BinTreeNode_binP* pHead) {
	return nullptr;
}

int* preOrderLoop(BinTreeNode_binP* pHead) {
	return nullptr;
}
int* inOrderLoop(BinTreeNode_binP* pHead) {
	return nullptr;
}
int* postOrderLoop(BinTreeNode_binP* pHead) {
	return nullptr;
}

int* boardOrderLoop(BinTreeNode_binP* pHead) {
	return nullptr;
}