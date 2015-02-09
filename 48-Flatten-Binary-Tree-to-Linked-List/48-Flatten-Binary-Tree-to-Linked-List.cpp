/* Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

click to show hints.
Hints:

If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

key: return the last visited node as the root for the right sub-tree

*/

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
    void flatten(TreeNode *root) {
        flattenTree(root);    
    }
    
    TreeNode *flattenTree(TreeNode *node){
        if(!node){
            return node;
        }
        TreeNode *rtree = node->right;
        if(node->left){
            node->right = node->left;
            node->left = NULL;
            node = flattenTree(node->right);
        }
        if(rtree){
            node->right = rtree;
            node = flattenTree(node->right);
        }
        return node; //key: return the last node visited
    }
};