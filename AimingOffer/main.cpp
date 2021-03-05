
#include <iostream>
#include <stdio.h>
#include <vector>
#include "head.h"


using namespace std;
int main(int args, char* argv) {

	int preorder[8] = { 1,2,4,7,3,5,6,8 };
	int inorder[8] = { 4,7,2,1,5,3,8,6 };

	BinTreeNode* BinTree = reBuildBinTree(preorder, inorder, 8);
	
	vector<vector<string>> vec = printTree(BinTree);

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		for (unsigned int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

