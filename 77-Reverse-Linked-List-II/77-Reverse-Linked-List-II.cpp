/* Reverse Linked List II

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list. 

key: reuse the pointer, to move to m, and to move n.
when moving from m to n, move and reverse.

pitfalls: when i==n, itr moves out of n, i.e. itr moves to n+1
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head || !head->next){
            return head;
        }
        if(m == n){
            return head;
        }
        //list is divided into list0, list1, list2, reverse list1 and insert it back between list0 and 2
        //find m-th and m-1-th;
        ListNode *prev = NULL;
        ListNode *itr = head;
        int i = 1;
        while(i < m && itr){
            prev = itr;
            itr = itr->next;
            i++;
        }
        ListNode *end_l0 = prev;
        ListNode *end_l1 = itr;
        //reverse between m and n
        prev = NULL;
        while(i <= n && itr){//initially, i=m, if m=n, do nothing
            ListNode *tmp = itr->next;
            itr->next = prev;
            prev = itr;
            itr = tmp;
            i++;
        }
        ListNode *beg_l1 = prev;// afer reversion, end_l1->...->beg_l1
        ListNode *beg_l2 = itr;//key: the final position of itr     
        
        //insert back
        if(end_l0 == NULL){
            head = beg_l1;
        }else{
            end_l0->next = beg_l1;
        }
        
        if(end_l1)
            end_l1->next = beg_l2;
            
        return head;
    }
};