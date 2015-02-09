/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        bool isSame = true;
		DFS(p, q, isSame);
		return isSame;
    }
	
	void DFS(TreeNode *p, TreeNode *q, bool &isSame){
		if(!p){//key: check NULL
			if(q){
				isSame = false;
			}
			return;
		}
		if(!q){//key: check NULL
			isSame = false;	
			return;
		}
		if(p->val != q->val){
			isSame = false;
			return;
		}
		DFS(p->left, q->left, isSame);
		DFS(p->right, q->right, isSame);
	}
};