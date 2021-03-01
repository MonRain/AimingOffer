/*����*/
#include <stdio.h>
#include "head.h"
#include <stack>

/*����Ͳ�����������*/


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
// ���������ĩ�˵�ֵ
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
// �����ӡ����
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
// �ҵ���һ������ĳ��ֵ�Ľڵ㲢ɾ��
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

// ɾ��ĳ���ڵ�


// ��β��ͷ��ӡ����
void printListRev(ListNode** pHead) {
	// ����˼·��
	// 1. ʹ��std::stackջ��������ȳ�
	printListRevStack(pHead);
	// 2. ��Դ���ʡ����ݹ�
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
	
/* ������5���滻�ո�
* ��Ŀ��ʵ��һ�����������ַ���ÿ���ո��滻��%20��
* �磺
* 	����"We are happy."
*	���"We%20are%20happy."
*/


/*
* ����ͨ�ô�����bug����©�����һ��  ѭ���ж����⡣
*/
