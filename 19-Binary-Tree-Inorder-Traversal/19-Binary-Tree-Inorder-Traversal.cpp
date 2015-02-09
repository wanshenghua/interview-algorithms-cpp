/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3

return [1,3,2]. 
*/
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution_recursive{
public:
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		inorderTraversal(root, res);
		return res;
    }
	void inorderTraversal(TreeNode *root, vector<int> &res){
		if(!root){
			return;
		}
		inorderTraversal(root->left, res);
		res.push_back(root->val);
		inorderTraversal(root->right, res);	
	}
};

//use a stack to backtrack the root
#include <stack>
#include <vector>
using namespace std;
class Solution_iterative{
/*key: backtrack procedure
*/
public:
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode *> stk;
		TreeNode *cur = root;

		while(!stk.empty() || cur){
			if(cur){//first left subtree, go deeper
				stk.push(cur);
				cur = cur->left; //visit left subtree first and use stack to save root.
			}else{//cur is NULL, i.e. meet a leaf, move backwards
				cur = stk.top();
				stk.pop();
				res.push_back(cur->val); //visit root ;
				
				cur = cur->right; //visit right subtree
			}
		}		
		return res;
	}
};



