//======================================================
//	This is a test file of zhouwei's leetcode homework.
//	Author: baobao7766
//	Time:   2015/04/17
//======================================================

#include <vector>
#include <iostream>		// cout, cin
#include <string>
#include <map>
#include <assert.h>		// assert()

#include "SortList.h"

#define NULL 0

using namespace std;

int main ()
{
	/* definition */
	ListNode *pHead, *pRear, *pNew;
	int data[] = {3,2,1,4,1};
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

	/* processing */
	ListNode *L = pHead;
	Solution solution;
	L = solution.sortList(L);

	/* print */
	assert(L != NULL);
	while(L != NULL){
		cout << L->val << '\t';
		L = L->next;
	}
	cout << endl;

	system("pause");
	return 0;
}