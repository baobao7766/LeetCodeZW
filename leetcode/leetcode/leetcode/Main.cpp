//======================================================
//	This is a test file of zhouwei's leetcode homework.
//	Author: baobao7766
//	Time:   2015/04/17
//======================================================

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <assert.h>

#include "SwapNodesInPairs.h"

#define NULL 0

using namespace std;

int main ()
{
	ListNode *pHead, *pRear, *pNew;
	int data[] = {1,2,3,4};
	int index = 0;
	while(index!=int(sizeof(data)/sizeof(int))){
		pNew = new ListNode(data[index]);
		if(index == 0)
			pRear = pHead = pNew;
		else
			pRear->next = pNew;
		pNew->next = NULL;
		pRear = pNew;
		++index;
	}
	/* print */
	ListNode *L = pHead;
	Solution solution;
	L = solution.swapPairs(L);
	assert(L != NULL);
	while(L != NULL){
		cout << L->val << '\t';
		L = L->next;
	}
	cout << endl;
	system("pause");
	return 0;
}





