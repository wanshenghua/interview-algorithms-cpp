/*Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 

key: keep two pointer, prev and cur, delete duplicate nodes.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next){//input of size 0 and 1
            return head;
        }
        
        ListNode *prev = head;
        ListNode *cur = head->next;
        
        while(cur){
            if(cur->val == prev->val){//remove duplicate, delete, move pointers
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};