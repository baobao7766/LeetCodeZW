//======================================================
//Swap Nodes in Pairs
//
//Given a linked list, swap every two adjacent nodes and return its head.
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
//======================================================
#define NULL 0

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return head;
        if(head->next!=NULL){
			ListNode *p = head->next->next;
			ListNode *q = head->next;
			head->next->next = head;
			head->next = swapPairs(p);
			head = q;

			/* 个人认为下面的做法更加简单明了，上面的有点累赘 */
			//ListNode *p = head->next->next;
			//head->next->next = head;
			//head = head->next;
			//head->next->next = swapPairs(p);
        }
        return head;
    }
};