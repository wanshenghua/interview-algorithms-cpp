/* Reorder List
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 

key: 
1. two slow/fast pointers, find middle point of the list, i.e. k of 2k or 2k+1,
2. get two lists [1, ...,k] [k+1,...2k/2k+1], set tail to NULL
3. reverse [k+1,...,2k/2k+1]
4. merge the two lists interleavingly

*/

class Solution {
public:
    void reorderList(ListNode *head) {
		//find k(k>=1) of 2k, or 2k+1
		if(!head || !head->next || !head->next->next){
			return;
		}
		
		ListNode *slow = head;
		ListNode *fast = head;
		while(fast->next){
			fast = fast->next;
			if(fast->next){
				fast = fast->next;
			}else{
				break;
			}
			slow = slow->next;
		}
		ListNode *beg_l2 = fast;
		ListNode *end_l2 = slow->next;
		slow->next = NULL;//key: set end of sublist 1 to NULL
		//reverse sublist2, [end_l2, ..., beg_l2]
		ListNode *prev = NULL;
		ListNode *itr = end_l2;
		while(itr){
			ListNode *tmp = itr->next;
			itr->next = prev;
			prev = itr;
			itr = tmp;
		}
		//interleave sublist1 and sublist2
		itr = head;
		while(itr->next){
			ListNode *tmp = itr->next;
			itr->next = beg_l2;
			itr = tmp;
			ListNode *tmp2 = beg_l2->next;
			beg_l2->next = tmp;
			beg_l2 = tmp2;
		}
		//size of subtlist2 might be longer than that of sublist1 by 1
		itr->next = beg_l2;
	}
};