/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

Ideas:
use Level Order traversal which is based on BFS.
reverse the rows of the vector alternatively.
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
	
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
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
			
			int ind = p_node.second - 1;
			res[ind].push_back(p_node.first->val);
			if(p_node.first->left){
				q.push(make_pair(p_node.first->left, p_node.second + 1));
			}
			if(p_node.first->right){
				q.push(make_pair(p_node.first->right, p_node.second + 1));
			}			
		}
		//make zigzag order
		for(int i = 0; i < h; i++){
		    if( i%2 == 1){ //odd rows
		        reverse(res[i].begin(), res[i].end());
		    }
		}
        return res;
    }
};