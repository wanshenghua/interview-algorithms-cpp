/*Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null. 
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *copy_head = copyRedundentRamdomList(head);
		fixRandomPointer(head);
		separateLists(head);
		return copy_head;
    }
	//make a copy of a node and put it after the old one
	RandomListNode *copyRedundentRandomList(RandomListNode *head){
		RandomListNode *node = head;
		whlie(node){
			//copy a node
			RandomListNode *copy_node = new RandomListNode(node->label);
			copy_node->next = node->next;
			copy_node->random = node->random;
			//put new node after old node
			node->next = copy;
			//move to next old node
			node = copy->next;
			//node = node->next;
		}
		RandomListNode *copy_head = head->next;
		return copy_head;
	}
	//fix the random pointer of the copied nodes
	void fixRandomPointer(RandomListNode *head){
		RandomListNode *node = head;
		whlie(node){	
			copy_node = node->next;
			copy_node->random = node->random->next;
			node = node->next->next; //guaranteed validness due to cpy
		}
	}
	void separateLists(RandomListNode *head){
		RandomListNode *node = head;
		while(node){
			RandomListNode *copy_node = node->next;
			copy_node->next = copy_node->next->next;
			node = node->next->next;
		}
	}
};