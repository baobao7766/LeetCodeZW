//==================================================
//Remove Duplicates from Sorted List II 
//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3.
//======================================================
#include <iostream>
#define NULL 0
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/* 主要思想：迭代使用 deleteDuplicates() */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode * p = head;
        while(p->next!=NULL && p->val == p->next->val){
            p=p->next;
        }
    
        if(p!=head){
            while(head!=p->next)
                head = head->next;
            return deleteDuplicates(p->next);
        }
    
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
//////////////////////////////////////////////////////
//int main ()
//{
//	ListNode *pHead, *pRear, *pNew;
//	int data[] = {1,1,2,3,3,3,4,5,5,5,5};
//	int index = 0;
//	while(index!=int(sizeof(data)/sizeof(int))){
//		pNew = new ListNode(data[index]);
//		if(index == 0)
//			pRear = pHead = pNew;
//		else
//			pRear->next = pNew;
//		pNew->next = NULL;
//		pRear = pNew;
//		++index;
//	}
//	/* print */
//	ListNode *L = pHead;
//	Solution solution;
//	L = solution.deleteDuplicates(L);
//	assert(L != NULL);
//	while(L != NULL){
//		cout << L->val << '\t';
//		L = L->next;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
