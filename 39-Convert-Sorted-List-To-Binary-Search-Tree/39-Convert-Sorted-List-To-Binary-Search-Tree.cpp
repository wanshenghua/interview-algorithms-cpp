/*Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
		vector<ListNode*> nums;
		TreeNode *node = head;
		while(node){
			nums.push_back(node->val);
			node = node->next;
		}
		
		return buildTree(idx2node, 0, nums.size() - 1);
    }
	
	TreeNode *buildTree(vector<int> &num, int beg, int end){
		if(beg > end){
			return NULL;
		}
		int rootIndex = (int) ((beg + end) / 2);
		int rootLabel = num[rootIndex];
		TreeNode *root = new TreeNode(rootLabel);
		root->left = buildTree(num, beg, rootIndex - 1);
		root->right = buildTree(num, rootIndex + 1, end);
		return root;
	}
};