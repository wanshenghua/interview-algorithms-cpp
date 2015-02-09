#include <iostream>
using namespace std;
/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int m = listSize(l1);
		int n = listSize(l2);
		
		ListNode *longer = (m > n) ? l1 : l2;
		ListNode *shorter = (longer == l1) ? l2 : l1;
		ListNode *save_head = longer;
		int carry = 0;
		while(longer || shorter){
			int p = (longer) ? longer->val : 0;
			int q = (shorter) ? shorter->val : 0;
			int tmp = p + q + carry;
			int digit = tmp % 10;
			carry = tmp / 10;
			longer->val = digit;
			longer = longer->next;
			if(shorter){
				shorter = shorter->next;
			}
		}
		if(carry){
			ListNode *last = listTail(save_head);
			ListNode *new_node = new ListNode(1);
			last->next = new_node;
		}
		return save_head;
    }
	
	int listSize(ListNode *node){
		int count = 0;
		while(node){
			count++;		
			node = node->next;
		}
		return count;
	}
	
	ListNode *listTail(ListNode *node){
		ListNode *last = NULL;
		while(node){
			last = node;
			node = node->next;
		}
		return last;
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
	ListNode *l1 = NULL, *l2 = NULL;
	Solution sol;
/* 	sol.push(l1, 5);
	sol.push(l1, 4);
	sol.push(l1, 2);

	sol.push(l2, 4);
	sol.push(l2, 6);
	sol.push(l2, 5); */
	
	//sol.push(l1, 8);
	sol.push(l1, 0);
	
	sol.push(l2, 1);
	
	sol.printList(l1);
	sol.printList(l2);
	
	ListNode *res = sol.addTwoNumbers(l1, l2);
	sol.printList(res);	
	sol.destroy(l1);
	sol.destroy(l2);	
	return 0;
}