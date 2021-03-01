
#include <iostream>
#include <stdio.h>

#include "head.h"


using namespace std;
int main(int args, char* argv) {
	ListNode* pHead = new ListNode();
	int i = 0;
	int value;
	while (i<5) {
		addToTail(&pHead, ++i);
	}

	printList(&pHead);

	findDelNode(&pHead, 1);
	findDelNode(&pHead, 2);
	printList(&pHead);

	return 0;
}

