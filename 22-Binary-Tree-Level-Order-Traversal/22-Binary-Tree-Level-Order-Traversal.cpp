/* Binary-Tree-Level-Order-Traversal
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

*/
#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
//recursion, time complexity worst O(n^2)
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
		int h = height(root);
		vector<vector<int> > res(h);
		for(int i = 1; i <= h; i++){
			getGivenLevel(root, i, res[i - 1]);
		}
		return res;
    }
	int height(TreeNode *root){
		if(!root){
			return 0;
		}
		return 1 + max(height(root->left), height(root->right));
	}
	
	void getGivenLevel(TreeNode *root, int level, vector<int> &cur_level){
		//print all the items on the same level
		if(!root){
			return;
		}
		if(level == 1){
			cur_level.push_back(root->val);
		}else if(level > 1){
			getGivenLevel(root->left, level - 1, cur_level); //carry level - 1
			getGivenLevel(root->right, level - 1, cur_level);
		}
	}
}; 

//iteration: idea = BFS, time complexity O(N)
#include <queue>
#include <vector>
#include <utility>
class Solution {
public:
	int height(TreeNode *root){
		if(!root){
			return 0;
		}
		return 1 + max(height(root->left), height(root->right));
	}
	
    vector<vector<int> > levelOrder(TreeNode *root) {
		int h = height(root);
		vector<vector<int> > res(h); //result vector
		
        queue<pair<TreeNode*,int> > q; //traversal queue
         
		 if(!root){
			return res;
		 }
		 
		 q.push(make_pair(root, 1));

		 while(!q.empty()){
			pair<TreeNode*, int> p_node = q.front();
			q.pop();
			
			res[p_node.second - 1].push_back(p_node.first->val);
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


int main()
{
	TreeNode node(1);
	Solution sol;
	vector<vector<int> > res = sol.levelOrder(&node);
	cout << res.size() << endl;
	cout << res[0].size() << endl;
	return 0;
}