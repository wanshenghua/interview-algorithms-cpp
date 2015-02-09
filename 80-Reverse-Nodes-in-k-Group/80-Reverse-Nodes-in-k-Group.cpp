/*Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 

key: 4 pointers, prev_end, end, beg, beg_next, plus one scan pointer(itr).
pitfalls: update head
*/

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head || k == 1){
            return head;
        }
        //get k nodes and reverse
        ListNode dHead(0);
        dHead.next = head;
        
        ListNode *itr = head;
        ListNode *end = itr;
        ListNode *beg = itr;
        ListNode *prev_end = &dHead;
        
        int len = 1;
        while(len <= k && itr){
            if(len == k){//[end, beg]
                if(end == head){//pitfall, update head 
                    head = beg;
                }
                prev_end->next = beg;//connect [end, beg] to the front part of list, i.e. previous item of end
                
                ListNode *beg_next = itr->next; //itr points to beg currently, will be reversed.     
                //reverse group
                ListNode *prev = itr->next;//key
                ListNode *cur = end;
                while(cur != beg_next){
                    ListNode *tmp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = tmp;
                }
                prev_end = end;
                
                //reset
                len = 1;
                if(beg_next == NULL){//pitfall: check NULL, i.e. out of nodes
                    break;
                }
                end = beg_next;//pitfall: move beg, end, itr to a new start
                beg = beg_next;
                itr = beg_next;
                continue;
            }
            itr = itr->next;
            beg = itr;
            ++len;
        }
        return head;
    }
};