/* Insertion Sort List
Sort a linked list using insertion sort.
idea: do not swap, but only insert the node to the target position.
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
    ListNode *insertionSortList(ListNode *head) {//using array as buffer
        vector<ListNode*> history;
        history.push_back(head);
        if(head){
            for(ListNode *cur = head->next; cur != NULL; cur = cur->next){
                history.push_back(cur);
                int j = history.size() - 1;
                while(j > 0 && history[j]->val < history[j - 1]->val){
                    swap(history[j]->val, history[j - 1]->val);
                    j--;
                }
            }
        }
        return head;
    }
    
    void insertionSort(vector<int> &num){
        int n = num.size();
        for(int i = 1; i < n; i++){
            int j = i;
            while(j > 0 && num[j] < num[j - 1]){
                swap(num[j], num[j - 1]);
                j--;
            }
        }
    }
    
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};

string reverse(const string &s)
{
	string t;
	int n = s.size();
	
	string word;
	for(int i = 0; i < n; i++){
		if(s[i] == ' '){
			t = string(" ") + word + t;
			word.clear();
		}else{
			word = word + s[i];
		}
	}
	if(!word.empty()){
		t = word + t;
	}

	return t;
}