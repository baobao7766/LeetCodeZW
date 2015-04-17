//======================================================
//Swap Nodes in Pairs
//	Author: baobao7766
//	Time:   2015/04/17
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
			head->next->next = head;
			head = head->next;
            head->next->next = swapPairs(p);
        }
        return head;
    }
};