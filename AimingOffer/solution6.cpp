/*链表*/
#include <stdio.h>
#include "head.h"
#include <stack>

/*定义和操作单向链表*/


void addToTail(ListNode** pHead, int value) {
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
		*pHead = pNew;
	else {
		ListNode* pNode = *pHead;

		while (pNode->m_pNext != nullptr)
			pNode = pNode->m_pNext;

 		pNode->m_pNext = pNew;
	}
}
// 获得链表最末端的值
void getTail(ListNode** pHead,int* tail_value) {
	if (*pHead == nullptr) {
		*tail_value = NULL;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr) {
			pNode = pNode->m_pNext;
		}
		*tail_value = pNode->m_nValue;
	}
}
// 正向打印链表
void printList(ListNode** pHead) {
	if (*pHead == nullptr) {
		printf("\n");
		return;
	}

	ListNode* pNode = *pHead;
	printf("<- begin ->");
	while (pNode != nullptr) {
		printf("%d,",pNode->m_nValue);
		pNode = pNode->m_pNext;
	}

	printf("\b<- end ->\n");
}
// 找到第一个等于某个值的节点并删除
void findDelNode(ListNode** pHead,int value) {
	if (*pHead == nullptr) {
		return;
	}


	ListNode* pNodeToBeDel = nullptr;
	if ((*pHead)->m_nValue == value) {
		pNodeToBeDel = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else {
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value) {
			pNodeToBeDel = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pNodeToBeDel != nullptr) {
		delete pNodeToBeDel;
		pNodeToBeDel = nullptr;
	}

}

// 删除某个节点


// 从尾到头打印链表
void printListRev(ListNode** pHead) {
	// 两种思路：
	// 1. 使用std::stack栈——后进先出
	printListRevStack(pHead);
	// 2. 溯源本质——递归
	printListRevRecursively(pHead);
}

void printListRevStack(ListNode** pHead) {
	if (*pHead == nullptr || pHead == nullptr)
		return;
	
	std::stack<int> nodes;

	ListNode* pNode = *pHead;
	while (pNode != nullptr) {
		nodes.push(pNode->m_nValue);
		pNode = pNode->m_pNext;
	}
	printf("<- begin ->");
	while (nodes.empty() == false) {
		printf("%d,", nodes.top());
		nodes.pop();
	}

	printf("\b<-- end -->(Reverse)\n");
}

void printListRevRecursively(ListNode** pHead) {
	if (*pHead == nullptr)
		return;

	ListNode* pNode = *pHead;

	if (pNode->m_pNext != nullptr) {
		printListRevRecursively(&(pNode->m_pNext));
	}
	printf("%d,", pNode->m_nValue);
}	
	
/* 面试题5：替换空格
* 题目：实现一个函数，吧字符串每个空格替换成%20。
* 如：
* 	输入"We are happy."
*	输出"We%20are%20happy."
*/


/*
* 发现通用代码有bug，会漏掉最后一个  循环判断问题。
*/
