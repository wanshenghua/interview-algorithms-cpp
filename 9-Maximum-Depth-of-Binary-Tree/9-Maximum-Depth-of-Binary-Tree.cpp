/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
 #include <stack>
 
class Solution {
public:
    int maxDepth(TreeNode *root) {
        int max_depth = 0;
		DFS(root, 0, max_depth);
		return max_depth;
    }
	
	void DFS(TreeNode *n, int depth, int &max_depth){
		if(!n){
			return;
		}
		int cur_depth = depth + 1;
		max_depth = (cur_depth > max_depth) ? cur_depth : max_depth;
		DFS(n->left, cur_depth, max_depth);
		DFS(n->right, cur_depth, max_depth);
	}
};