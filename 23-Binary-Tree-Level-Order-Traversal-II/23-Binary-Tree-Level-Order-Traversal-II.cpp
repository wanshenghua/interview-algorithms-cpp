/*Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]


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
#include <vector>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
	int height(TreeNode *root){
		if(!root){
			return 0;
		}
		return 1 + max(height(root->left), height(root->right));
	}
	
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		int h = height(root);
		vector<vector<int> > res(h); //result vector
		
        queue<pair<TreeNode*,int> > q; //traversal queue, level
         
		 if(!root){
			return res;
		 }
		 
		 q.push(make_pair(root, 1));

		 while(!q.empty()){
			pair<TreeNode*, int> p_node = q.front();
			q.pop();
			
			int level = p_node.second - 1;
			res[h - 1 - level].push_back(p_node.first->val);
			if(p_node.first->left){
				q.push(make_pair(p_node.first->left, p_node.second + 1));
			}
			if(p_node.first->right){
				q.push(make_pair(p_node.first->right, p_node.second + 1));
			}			
		}
        return res;
    }
};