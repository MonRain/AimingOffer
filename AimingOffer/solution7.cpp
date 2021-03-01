/* 
* 数据结构：树
* 二叉树
*	二叉树的遍历 递归与循环  三种遍历的6中方法
*	二叉搜索树 
*	堆 最大堆（根最大） 最小堆（根最小）——快速找最值 面试题40
*	红黑树 面试题40
*/
// 领悟：二叉树编程学习第一步并不是遍历，而是重建二叉树——>从遍历建立二叉树后才方便测试后续代码
#include <stdio.h>
#include "head.h"
#include <stack>
#include <vector>
// 先实现二叉树的3种遍历的6种实现方法
// 基本思路：
// 1. 递归 
// 2. 循环：利用栈

// 递归方式

std::vector<int>* preOrderRecursion(BinTreeNode* pHead, std::vector<int>* vec) {

	int counter = 0;
	while (pHead != nullptr)
	{
		vec->push_back(pHead->m_nValue);
		preOrderRecursion(pHead->m_pRight, vec);
		preOrderRecursion(pHead->m_pLeft, vec);
	}
	
	return vec;
}
std::vector<int>* inOrderRecursion(BinTreeNode* pHead, std::vector<int>* vec) {

	int counter = 0;
	while (pHead != nullptr)
	{
		preOrderRecursion(pHead->m_pRight, vec);
		vec->push_back(pHead->m_nValue);
		preOrderRecursion(pHead->m_pLeft, vec);
	}

	return vec;
}
int* postOrderRecursion(BinTreeNode* pHead) {

}

int* boardOrderRecursion(BinTreeNode* pHead) {

}

int* preOrderLoop(BinTreeNode* pHead) {

}
int* inOrderLoop(BinTreeNode* pHead) {

}
int* postOrderLoop(BinTreeNode* pHead) {

}

int* boardOrderLoop(BinTreeNode* pHead) {

}
/* 面试题7：重建二叉树
* 输入前序遍历 中序遍历，重建二叉树。输出头节点
* 假设：前序 中序遍历中都不包含重复的数字
*/

BinTreeNode* reBuildBinTree(int forward[], int middle[], int length) {
	if (length <= 0)
		return nullptr;

	if (length == 1)
		;
	int rootValue = forward[0];
	int idx = NULL;
	// 查找根节点
	for (int i = 0; i < length; i++) {
		if (middle[i] == forward[0])
			idx = i;
	}
	// 执行递归
	if (idx != NULL) {

	}


}