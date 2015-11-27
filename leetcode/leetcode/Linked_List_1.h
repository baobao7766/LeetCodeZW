//===============================================================
//	Remove Duplicates from Sorted List 
//
//	Given a sorted linked list, delete all duplicates such that each element appear only once.
//	For example,
//		Given 1->1->2, return 1->2.
//		Given 1->1->2->3->3, return 1->2->3.
//================================================================

#define NULL 0

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL||head->next == NULL)
			return head;
		ListNode *p = head;
		while(p!=NULL && p->next!=NULL){
			if(p->val == p->next->val){
				p->next = p->next->next;
			}else{
				p = p->next;
			}
		}
		return head;
    }
};

//int main ()
//{
//	ListNode *pHead, *pRear, *pNew;
//	int data[] = {1,1};
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