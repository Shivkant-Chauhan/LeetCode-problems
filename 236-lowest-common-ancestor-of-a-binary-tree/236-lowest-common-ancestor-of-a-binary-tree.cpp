/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)    return root;
        if(root == p || root == q){
            return root;
        }
        
        TreeNode* a = LCA(root->left, p, q);
        TreeNode* b = LCA(root->right, p, q);
        
        if(a!=NULL && b!=NULL){
            return root;
        } else if(a!=NULL){
            return a;
        } else if(b!=NULL){
            return b;
        } else{
            return NULL;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }
};