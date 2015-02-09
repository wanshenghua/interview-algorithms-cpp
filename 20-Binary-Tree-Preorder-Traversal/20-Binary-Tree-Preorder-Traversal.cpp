/* Binary Tree Pre-order Traversal
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
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		preorderTraversal(root, res);
		return res;
    }
	void preorderTraversal(TreeNode *root, vector<int> &res){
		if(!root){
			return;
		}
		res.push_back(root->val);
		preorderTraversal(root->left, res);
		preorderTraversal(root->right, res);	
	}
};

#include <stack>
#include <vector>
class Solution_iterative{
/* preorder is just like DFS but keep order of left and right child.
*/
public:
    vector<int> preorderTraversal(TreeNode *root, vector<int> &res) {
		vector<int> res;
		if(!root){
			return res;
		}
		
		stack<TreeNode *> stk;
		stk.push(root);//restriction: no NULL point in this stack.
		while(!stk.empty()){
			TreeNode *cur = stk.top();
			stk.pop();
			res.push_back(cur->val); //visit root of subtrees first
			
			if(cur->right){//right push stack first since it is visited last
				stk.push(cur->right);
			}
			if(cur->left){
				stk.push(cur->left);
			}
		}
		return res;
	}
};

