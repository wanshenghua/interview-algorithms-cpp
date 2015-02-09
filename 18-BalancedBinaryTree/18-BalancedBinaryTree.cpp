/* Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

understanding:
Definition of height-balanced binary tree:
1. left and right subtrees are balanced.
2. the height difference of left and right subtrees is up to 1.

find the max/min depth and check the difference.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution_1st {
	/*	Time complexity: O(n^2)
		worst case: skewed tree, f(n) = f(n-1) + O(n) ~ O(n^2)
		best case: f(n) = 2 f(n/2) + O(logn) = O(n)
	*/
public:
    bool isBalanced(TreeNode *root) {
		//use the definition
		if(!root){
			return true;
		}
		
		int lh = height(root->left); //worst case O(n), average O(log n)
		int rh = height(root->right);
		
		bool lb = isBalanced(root->left);
		bool rb = isBalanced(root->right);
		
		if(abs(lh - rh) <= 1 && lb && rb){
			return true;
		}
		return false;
    }
	int height(TreeNode *root){
	/*recursive definition of tree height: 1 + max(left_subtree_height, right_subtree_height)
	*/	
		if(!root){
			return 0;
		}
		return 1 + max(height(root->left), height(root->right));
	}

};
 
class Solution_2n{
//calculate the distance with the recursion
	/*	Time complexity: O(n)
		worst case: skewed tree, f(n) = f(n-1) + O(1) ~ O(n)
		best case: f(n) = 2 f(n/2) + O(1) = O(n)
	*/
public:
    bool isBalanced(TreeNode *root) {
		int height = 0;
		return isBalanced(root, height);
    }
    bool isBalanced(TreeNode *root, int &height) {
		if(!root){
			height = 0;
			return true;
		}
		int lh = 0, rh = 0;
		bool lb = isBalanced(root->left, lh);
		bool rb = isBalanced(root->right, rh);
		//recursive definition of tree height: 1 + max(left_subtree_height, right_subtree_height)
		height = max(lh, rh) + 1;
		if(abs(lh - rh) <= 1 && lb && rb){
			return true;
		}
		return false;
    }
};