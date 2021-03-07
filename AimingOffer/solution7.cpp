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
#include <string>
/* 面试题7：重建二叉树
* 输入前序遍历 中序遍历，重建二叉树。输出头节点
* 假设：前序 中序遍历中都不包含重复的数字
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

		//确定左右子树
		for (int i = 0; i < length; i++) {
			if (i < root_idx)
				left_tree_inorder[i] = middle[i];
			else if (i == root_idx)
				continue;
			else if (i > root_idx)
				right_tree_inorder[i - 1 - root_idx] = middle[i];
			else
				printf("中序子树错误");
		}
		for (int i = 0; i < length; i++) {
			if (i == 0)
				continue;
			else if (i <= root_idx)
				left_tree_preorder[i - 1] = forward[i];
			else if (i > root_idx)
				right_tree_preorder[i - 1 - root_idx] = forward[i];
			else
				printf("前序子树错误");
		}
		//执行递归重建左右子树
		pHead->m_nValue = forward[0];
		pHead->m_pLeft = reBuildBinTree(left_tree_preorder, left_tree_inorder, root_idx);
		pHead->m_pRight = reBuildBinTree(right_tree_preorder, right_tree_inorder, length - root_idx - 1);

		return pHead;
	}
	else
	{
		printf("其它错误");
		return nullptr;
	}


}


// 打印二叉树 来自Leetcode题解
int getDepth(BinTreeNode_binP* root) {
	int mLen = -1;
	//记最深为-1，只要有一个比-1大的深度，就给他！
	if (!root) {
		return 0;
	}
	return max(mLen, max(getDepth(root->m_pLeft), getDepth(root->m_pRight))) + 1;
	//加一是因为人家有值，更进一步，就得加一！
}

void write(vector<vector<string>>& print, BinTreeNode_binP* root, int nodeI, int left, int right) {
	//深度优先的遍历，把打印表一直带着，把树节点一直带着，然后这是：当前root的行数，left和right是以root为根的时候它
	//的打印表的左右范围，以便确定下一个左右孩子的那个中间位置！
	if (!root) {
		return;
	}
	print[nodeI][(left + right) / 2] = to_string(root->m_nValue);
	//例如：0-6 ， 除了2是3，也就是第四个，就是中间位置
	//0-14， （0+14）/2=7，第八个，也是中间！

	//递归，把这个root的左右孩子作为根，去重写打印表，反正够大！
	write(print, root->m_pLeft, nodeI + 1, left, (left + right) / 2);
	write(print, root->m_pRight, nodeI + 1, (left + right) / 2, right);

	//注意
	//左孩子的打印范围是：left ~  (left+right)/2，
	// 以4行的数，0~14为例   0 ~ (0+14)/2 ==  0 ~ 7,
	//右孩子的打印范围是： (left+right+1)/2 ~ right
	// 以4行的数，0~14为例   (0+14)/2 ~ 14  ==  7 ~ 14,
}

vector<vector<string>> printTree(BinTreeNode_binP* root) {
	int row = getDepth(root);
	int col = pow(2, row) - 1;
	vector<vector<string>> print(row, vector<string>(col, ""));

	write(print, root, 0, 0, col);

	return print;
}

