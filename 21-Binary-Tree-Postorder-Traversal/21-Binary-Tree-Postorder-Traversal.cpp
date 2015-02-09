/* Binary Tree Post-order Traversal
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

 
*/
#inclue <vector>
using namespace std;
class Solution_recursive {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
		postorderTraversal(root, res);
		return res;
    }
	
	void postorderTraversal(TreeNode *root, vector<int> &res){
		if(!root){
			return;
		}
		postorderTraversal(root->left, res);
		postorderTraversal(root->right, res);
		res.push_back(root->val);
	}
};
#include<stack>
class Solution_iterative {
/*key: 1.backtrack if cur is NULL
   o                 o
  / \       OR      / \
 O   NULL          O   o 
       2. when visit root, memorize it as last visited
*/
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
		if(!root){
			return res;
		}
		stack<TreeNode *> stk;
		TreeNode* cur = root;
		TreeNode* last_node_visited = NULL;
		while(!stk.empty() || cur){//left subtree, then root, then right subtree
			if(cur){//first left subtree, go deeper
				stk.push(cur);
				cur = cur->left;
			}else{//backwards, go right
				TreeNode *peek_node = stk.top();//when move backwards, there are two cases, the last visited is left child or right child.
				if(peek_node->right && last_node_visited != peek_node->right){		
					cur = peek_node->right;//go right if right exist and last visited is left subtree
				}else{//after left/right subtree, visit root
					stk.pop();
					res.push_back(peek_node->val);
					last_node_visited = peek_node;//key:
				}
			}
		}
		return res;
    }
};

