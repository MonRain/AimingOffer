/*����*/
#include <stdio.h>

/*����Ͳ�����������*/

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

/* ������5���滻�ո�
* ��Ŀ��ʵ��һ�����������ַ���ÿ���ո��滻��%20��
* �磺
* 	����"We are happy."
*	���"We%20are%20happy."
*/