/*Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 

key: two pointers + prev pointer for deletion
pitfalls: if to be deleted node is head.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        //two pointers + prev pointer
        ListNode *p = head;
        ListNode *q = head;
        
        int i = 1;
        while(i < n && q){//move q to n - 1 nodes after head, n>=1
            q = q->next;
            i++;
        }
        if(i < n){// n is larger the size of list
            return head;
        }
        //long enough
        ListNode *prev = NULL;
        while(q->next){//q stops at the last item, not NULL
            prev = p;//record p's prev
            q = q->next;
            p = p->next;
        }
        //will delelte p
        if(p != head){
            prev->next = p->next;
            delete p;
        }else{//p is head
            head = head->next;
            delete p;
        }
        return head;
    }
};