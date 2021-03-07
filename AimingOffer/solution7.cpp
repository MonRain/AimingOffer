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
#include <string>
/* ������7���ؽ�������
* ����ǰ����� ����������ؽ������������ͷ�ڵ�
* ���裺ǰ�� ��������ж��������ظ�������
*/

BinTreeNode_binP* reBuildBinTree(int forward[], int middle[], int length) {
	if (length <= 0)
		return nullptr;

	BinTreeNode_binP* pHead = new BinTreeNode_binP();

	if (length == 1) {
		pHead->m_nValue = forward[0];
		pHead->m_pLeft = nullptr;
		pHead->m_pRight = nullptr;
		return pHead;
	}
		
	int root_idx;
	for (root_idx = 0; root_idx < length; root_idx++) {
		if (middle[root_idx] == forward[0])
			break;
	}

	if (middle[root_idx] == forward[0]) {
		int len_left_tree = root_idx;
		int len_right_tree = length - root_idx - 1;

		int* left_tree_inorder = new int[len_left_tree];
		int* left_tree_preorder = new int[len_left_tree];
		int* right_tree_inorder = new int[len_right_tree];
		int* right_tree_preorder = new int[len_right_tree];

		//ȷ����������
		for (int i = 0; i < length; i++) {
			if (i < root_idx)
				left_tree_inorder[i] = middle[i];
			else if (i == root_idx)
				continue;
			else if (i > root_idx)
				right_tree_inorder[i - 1 - root_idx] = middle[i];
			else
				printf("������������");
		}
		for (int i = 0; i < length; i++) {
			if (i == 0)
				continue;
			else if (i <= root_idx)
				left_tree_preorder[i - 1] = forward[i];
			else if (i > root_idx)
				right_tree_preorder[i - 1 - root_idx] = forward[i];
			else
				printf("ǰ����������");
		}
		//ִ�еݹ��ؽ���������
		pHead->m_nValue = forward[0];
		pHead->m_pLeft = reBuildBinTree(left_tree_preorder, left_tree_inorder, root_idx);
		pHead->m_pRight = reBuildBinTree(right_tree_preorder, right_tree_inorder, length - root_idx - 1);

		return pHead;
	}
	else
	{
		printf("��������");
		return nullptr;
	}


}


// ��ӡ������ ����Leetcode���
int getDepth(BinTreeNode_binP* root) {
	int mLen = -1;
	//������Ϊ-1��ֻҪ��һ����-1�����ȣ��͸�����
	if (!root) {
		return 0;
	}
	return max(mLen, max(getDepth(root->m_pLeft), getDepth(root->m_pRight))) + 1;
	//��һ����Ϊ�˼���ֵ������һ�����͵ü�һ��
}

void write(vector<vector<string>>& print, BinTreeNode_binP* root, int nodeI, int left, int right) {
	//������ȵı������Ѵ�ӡ��һֱ���ţ������ڵ�һֱ���ţ�Ȼ�����ǣ���ǰroot��������left��right����rootΪ����ʱ����
	//�Ĵ�ӡ������ҷ�Χ���Ա�ȷ����һ�����Һ��ӵ��Ǹ��м�λ�ã�
	if (!root) {
		return;
	}
	print[nodeI][(left + right) / 2] = to_string(root->m_nValue);
	//���磺0-6 �� ����2��3��Ҳ���ǵ��ĸ��������м�λ��
	//0-14�� ��0+14��/2=7���ڰ˸���Ҳ���м䣡

	//�ݹ飬�����root�����Һ�����Ϊ����ȥ��д��ӡ����������
	write(print, root->m_pLeft, nodeI + 1, left, (left + right) / 2);
	write(print, root->m_pRight, nodeI + 1, (left + right) / 2, right);

	//ע��
	//���ӵĴ�ӡ��Χ�ǣ�left ~  (left+right)/2��
	// ��4�е�����0~14Ϊ��   0 ~ (0+14)/2 ==  0 ~ 7,
	//�Һ��ӵĴ�ӡ��Χ�ǣ� (left+right+1)/2 ~ right
	// ��4�е�����0~14Ϊ��   (0+14)/2 ~ 14  ==  7 ~ 14,
}

vector<vector<string>> printTree(BinTreeNode_binP* root) {
	int row = getDepth(root);
	int col = pow(2, row) - 1;
	vector<vector<string>> print(row, vector<string>(col, ""));

	write(print, root, 0, 0, col);

	return print;
}

