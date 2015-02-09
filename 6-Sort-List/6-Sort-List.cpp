#include <iostream>
using namespace std;


 
 struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *sortList(ListNode *head) {
		if(!head || !head->next){
			return head;
		}
		ListNode *left=NULL, *right=NULL;
		split(head, left, right);
		sortList(left);
		sortList(right);
		head = merge(left, right);
		
		return head;
    }
	
	void split(ListNode *head, ListNode* &left, ListNode* &right){
		ListNode *fast=NULL, *slow=NULL;
		if(!head || !head->next){
			left = head;
			right = NULL;
		}else{
			slow = head;
			fast = head->next;
			while(fast){
				fast = fast->next;
				if(fast){
					slow = slow->next;
					fast = fast->next;
				}
			}
			left = head;
			right = slow->next;
			slow->next = NULL; //split to two lists
		}
	}
	
	ListNode* merge(ListNode* left, ListNode* right){
		ListNode *result = NULL;
		if(!left){
			return right;
		}else if(!right){
			return left;
		}
		if(left->val <= right->val){
			result = left;
			result->next = merge(left->next, right);
		}else{
			result = right;
			result->next = merge(left, right->next);
		}
		return result;
	}

	void printList(ListNode *head){
		while(head){
			cout << head->val << " " ;
			head = head->next;
		}
		cout << endl;
	}
	
	void push(ListNode* &head, int new_data){
		ListNode *new_node = new ListNode(new_data);
		new_node->next = head;
		head = new_node;
	}
	
	void destroy(ListNode *head){
		while(head){
			ListNode *new_head = head->next;
			delete head;
			head = new_head;
		}
	}
	
};

int main()
{
	ListNode *head = NULL;
	Solution sol;
	sol.push(head, 2);
	sol.push(head, 3);
	sol.push(head, 20);
	sol.push(head, 5);
	sol.push(head, 10);
	sol.push(head, 15);	
	
	sol.printList(head);
	
	sol.sortList(head);
	
	sol.printList(head);
		
	return 0;
}