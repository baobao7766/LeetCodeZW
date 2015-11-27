//==========================================================
//Sort List
//Sort a linked list in O(n log n) time using constant space complexity.
//==========================================================

/* 符合要求的复杂度要求就是归并排序和快速排序了，
	只不过这里将排序算法用在了链表上了，反而符合了空间复杂度的要求 */

#define NULL 0

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return head;
		return mergeSort(head);
    }// end sortList

	ListNode *mergeSort(ListNode *head){
		if(head==NULL||head->next==NULL)
			return head;
		/* divide */
		ListNode *fast = head;
		ListNode *slow = head;
		while(fast->next!=NULL && fast->next->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *rhead = slow->next;
		slow->next = NULL;
		head = sortList(head);
		rhead = sortList(rhead);
		return merge(head, rhead);
	}// end mergeSort

	ListNode *merge(ListNode *lh, ListNode *rh){
		if(lh==NULL) return rh;
		if(rh==NULL) return lh;
		ListNode *newHead = new ListNode(0);
		ListNode *last = newHead;

		while(lh!=NULL && rh!=NULL){
			if(lh->val < rh->val){
				last->next = lh;
				lh = lh->next;
			}else{
				last->next = rh;
				rh = rh->next;
			}// end if
			last = last->next;
		}// end while

		if(lh==NULL){
			last->next = rh;
		}else if(rh==NULL){
			last->next = lh;
		}// end if

		return newHead->next;
	}// end merge
};

/////////////////////////////////////////////////

//int main ()
//{
//	ListNode *pHead, *pRear, *pNew;
//	int data[] = {3,2,1,4,1};
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
//	L = solution.sortList(L);
//	assert(L != NULL);
//	while(L != NULL){
//		cout << L->val << '\t';
//		L = L->next;
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}