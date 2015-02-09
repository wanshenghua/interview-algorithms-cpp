/* Linked List Cycle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space? 

key: use fast/slow pointers to detect a cycle.
where is the cycle begins?
let x be the steps from head to where the cycle begins, y is the steps since the cycle begins before they met, C is the length of the cycle

2t = n * C + x + y  -> t = (m-n)*C -> (n-2*m)*C = x + y
t = m * C + x + y   ->

(n-2*m)*C = x + y
this means when the slow pointer moves x steps, it will arrive where the cyecle begins.
therefore, use a 3rd slow pointer to move from head together with slow pointer, the place where it met slow pointer is where the cycle begins.
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
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow && fast){//make sure two pointer are valid
            slow = slow->next;
            fast = fast->next;
            if(fast){//check validness
                fast = fast->next;
            }
            if(slow == fast){
                break;
            }
        }
        if(!fast){
            return NULL;
        }
        //a cycle exists
        ListNode *itr = head;
        while(itr != slow){
            itr = itr->next;
            slow = slow->next;
        }
        return itr;
    }
};