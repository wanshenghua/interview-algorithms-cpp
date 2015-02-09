/*Validate Binary Search Tree 
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    bool isValidBST(TreeNode *root) {
        int max_tree = 0, min_tree = 0;
        return validBST(root, max_tree, min_tree);
    }
    
    bool validBST(TreeNode *node, int &max_tree, int &min_tree){
        if(!node){
            return true;
        }
        
        
        int max_left = 0, min_left = 0;
        if(!validBST(node->left, max_left, min_left)){
            return false;
        }
        
        int max_right = 0, min_right = 0;
        if(!validBST(node->right, max_right, min_right)){
            return false;
        }
    
        if(node->left && node->val <= max_left){//key: ignore if no left subtree
            return false;
        }
        
        if(node->right && node->val >= min_right){//key: ignore if no right subtree
            return false;
        }
        //now we know it is BST; let's find the max/min
        if(node->left){
            min_tree = min_left;
        }else{
            min_tree = node->val;
        }
        
        if(node->right){
            max_tree = max_right;   
        }else{
            max_tree = node->val;
        }
        
        return true;
    }
};