/*

Remove Duplicates from Sorted List II
Total Accepted: 8198 Total Submissions: 33318

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 

key: keep 3 pointers, prev_prev, prev, cur and a status dup to record if duplicates are seen.
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
        if(!head || !head->next){//boundary case: size of 0 and 1
            return head;
        }
        ListNode *dHead = new ListNode(0);
        dHead->next = head;
        ListNode *prev_prev = dHead;
        ListNode *prev = head;
        ListNode *cur = head->next;
        bool dup = false;
        while(cur){
            if(prev && cur->val == prev->val){//duplicate
                prev->next = cur->next;
                delete cur;
                cur = prev->next; //remove duplicate, move cur forward, can be NULL, i.e. end
                dup = true;
            }else{//when a new value is found, remove prev if duplicated.
                if(dup){//remove prev
                    prev_prev->next = prev->next;
                    delete prev;
                    prev = NULL;
                    dup = false;
                }else{//no duplicate
                   prev_prev = prev; 
                }
                prev = cur;
                cur = cur->next;
            }
        }
        if(dup){//key: the last item still needs handling
            prev_prev->next = prev->next;
            delete prev;
            prev = NULL;
        }
        
        ListNode *save = dHead->next;
        delete dHead;
        return save;
    }
};