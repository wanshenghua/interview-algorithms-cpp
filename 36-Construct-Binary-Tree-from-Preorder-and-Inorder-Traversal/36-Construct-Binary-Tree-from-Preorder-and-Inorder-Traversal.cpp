/* Construct Binary Tree from Preorder and Inorder Traversal

Total Accepted: 5848 Total Submissions: 23223

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
          return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
	TreeNode *buildTree(vector<int> &pre, int pBeg, int pEnd, vector<int> &in, int iBeg, int iEnd){
		if(iBeg > iEnd){
			return NULL;
		}
		
		int rootLabel = pre[pBeg];
		int rootIndex = -1; //search in in-order
		for(int i = iBeg; i <= iEnd; i++){
			if(in[i] == rootLabel){
				rootIndex = i;
				break;
			}
		}
		TreeNode *root = new TreeNode(rootLabel);
		int len = rootIndex - iBeg;
		root->left = buildTree(pre, pBeg + 1, pBeg + len, in, iBeg, rootIndex - 1);
		root->right = buildTree(pre, pBeg + len + 1, pEnd, in, rootIndex + 1, iEnd);
		return root;
	}
};