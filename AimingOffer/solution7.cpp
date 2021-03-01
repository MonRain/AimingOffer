/* 
* 数据结构：树
* 二叉树
*	二叉树的遍历 递归与循环  三种遍历的6中方法
*	二叉搜索树 
*	堆 最大堆（根最大） 最小堆（根最小）——快速找最值 面试题40
*	红黑树 面试题40
*/

#include <stdio.h>
#include "head.h"

// 先实现二叉树的3种遍历的6种实现方法

int* preOrder(BinTreeNode* pHead) {

}
int* inOrder(BinTreeNode* pHead) {

}
int* postOrder(BinTreeNode* pHead) {

}

int* wideOrder(BinTreeNode* pHead) {

}
/* 面试题7：重建二叉树
* 输入前序遍历 中序遍历，重建二叉树。输出头节点
* 假设：前序 中序遍历中都不包含重复的数字
*/

BinTreeNode* reBuildBinTree(int forward[], int middle[]) {
	BinTreeNode* pHead = new BinTreeNode();
}