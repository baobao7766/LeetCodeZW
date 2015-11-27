//==========================================================
//	Rotate List
//	Given a list, rotate the list to the right by k places, 
//	where k is non-negative.
//	For example:
//	Given 1->2->3->4->5->NULL and k = 2,
//	return 4->5->1->2->3->NULL.
//==========================================================
#define NULL 0

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
			return head;

		ListNode *p = head;
		int length = 1;

		while(p->next != NULL){
			p = p->next;
			++length;
		}//end while

		int new_k = k % length;
		p->next = head;
		for(int i=0; i!=length-new_k-1; ++i){
			head = head->next;
		}//end for
		ListNode *q = head;
		head = head->next;
		q->next = NULL;
		return head;
    }//end rotateRight()
};

//int main ()
//{
//	/* definition */
//	ListNode *pHead, *pRear, *pNew;
//	int data[] = {1,2,3,4,5,6,7};
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
//
//	/* processing */
//	ListNode *L = pHead;
//	int k = 20000000000;
//	Solution solution;
//	L = solution.rotateRight(L, k);
//
//	/* print */
//	assert(L != NULL);
//	while(L != NULL){
//		cout << L->val << '\t';
//		L = L->next;
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}