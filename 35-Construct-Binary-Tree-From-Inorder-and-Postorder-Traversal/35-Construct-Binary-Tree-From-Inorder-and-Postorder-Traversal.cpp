/*

Construct Binary Tree from Inorder and Postorder Traversal
Total Accepted: 5656 Total Submissions: 22249

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 

Ideas:
     A
   /    \
  B     C
 / \   / \
D   E F   G

Inorder:     DBEAFCG
Postorder:   DEBFGCA

The last item of post-order is always a root, whose left subtree can be find with the help of in-order
e.g. (DBE) A (FCG)
     left root right
left length = n1
the separation of post-order is (DEB) (FGC) A
								left   right root
Time complexity: worse case O(n^2) from a left-skewed tree
*/

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
	
	TreeNode *buildTree(vector<int> &in, int iBeg, int iEnd,
						vector<int> &post, int pBeg, int pEnd){
		if(iBeg > iEnd){
			return NULL;
		}
		//always know current root label as the last element in post[]
		int rootLabel = post[pEnd];
		
		//search for root node in in[] to separate left/right subtrees
		int rootIndex = -1;
		for(int i = iBeg; i <= iEnd; i++){
			if(in[i] == rootLabel){
				rootIndex = i;
				break; //separation point
			}
		}
		int len = rootIndex - iBeg;
		TreeNode *root = new TreeNode(rootLabel);
		root->left = buildTree(in, iBeg, rootIndex - 1, post, pBeg, pBeg, pBeg + len - 1);//rootIndex is root
		root->right = buildTree(int, rootIndex + 1, iEnd, post, pBeg + len, pEnd - 1);//pEnd is root
		return root;
	}
};