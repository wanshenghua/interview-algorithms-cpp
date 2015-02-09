/* Binary Treee Maxium Path Sum
 Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 

Understanding:
key: what is the definition of the max path sum?

recursive definition:
maxPathSum(node) = max of 
	1. node 
	2. node + maxPathSum(node->left)  //expand path from left subtree
	3. node + maxPathSum(node->right) //eexpand path from right subtree
	4. node + maxPathSum(node->left) + maxPathSum(node->right) //expand path from both
*/

#include <numeric>
using namespace std;
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int max = std::numeric_limits<int>::min();
		DFS(root, max);
		return max;
    }
	//return value is the max path sum from root to the leaves, i.e. can not cross root 
	int DFS(TreeNode *root, int &max){
		if(!root){
			return 0; //contribution to the path that contains this node
		}
		int l = DFS(root->left, max);
		int r = DFS(root->right, max);
		
		int m = root->val; //if path from left and right are negatively weighted, use current node
		m = (l > 0) ? m + l : m;//contribute node to path from left sub-tree
		m = (r > 0) ? m + r : m;
		
		max = (m > max) ? m : max;
		
		return std::max(l, r) > 0 ? std::max(l, r) + root->val : root->val; //lengthen the path or start a new path		
	}
};