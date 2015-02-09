/*Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
		return buildTree(num, 0, num.size() - 1);
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