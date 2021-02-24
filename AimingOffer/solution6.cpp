/*链表*/
#include <stdio.h>

/*定义和操作单向链表*/

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void addToTail(ListNode** pHead, int value) {
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
		*pHead = pNew;
	else {
		ListNode* pNode = *pHead;

		while (pNode->m_pNext != nullptr)
			pNode = pNew->m_pNext;

		pNew->m_pNext = pNew;
	}
}

/* 面试题5：替换空格
* 题目：实现一个函数，吧字符串每个空格替换成%20。
* 如：
* 	输入"We are happy."
*	输出"We%20are%20happy."
*/