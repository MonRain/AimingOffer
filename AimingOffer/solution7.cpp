/* 
* ���ݽṹ����
* ������
*	�������ı��� �ݹ���ѭ��  ���ֱ�����6�з���
*	���������� 
*	�� ���ѣ������ ��С�ѣ�����С��������������ֵ ������40
*	����� ������40
*/
// ���򣺶��������ѧϰ��һ�������Ǳ����������ؽ�����������>�ӱ���������������ŷ�����Ժ�������
#include <stdio.h>
#include "head.h"
#include <stack>
#include <vector>
// ��ʵ�ֶ�������3�ֱ�����6��ʵ�ַ���
// ����˼·��
// 1. �ݹ� 
// 2. ѭ��������ջ

// �ݹ鷽ʽ

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
/* ������7���ؽ�������
* ����ǰ����� ����������ؽ������������ͷ�ڵ�
* ���裺ǰ�� ��������ж��������ظ�������
*/

BinTreeNode* reBuildBinTree(int forward[], int middle[], int length) {
	if (length <= 0)
		return nullptr;

	if (length == 1)
		;
	int rootValue = forward[0];
	int idx = NULL;
	// ���Ҹ��ڵ�
	for (int i = 0; i < length; i++) {
		if (middle[i] == forward[0])
			idx = i;
	}
	// ִ�еݹ�
	if (idx != NULL) {

	}


}